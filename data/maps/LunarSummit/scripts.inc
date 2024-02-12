LunarSummit_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LunarSummit_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LunarSummit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LunarSummit_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_CAUGHT_JIRACHI, LunarSummit_MapScripts_MAP_SCRIPT_ON_LOAD_2
	goto_if_unset FLAG_WITNESSED_MILLENNIUM_COMET, LunarSummit_MapScripts_MAP_SCRIPT_ON_LOAD_2
	clearflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	call LunarSummit_SetScientistsToWatchJirachi
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

LunarSummit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_LOADED, FALSE, LunarSummit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

LunarSummit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	setvar VAR_TEMP_LOADED, TRUE
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
	compare VAR_TEMP_2, 65
	goto_if_eq LunarSummit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2
	return

LunarSummit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
	call LunarSummit_FlightIn
	return

LunarSummit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2:
	compare VAR_TEMP_3, 59
	goto_if_eq LunarSummit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1
	return


LunarSummit_Scientist1::
	lock
	faceplayer
	call LunarSummit_PrepareTakeOff
	end
	goto_if_set FLAG_WITNESSED_MILLENNIUM_COMET, LunarSummit_Scientist1_2
	msgbox LunarSummit_Scientist1_Text_3, MSGBOX_DEFAULT
LunarSummit_Scientist1_1:
	release
	return

LunarSummit_Scientist1_2:
	goto_if_set FLAG_CAUGHT_JIRACHI, LunarSummit_Scientist1_5
	msgbox LunarSummit_Scientist1_Text_2, MSGBOX_NPC
	goto LunarSummit_Scientist1_1

LunarSummit_Scientist1_5:
	msgbox LunarSummit_Scientist1_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LunarSummit_Scientist1_8
	goto LunarSummit_Scientist1_1

LunarSummit_Scientist1_8:
	msgbox LunarSummit_Scientist1_Text_1, MSGBOX_DEFAULT
	closemessage
	call LunarSummit_PrepareTakeOff
	goto LunarSummit_Scientist1_1


LunarSummit_Scientist2::
	lock
	faceplayer
	goto_if_set FLAG_WITNESSED_MILLENNIUM_COMET, LunarSummit_Scientist2_2
	msgbox LunarSummit_Scientist2_Text_2, MSGBOX_DEFAULT
LunarSummit_Scientist2_1:
	msgbox LunarSummit_Scientist2_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LunarSummit_Scientist2_6
LunarSummit_Scientist2_5:
	release
	return

LunarSummit_Scientist2_2:
	goto_if_set FLAG_CAUGHT_JIRACHI, LunarSummit_Scientist2_8
	callnative HasAtLeastOnePokeball
	compare VAR_RESULT, FALSE
	goto_if_eq LunarSummit_Scientist2_11
	goto LunarSummit_Scientist2_1

LunarSummit_Scientist2_6:
	msgbox LunarSummit_Scientist2_Text_4, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	delay 30
	msgbox LunarSummit_Scientist2_Text_5, MSGBOX_DEFAULT
	goto LunarSummit_Scientist2_5

LunarSummit_Scientist2_8:
	msgbox LunarSummit_Scientist2_Text_0, MSGBOX_NPC
	goto LunarSummit_Scientist2_1

LunarSummit_Scientist2_11:
	msgbox LunarSummit_Scientist2_Text_1, MSGBOX_NPC
	giveitem ITEM_MOON_BALL, 20
	goto LunarSummit_Scientist2_1


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
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, LunarSummit_PrepareTakeOffCameraToRocket
	waitmovement 0
	delay 30
	special StopMapMusic
	delay 10
	playbgm MUS_EVOLUTION_INTRO, FALSE
	messageautoscroll LunarSummit_PrepareTakeOff_Text_0
	waitmessage
	delay 30
	closemessage
	delay 30
	call LunarSummit_RocketTakeOff
	warpwhitefade MAP_MOSSDEEP_CITY_SPACE_CENTER_1F, 7, 3
	waitstate
	special RemoveCameraObject
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
	waitmovement 3
	playse SE_M_EARTHQUAKE
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 50
	setvar VAR_0x8007, 2
	special ShakeCamera
	applymovement 3, LunarSummit_TakeOffRocketMovement
	applymovement OBJ_EVENT_ID_CAMERA, LunarSummit_TakeOffCameraMovement
	waitstate
	playse SE_INTRO_BLAST
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 40
	setvar VAR_0x8007, 2
	special ShakeCamera
	waitstate
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 80
	setvar VAR_0x8007, 1
	special ShakeCamera
	delay 30
	playse SE_RAIN
	waitmovement 3
	waitmovement OBJ_EVENT_ID_CAMERA
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

LunarSummit_PrepareTakeOffCameraToRocket:
	walk_up
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
	step_end

