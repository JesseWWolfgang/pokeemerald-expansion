#include "global.h"
#include "battle.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "event_data.h"
#include "field_message_box.h"
#include "field_poison.h"
#include "fldeff_misc.h"
#include "frontier_util.h"
#include "party_menu.h"
#include "pokenav.h"
#include "script.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "trainer_hill.h"
#include "constants/field_poison.h"
#include "constants/form_change_types.h"
#include "constants/party_menu.h"

static u8 sWalkFainted = 0;
static bool8 sWalkFainted2[PARTY_SIZE];

static bool32 IsMonValidSpecies(struct Pokemon *pokemon)
{
    u16 species = GetMonData(pokemon, MON_DATA_SPECIES_OR_EGG);
    if (species == SPECIES_NONE || species == SPECIES_EGG)
        return FALSE;

    return TRUE;
}

static bool32 AllMonsFainted(void)
{
    int i;
    struct Pokemon *pokemon = gPlayerParty;

    for (i = 0; i < PARTY_SIZE; i++, pokemon++)
    {
        if (IsMonValidSpecies(pokemon) && GetMonData(pokemon, MON_DATA_HP) != 0)
            return FALSE;
    }
    return TRUE;
}

static void FaintFromFieldPoison(u8 partyIdx)
{
    struct Pokemon *pokemon = &gPlayerParty[partyIdx];
    u32 status = STATUS1_NONE;
    sWalkFainted &= ~(1 << partyIdx);
    sWalkFainted2[partyIdx] = FALSE;

#if OW_POISON_DAMAGE < GEN_4
    AdjustFriendship(pokemon, FRIENDSHIP_EVENT_FAINT_FIELD_PSN);
#endif
    SetMonData(pokemon, MON_DATA_STATUS, &status);
    GetMonData(pokemon, MON_DATA_NICKNAME, gStringVar1);
    StringGet_Nickname(gStringVar1);
}

static bool32 MonFaintedFromPoison(u8 partyIdx)
{
    struct Pokemon *pokemon = &gPlayerParty[partyIdx];
#if OW_POISON_DAMAGE < GEN_4
    //if (IsMonValidSpecies(pokemon) && GetMonData(pokemon, MON_DATA_HP) == 0 && GetAilmentFromStatus(GetMonData(pokemon, MON_DATA_STATUS)) == AILMENT_PSN)
    //if (IsMonValidSpecies(pokemon) && GetMonData(pokemon, MON_DATA_HP) == 0 && (sWalkFainted & (1 << partyIdx) > 0))
    if (IsMonValidSpecies(pokemon) && GetMonData(pokemon, MON_DATA_HP) == 0 && sWalkFainted2[partyIdx])
#else
    if (IsMonValidSpecies(pokemon) && GetMonData(pokemon, MON_DATA_HP) == 1 && GetAilmentFromStatus(GetMonData(pokemon, MON_DATA_STATUS)) == AILMENT_PSN)
#endif
        return TRUE;

    return FALSE;
}

#define tState    data[0]
#define tPartyIdx data[1]

static void Task_TryFieldPoisonWhiteOut(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (tState)
    {
    case 0:
        for (; tPartyIdx < PARTY_SIZE; tPartyIdx++)
        {
            if (MonFaintedFromPoison(tPartyIdx))
            {
                FaintFromFieldPoison(tPartyIdx);
                ShowFieldMessage(gText_PkmnFainted_FldPsn);
                tState++;
                return;
            }
        }
        tState = 2; // Finished checking party
        break;
    case 1:
        // Wait for "{mon} fainted" message, then return to party loop
        if (IsFieldMessageBoxHidden())
            tState--;
        break;
    case 2:
        if (AllMonsFainted())
        {
            // Battle facilities have their own white out script to handle the challenge loss
            if (InBattlePyramid() | InBattlePike() || InTrainerHillChallenge())
                gSpecialVar_Result = FLDPSN_FRONTIER_WHITEOUT;
            else
                gSpecialVar_Result = FLDPSN_WHITEOUT;
        }
        else
        {
            gSpecialVar_Result = FLDPSN_NO_WHITEOUT;
        }
        ScriptContext_Enable();
        DestroyTask(taskId);
        break;
    }
}

#undef tState
#undef tPartyIdx

void TryFieldPoisonWhiteOut(void)
{
    CreateTask(Task_TryFieldPoisonWhiteOut, 80);
    ScriptContext_Stop();
}

s32 DoPoisonFieldEffect(void)
{
    int i;
    u32 hp;
    struct Pokemon *pokemon = gPlayerParty;
    u32 numPoisoned = 0;
    u32 numFainted = 0;
    u32 numDmgd = 0;
    u32 numWalkDmgd = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        hp = GetMonData(pokemon, MON_DATA_HP);
        if (GetMonData(pokemon, MON_DATA_SANITY_HAS_SPECIES) && hp > 0)
        {
            // Apply on-step dmg
            if (hp > 0)
                hp--;
            numWalkDmgd++;


            // Apply regular poison
            if (GetAilmentFromStatus(GetMonData(pokemon, MON_DATA_STATUS)) == AILMENT_PSN)
            {
                if (hp > 0)
                    hp--;
                numPoisoned++;
            }

            // Apply damage
            #if OW_POISON_DAMAGE < GEN_4
                if (hp == 0)
                {
                    sWalkFainted |= (1 << i);
                    sWalkFainted2[i] = TRUE;
                    TryFormChange(i, B_SIDE_PLAYER, FORM_CHANGE_FAINT);
                    numFainted++;
                }
            #else
                if (hp == 1 || --hp == 1)
                    numFainted++;
            #endif
                SetMonData(pokemon, MON_DATA_HP, &hp);
        }
        pokemon++;
    }

    // Do screen flash effect
    if (numFainted != 0 || numPoisoned != 0)
        FldEffPoison_Start();

    if (numFainted != 0)
        return FLDPSN_FNT;

    if (numPoisoned != 0)
        return FLDPSN_PSN;

    if (numWalkDmgd != 0)
        return FLDPSN_WALK;

    return FLDPSN_NONE;
}
