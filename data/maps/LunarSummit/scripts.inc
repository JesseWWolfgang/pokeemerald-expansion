LunarSummit_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LunarSummit_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

LunarSummit_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_CAPTURED_VICTINI, LunarSummit_MapScripts_MAP_SCRIPT_ON_LOAD_2
	goto_if_unset FLAG_WITNESSED_MILLENNIUM_COMET, LunarSummit_MapScripts_MAP_SCRIPT_ON_LOAD_2
	clearflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
LunarSummit_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	goto_if_set FLAG_WITNESSED_MILLENNIUM_COMET, LunarSummit_MapScripts_MAP_SCRIPT_ON_LOAD_7
	setvar VAR_TEMP_0, 0
	return

LunarSummit_MapScripts_MAP_SCRIPT_ON_LOAD_2:
	setflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	goto LunarSummit_MapScripts_MAP_SCRIPT_ON_LOAD_1

LunarSummit_MapScripts_MAP_SCRIPT_ON_LOAD_7:
	setvar VAR_TEMP_0, 1
	return


LunarSummit_WitnessMillenniumComet::
	lock
	setvar VAR_TEMP_0, 1
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, LunarSummit_CameraMoveToComet
	waitmovement 0
	delay 120
	playse SE_M_DETECT
	dofieldeffectsparkle 47, 3, 0
	waitfieldeffect FLDEFF_SPARKLE
	delay 50
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	setvar VAR_RESULT, 4
	special DoOrbEffect
	delay 500
	special FadeOutOrbEffect
	waitstate
	fadescreen FADE_TO_WHITE
	clearflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	addobject 1
	setobjectxy 1, 44, 4
	playse SE_ICE_BREAK
	fadescreen FADE_FROM_WHITE
	waitse
	delay 20
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 60
	applymovement OBJ_EVENT_ID_CAMERA, LunarSummit_CameraMoveFromComet
	waitmovement 0
	delay 20
	applymovement 1, LunarSummit_JirachiMovesToBattle
	waitmovement 0
	special RemoveCameraObject
	release
	return


LunarSummit_CameraMoveToComet:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

LunarSummit_CameraMoveFromComet:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

LunarSummit_JirachiMovesToBattle:
	walk_slow_down
	walk_slow_down
	step_end

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
