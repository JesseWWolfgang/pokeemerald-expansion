CasteliaCity_CafeSonata_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CasteliaCity_CafeSonata_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

CasteliaCity_CafeSonata_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_CAPTURED_VICTINI, CasteliaCity_CafeSonata_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	clearflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	return

CasteliaCity_CafeSonata_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	return


CafeSonata_Meloetta::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MELOETTA, CRY_MODE_ENCOUNTER
	msgbox CafeSonata_Meloetta_Text_0, MSGBOX_NPC
	delay 20
	waitmoncry
	setwildbattle SPECIES_MELOETTA, 40
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, CafeSonata_Meloetta_3
	case B_OUTCOME_RAN, CafeSonata_Meloetta_4
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject 2
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox CafeSonata_Meloetta_Text_2, MSGBOX_DEFAULT
CafeSonata_Meloetta_1:
	release
	end

CafeSonata_Meloetta_3:
	setflag FLAG_CAPTURED_VICTINI
	setflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	call Common_EventScript_RemoveStaticPokemon
	goto CafeSonata_Meloetta_1

CafeSonata_Meloetta_4:
	msgbox CafeSonata_Meloetta_Text_1, MSGBOX_DEFAULT
	goto CafeSonata_Meloetta_1


CafeSonata_Meloetta_Text_0:
	.string "Ta-ta-ta-tah!$"

CafeSonata_Meloetta_Text_1:
	.string "Meloetta is watching carefully.$"

CafeSonata_Meloetta_Text_2:
	.string "Meloetta fled behind the furniture...$"
