LibertyGarden_2F_MapScripts::
	.byte 0


LibertyGarden_Victini::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VICTINI, CRY_MODE_ENCOUNTER
	msgbox LibertyGarden_Victini_Text_0, MSGBOX_NPC
	delay 20
	waitmoncry
	setwildbattle SPECIES_VICTINI, 15
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, LibertyGarden_Victini_3
	case B_OUTCOME_RAN, LibertyGarden_Victini_4
	fadescreenswapbuffers FADE_TO_BLACK
	hideobjectat 1, 0
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox LibertyGarden_Victini_Text_2, MSGBOX_DEFAULT
LibertyGarden_Victini_1:
	release
	end

LibertyGarden_Victini_3:
	setflag FLAG_DEFEATED_VICTINI
	call Common_EventScript_RemoveStaticPokemon
	goto LibertyGarden_Victini_1

LibertyGarden_Victini_4:
	msgbox LibertyGarden_Victini_Text_1, MSGBOX_DEFAULT
	goto LibertyGarden_Victini_1


LibertyGarden_Victini_Text_0:
	.string "Ta-ta-ta-tah!$"

LibertyGarden_Victini_Text_1:
	.string "Victini is watching carefully.$"

LibertyGarden_Victini_Text_2:
	.string "Victini fled behind the furniture...$"