LunarSummit_WitnessMillenniumComet::
	lock
	setflag FLAG_WITNESSED_MILLENNIUM_COMET
	setvar VAR_TEMP_0, 1
	delay 60
	special SpawnCameraObject
	call LunarSummit_WitnessMillenniumComet_ScientistsBefore
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
	delay 50
	dofieldeffectsparkle 44, 4, 0
	delay 50
	dofieldeffectsparkle 46, 5, 0
	delay 50
	dofieldeffectsparkle 43, 1, 0
	delay 40
	dofieldeffectsparkle 43, 5, 0
	delay 40
	dofieldeffectsparkle 46, 3, 0
	dofieldeffectsparkle 43, 4, 0
	delay 40
	dofieldeffectsparkle 43, 6, 0
	dofieldeffectsparkle 46, 5, 0
	delay 30
	dofieldeffectsparkle 43, 2, 0
	dofieldeffectsparkle 44, 4, 0
	delay 30
	dofieldeffectsparkle 44, 2, 0
	dofieldeffectsparkle 47, 2, 0
	dofieldeffectsparkle 44, 5, 0
	delay 30
	dofieldeffectsparkle 43, 2, 0
	dofieldeffectsparkle 44, 4, 0
	delay 20
	dofieldeffectsparkle 44, 2, 0
	dofieldeffectsparkle 47, 2, 0
	dofieldeffectsparkle 44, 5, 0
	delay 20
	dofieldeffectsparkle 43, 2, 0
	dofieldeffectsparkle 44, 4, 0
	delay 20
	dofieldeffectsparkle 44, 1, 0
	dofieldeffectsparkle 42, 6, 0
	dofieldeffectsparkle 46, 6, 0
	delay 20
	dofieldeffectsparkle 44, 2, 0
	dofieldeffectsparkle 47, 2, 0
	dofieldeffectsparkle 44, 5, 0
	delay 20
	dofieldeffectsparkle 44, 3, 0
	dofieldeffectsparkle 44, 5, 0
	dofieldeffectsparkle 43, 4, 0
	dofieldeffectsparkle 45, 4, 0
	delay 20
	dofieldeffectsparkle 44, 2, 0
	dofieldeffectsparkle 44, 6, 0
	dofieldeffectsparkle 42, 4, 0
	dofieldeffectsparkle 46, 4, 0
	delay 20
	dofieldeffectsparkle 44, 3, 0
	dofieldeffectsparkle 44, 5, 0
	dofieldeffectsparkle 43, 4, 0
	dofieldeffectsparkle 45, 4, 0
	setweather WEATHER_NONE
	doweather
	special FadeOutOrbEffect
	delay 10
	dofieldeffectsparkle 43, 6, 0
	dofieldeffectsparkle 46, 5, 0
	delay 10
	dofieldeffectsparkle 43, 2, 0
	dofieldeffectsparkle 44, 4, 0
	delay 20
	dofieldeffectsparkle 44, 4, 0
	delay 20
	dofieldeffectsparkle 46, 5, 0
	delay 20
	dofieldeffectsparkle 43, 1, 0
	delay 20
	dofieldeffectsparkle 43, 5, 0
	waitstate
	fadescreen FADE_TO_WHITE
	clearflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	addobject 1
	setobjectxy 1, 44, 4
	playse SE_ICE_BREAK
	fadescreen FADE_FROM_WHITE
	delay 4
	dofieldeffectsparkle 44, 3, 0
	delay 4
	dofieldeffectsparkle 44, 5, 0
	delay 4
	dofieldeffectsparkle 43, 4, 0
	delay 4
	dofieldeffectsparkle 45, 4, 0
	delay 4
	dofieldeffectsparkle 44, 4, 0
	waitse
	delay 20
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	waitmoncry
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement 2, Common_Movement_ExclamationMark
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	waitse
	delay 80
	applymovement OBJ_EVENT_ID_CAMERA, LunarSummit_Comet_CameraMoveFromComet
	applymovement 1, LunarSummit_Comet_JirachiMovesToBattle
	waitmovement OBJ_EVENT_ID_CAMERA
	waitmovement 1
	special RemoveCameraObject
	delay 20
	applymovement 4, Common_Movement_WalkInPlace
	waitmovement 0
	msgbox LunarSummit_WitnessMillenniumComet_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement 2, LunarSummit_Comet_ExcitedScientist
	waitmovement 0
	msgbox LunarSummit_WitnessMillenniumComet_Text_1, MSGBOX_DEFAULT
	delay 20
	applymovement 2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox LunarSummit_WitnessMillenniumComet_Text_2, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement 4, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox LunarSummit_WitnessMillenniumComet_Text_3, MSGBOX_DEFAULT
	closemessage
	applymovement 2, LunarSummit_Comet_Scientist1WalkToSideline
	applymovement 4, LunarSummit_Comet_Scientist2WalkToSideline
	waitmovement 2
	waitmovement 4
	call LunarSummit_SetScientistsToWatchJirachi
	return


