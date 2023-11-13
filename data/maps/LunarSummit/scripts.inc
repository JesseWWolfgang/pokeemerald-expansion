LunarSummit_MapScripts::
	.byte 0


LunarSummit_Jirachi::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	msgbox LunarSummit_Jirachi_Text_0, MSGBOX_NPC
	delay 20
	waitmoncry
	setwildbattle SPECIES_JIRACHI, 15
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, LunarSummit_Jirachi_3
	case B_OUTCOME_RAN, LunarSummit_Jirachi_4
	fadescreenswapbuffers FADE_TO_BLACK
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox LunarSummit_Jirachi_Text_2, MSGBOX_DEFAULT
LunarSummit_Jirachi_1:
	release
	end

LunarSummit_Jirachi_3:
	setflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	call Common_EventScript_RemoveStaticPokemon
	goto LunarSummit_Jirachi_1

LunarSummit_Jirachi_4:
	msgbox LunarSummit_Jirachi_Text_1, MSGBOX_DEFAULT
	goto LunarSummit_Jirachi_1


LunarSummit_Jirachi_Text_0:
	.string "Ta-ta-ta-tah!$"

LunarSummit_Jirachi_Text_1:
	.string "Jirachi is watching carefully.$"

LunarSummit_Jirachi_Text_2:
	.string "Jirachi fled into a crater...$"
