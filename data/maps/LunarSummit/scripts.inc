LunarSummit_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LunarSummit_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

LunarSummit_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_CAPTURED_JIRACHI, LunarSummit_MapScripts_MAP_SCRIPT_ON_LOAD_2
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


LunarSummit_ScientistAtRocket::
	lock
	faceplayer
	goto_if_unset FLAG_WITNESSED_MILLENNIUM_COMET, LunarSummit_ScientistAtRocket_2
	msgbox LunarSummit_ScientistAtRocket_Text_2, MSGBOX_DEFAULT
LunarSummit_ScientistAtRocket_1:
	release
	return

LunarSummit_ScientistAtRocket_2:
	msgbox LunarSummit_ScientistAtRocket_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LunarSummit_ScientistAtRocket_5
	goto LunarSummit_ScientistAtRocket_1

LunarSummit_ScientistAtRocket_5:
	msgbox LunarSummit_ScientistAtRocket_Text_1, MSGBOX_DEFAULT
	closemessage
	call LunarSummit_PrepareTakeOff
	goto LunarSummit_ScientistAtRocket_1


LunarSummit_PrepareTakeOff::
	applymovement 2, LunarSummit_PrepareTakeOffScientist1MoveForPlayerAndScientist2
	waitmovement 0
	applymovementplayerfacing OBJ_EVENT_ID_PLAYER, LunarSummit_PrepareTakeOffPlayerBoardNorth, LunarSummit_PrepareTakeOffPlayerBoardNorth, LunarSummit_PrepareTakeOffPlayerBoardEast, LunarSummit_PrepareTakeOffPlayerBoardWest
	applymovement 4, LunarSummit_PrepareTakeOffScientist2Board
	waitmovement OBJ_EVENT_ID_PLAYER
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_LUNAR_SUMMIT
	playse SE_EXIT
	waitmovement 4
	hideobjectat 4, MAP_LUNAR_SUMMIT
	playse SE_EXIT
	applymovement 2, LunarSummit_PrepareTakeOffScientist1Board
	waitmovement 0
	hideobjectat 2, MAP_LUNAR_SUMMIT
	playse SE_EXIT
	delay 30
	msgbox LunarSummit_PrepareTakeOff_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 60
	call LunarSummit_RocketTakeOff
	return


LunarSummit_RocketTakeOff::
	playse SE_M_EARTHQUAKE
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 32
	setvar VAR_0x8007, 2
	special ShakeCamera
	delay 32
	applymovement 3, LunarSummit_TakeOffRocketWarmUp
	waitstate
	waitmovement 3
	playse SE_M_EARTHQUAKE
	special ShakeCamera
	special SpawnCameraObject
	applymovement 3, LunarSummit_TakeOffRocketMovement
	applymovement OBJ_EVENT_ID_CAMERA, LunarSummit_TakeOffCameraMovement
	waitmovement 3
	waitmovement OBJ_EVENT_ID_CAMERA
	warp MAP_MOSSDEEP_CITY_SPACE_CENTER_1F, 7, 3
	waitstate
	return


LunarSummit_PrepareTakeOffScientist1MoveForPlayerAndScientist2:
	walk_up
	walk_up
	walk_right
	face_left
	step_end

LunarSummit_PrepareTakeOffPlayerBoardNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LunarSummit_PrepareTakeOffPlayerBoardEast:
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

LunarSummit_PrepareTakeOffPlayerBoardWest:
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

LunarSummit_PrepareTakeOffScientist2Board:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LunarSummit_PrepareTakeOffScientist1Board:
	walk_left
	walk_up
	step_end

LunarSummit_TakeOffRocketWarmUp:
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	step_end

LunarSummit_TakeOffRocketMovement:
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

LunarSummit_TakeOffCameraMovement:
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LunarSummit_WitnessMillenniumComet::
	lock
	setflag FLAG_WITNESSED_MILLENNIUM_COMET
	setvar VAR_TEMP_0, 1
	delay 60
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, LunarSummit_CameraMoveToComet
	waitmovement 0
	delay 120
	playse SE_M_DETECT
	dofieldeffectsparkle 47, 3, 0
	dofieldeffectsparkle 46, 3, 0
	dofieldeffectsparkle 48, 3, 0
	dofieldeffectsparkle 47, 2, 0
	dofieldeffectsparkle 47, 4, 0
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
	delay 20
	setvar VAR_LAST_TALKED, 1
	goto LunarSummit_Jirachi
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
	setwildbattle SPECIES_JIRACHI, 40
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, LunarSummit_Jirachi_3
	case B_OUTCOME_RAN, LunarSummit_Jirachi_4
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject 1
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox LunarSummit_Jirachi_Text_2, MSGBOX_DEFAULT
LunarSummit_Jirachi_1:
	release
	end

LunarSummit_Jirachi_3:
	setflag FLAG_CAPTURED_JIRACHI
	setflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	call Common_EventScript_RemoveStaticPokemon
	goto LunarSummit_Jirachi_1

LunarSummit_Jirachi_4:
	msgbox LunarSummit_Jirachi_Text_1, MSGBOX_DEFAULT
	goto LunarSummit_Jirachi_1


LunarSummit_ScientistAtRocket_Text_0:
	.string "Ready to leave?$"

LunarSummit_ScientistAtRocket_Text_1:
	.string "Please board the shuttle and wait for\n"
	.string "lift off.$"

LunarSummit_ScientistAtRocket_Text_2:
	.string "We haven't finished conducting our\n"
	.string "research here just yet.\p"
	.string "You could try and find the highest\n"
	.string "point around here to get a clear view\l"
	.string "of the comet.$"

LunarSummit_PrepareTakeOff_Text_0:
	.string "Take off.$"

LunarSummit_Jirachi_Text_0:
	.string "Wishah wishah!$"

LunarSummit_Jirachi_Text_1:
	.string "Jirachi is watching carefully.$"

LunarSummit_Jirachi_Text_2:
	.string "Jirachi fled into a crater...$"