LunarSummit_SetScientistsToWatchJirachi::
	setobjectxyperm 2, 46, 10
	setobjectxyperm 4, 46, 9
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_LEFT
	return


LunarSummit_WitnessMillenniumComet_ScientistsBefore::
	applymovement OBJ_EVENT_ID_CAMERA, LunarSummit_Comet_CameraMoveToComet1
	waitmovement 0
	delay 120
	removeobject 2
	removeobject 4
	setobjectxyperm 2, 44, 14
	setobjectxyperm 4, 45, 13
	addobject 2
	addobject 4
	applymovement 2, LunarSummit_Comet_Scientist1ApproachPlayer
	applymovement 4, LunarSummit_Comet_Scientist2ApproachPlayer
	waitmovement 2
	waitmovement 4
	delay 30
	applymovement 2, Common_Movement_WalkInPlace
	waitmovement 0
	msgbox LunarSummit_WitnessMillenniumComet_ScientistsBefore_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 100
	msgbox LunarSummit_WitnessMillenniumComet_ScientistsBefore_Text_1, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement 4, Common_Movement_WalkInPlace
	waitmovement 0
	msgbox LunarSummit_WitnessMillenniumComet_ScientistsBefore_Text_2, MSGBOX_DEFAULT
	closemessage
	delay 40
	dofieldeffectsparkle 44, 7, 0
	waitfieldeffect FLDEFF_SPARKLE
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	delay 15
	playse SE_PIN
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 2
	waitmovement 4
	delay 30
	applymovement 2, Common_Movement_WalkInPlace
	waitmovement 0
	msgbox LunarSummit_WitnessMillenniumComet_ScientistsBefore_Text_3, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	delay 10
	callnative NativePlayerPullOutBall
	delay 60
	dofieldeffectsparkle 44, 7, 0
	waitfieldeffect FLDEFF_SPARKLE
	delay 20
	callnative NativePlayerPutAwayBall
	delay 30
	applymovement 2, Common_Movement_WalkInPlace
	waitmovement 0
	msgbox LunarSummit_WitnessMillenniumComet_ScientistsBefore_Text_4, MSGBOX_DEFAULT
	closemessage
	setweather WEATHER_DROUGHT
	doweather
	special WaitWeather
	waitstate
	delay 60
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 2
	msgbox LunarSummit_WitnessMillenniumComet_ScientistsBefore_Text_5, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 40
	applymovement OBJ_EVENT_ID_CAMERA, LunarSummit_Comet_CameraMoveToComet2
	waitmovement 0
	delay 60
	return


LunarSummit_Comet_CameraMoveToComet1:
	walk_slow_up
	step_end

LunarSummit_Comet_CameraMoveToComet2:
	walk_slow_up
	walk_slow_up
	step_end

LunarSummit_Comet_Scientist1ApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LunarSummit_Comet_Scientist2ApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LunarSummit_Comet_CameraMoveFromComet:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

LunarSummit_Comet_JirachiMovesToBattle:
	walk_slow_down
	walk_slow_down
	step_end

LunarSummit_Comet_ExcitedScientist:
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

LunarSummit_Comet_Scientist1WalkToSideline:
	walk_down
	walk_down
	walk_right
	walk_right
	face_left
	step_end

LunarSummit_Comet_Scientist2WalkToSideline:
	walk_down
	walk_right
	face_left
	step_end

LunarSummit_Jirachi::
	lock
	objectfaceplayer 1
	waitse
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	msgbox LunarSummit_Jirachi_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 20
	waitmoncry
	setwildbattle SPECIES_JIRACHI, 40
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, LunarSummit_Jirachi_3
	case B_OUTCOME_RAN, LunarSummit_Jirachi_4
	fadescreenswapbuffers FADE_TO_WHITE
	playse SE_M_COSMIC_POWER
	waitse
	playse SE_SHINY
	waitse
	fadescreenswapbuffers FADE_FROM_WHITE
	msgbox LunarSummit_Jirachi_Text_2, MSGBOX_DEFAULT
	closemessage
LunarSummit_Jirachi_1:
	release
	end

LunarSummit_Jirachi_3:
	setflag FLAG_CAUGHT_JIRACHI
	setflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	call Common_EventScript_RemoveStaticPokemon
	goto LunarSummit_Jirachi_1

LunarSummit_Jirachi_4:
	msgbox LunarSummit_Jirachi_Text_1, MSGBOX_DEFAULT
	goto LunarSummit_Jirachi_1


