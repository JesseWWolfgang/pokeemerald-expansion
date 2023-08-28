LibertyGarden_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LibertyGarden_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

LibertyGarden_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_CAPTURED_VICTINI, LibertyGarden_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	clearflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	return

LibertyGarden_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	return


LibertyGarden_Victini::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VICTINI, CRY_MODE_ENCOUNTER
	msgbox LibertyGarden_Victini_Text_0, MSGBOX_NPC
	delay 20
	waitmoncry
	setwildbattle SPECIES_VICTINI, 15
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, LibertyGarden_Victini_3
	case B_OUTCOME_RAN, LibertyGarden_Victini_4
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject 1
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox LibertyGarden_Victini_Text_2, MSGBOX_DEFAULT
LibertyGarden_Victini_1:
	release
	end

LibertyGarden_Victini_3:
	setflag FLAG_CAPTURED_VICTINI
	setflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
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