LunarSummit_FlightIn::
	lock
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_LUNAR_SUMMIT
	special SpawnCameraObject
	setobjectxyperm 3, 65, 0
	setobjectxyperm OBJ_EVENT_ID_CAMERA, 65, 0
	applymovement 3, LunarSummit_FlightIn_DownFast
	applymovement OBJ_EVENT_ID_CAMERA, LunarSummit_FlightIn_DownFast
	fadescreenspeed FADE_FROM_BLACK, 18
	waitmovement 3
	waitmovement OBJ_EVENT_ID_CAMERA
	delay 60
	msgbox LunarSummit_FlightIn_Text_0, MSGBOX_DEFAULT
	closemessage
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_LUNAR_SUMMIT
	release
	return


LunarSummit_FlightIn_DownFast:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

LunarSummit_Scientist1_Text_0:
	.string "Ready to leave?$"

LunarSummit_Scientist1_Text_1:
	.string "Please board the shuttle and wait for\n"
	.string "lift off.$"

LunarSummit_Scientist1_Text_2:
	.string "We're set up and monitoring. Give it your\n"
	.string "all {PLAYER}!$"

LunarSummit_Scientist1_Text_3:
	.string "We haven't finished conducting our\n"
	.string "research here just yet.\p"
	.string "You could try and find the highest\n"
	.string "point around here to get a clear view\l"
	.string "of the comet.$"

LunarSummit_Scientist2_Text_0:
	.string "That was really something up there\n"
	.string "wasn't it?\p"
	.string "I do hope your wish comes true...$"

LunarSummit_Scientist2_Text_1:
	.string "It seems like you're out of Pokéballs...\p"
	.string "Here, take these!$"

LunarSummit_Scientist2_Text_2:
	.string "Hi {PLAYER}, I'm pretty busy taking\n"
	.string "sample data at the moment... can't stop\l"
	.string "for long.$"

LunarSummit_Scientist2_Text_3:
	.string "Would you like me to restore the health\n"
	.string "of your Pokémon?$"

LunarSummit_Scientist2_Text_4:
	.string "Let me take your Pokémon for a moment...$"

LunarSummit_Scientist2_Text_5:
	.string "Fully healed and ready to go!$"

LunarSummit_PrepareTakeOff_Text_0:
	.string "T-minus-5...\p"
	.string "4...\p"
	.string "3...\p"
	.string "2...\p"
	.string "1...\p"
	.string "Lift off!$"

LunarSummit_WitnessMillenniumComet_Text_0:
	.string "Is that... a Pokémon?!$"

LunarSummit_WitnessMillenniumComet_Text_1:
	.string "Simply incredible!\p"
	.string "It's Jirachi!$"

LunarSummit_WitnessMillenniumComet_Text_2:
	.string "We were right to bring you on this\n"
	.string "journey {PLAYER}.\p"
	.string "Jirachi is rumoured to grant a single\n"
	.string "wish each time it awakens every 1000\l"
	.string "years...\p"
	.string "...and it looks like it may have chosen\n"
	.string "you...$"

LunarSummit_WitnessMillenniumComet_Text_3:
	.string "We will observe from the side and\n"
	.string "collect as much data as we can of this\l"
	.string "historical moment.\p"
	.string "Good luck {PLAYER}!$"

LunarSummit_WitnessMillenniumComet_ScientistsBefore_Text_0:
	.string "Would you look at that...$"

LunarSummit_WitnessMillenniumComet_ScientistsBefore_Text_1:
	.string "This truly is a once in a lifetime view.\p"
	.string "I used to read books about this sort of\n"
	.string "thing when I was just a kid.\p"
	.string "...but seeing something like this\n"
	.string "first-hand...\l"
	.string "Nothing truly prepares you.$"

LunarSummit_WitnessMillenniumComet_ScientistsBefore_Text_2:
	.string "Look how bright the comet shines.\n"
	.string "Simply magnificent.$"

LunarSummit_WitnessMillenniumComet_ScientistsBefore_Text_3:
	.string "Hey {PLAYER}...!\p"
	.string "The rock! In your bag!\l"
	.string "It's shining!$"

LunarSummit_WitnessMillenniumComet_ScientistsBefore_Text_4:
	.string "Amazing!\n"
	.string "What could this possibly mean?$"

LunarSummit_WitnessMillenniumComet_ScientistsBefore_Text_5:
	.string "Hold on...\p"
	.string "The light from the comet... it's getting\n"
	.string "brighter!$"

LunarSummit_Jirachi_Text_0:
	.string "Wishah wishah!$"

LunarSummit_Jirachi_Text_1:
	.string "Jirachi is watching carefully.$"

LunarSummit_Jirachi_Text_2:
	.string "Jirachi was enveloped by a sheen of\n"
	.string "light, and fully recovered.$"

LunarSummit_FlightIn_Text_0:
	.string "We're here!$"
