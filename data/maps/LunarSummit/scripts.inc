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
	compare VAR_TEMP_3, 0
	goto_if_eq LunarSummit_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1
	return


LunarSummit_Scientist1::
	lock
	faceplayer
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
	movefromoffscreen 2, 44, 14
	movefromoffscreen 4, 45, 13
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
	goto_if_unset FLAG_JIRACHI_WISH_GRANTED, LunarSummit_Jirachi_2
LunarSummit_Jirachi_1:
	compare VAR_RESULT, 0
	goto_if_ne LunarSummit_Jirachi_5
LunarSummit_Jirachi_4:
	release
	end

LunarSummit_Jirachi_2:
	call LunarSummit_JirachiGrantWish
	goto LunarSummit_Jirachi_1

LunarSummit_Jirachi_5:
	call LunarSummit_JirachiBattle
	goto LunarSummit_Jirachi_4


LunarSummit_JirachiBattle::
	objectfaceplayer 1
	waitse
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	msgbox LunarSummit_JirachiBattle_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 20
	waitmoncry
	setwildbattle SPECIES_JIRACHI, 40
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, LunarSummit_JirachiBattle_2
	case B_OUTCOME_RAN, LunarSummit_JirachiBattle_3
	fadescreenswapbuffers FADE_TO_WHITE
	playse SE_M_COSMIC_POWER
	waitse
	playse SE_SHINY
	waitse
	fadescreenswapbuffers FADE_FROM_WHITE
	msgbox LunarSummit_JirachiBattle_Text_2, MSGBOX_DEFAULT
	closemessage
	return

LunarSummit_JirachiBattle_2:
	setflag FLAG_CAUGHT_JIRACHI
	setflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	call Common_EventScript_RemoveStaticPokemon
	return

LunarSummit_JirachiBattle_3:
	msgbox LunarSummit_JirachiBattle_Text_1, MSGBOX_DEFAULT
	return


LunarSummit_JirachiGrantWish::
	objectfaceplayer 1
	waitse
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	msgbox LunarSummit_JirachiBattle_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 20
	waitmoncry
	delay 30
	playse SE_M_HEAL_BELL
	applymovement 1, LunarSummit_JirachiGrantWishSpin
	waitmovement 0
	waitse
	delay 60
	msgbox LunarSummit_JirachiGrantWish_Text_0, MSGBOX_DEFAULT
LunarSummit_JirachiGrantWish_2:
	msgbox LunarSummit_JirachiGrantWish_Text_1, MSGBOX_DEFAULT
	dynmultipush LunarSummit_JirachiGrantWish_Text_2, 0
	dynmultipush LunarSummit_JirachiGrantWish_Text_3, 1
	dynmultipush LunarSummit_JirachiGrantWish_Text_4, 2
	dynmultipush LunarSummit_JirachiGrantWish_Text_5, 3
	dynmultipush LunarSummit_JirachiGrantWish_Text_6, 4
	dynmultipush LunarSummit_JirachiGrantWish_Text_7, 5
	dynmultipush LunarSummit_JirachiGrantWish_Text_8, 6
	dynmultipush LunarSummit_JirachiGrantWish_Text_9, 7
	dynmultipush LunarSummit_JirachiGrantWish_Text_10, 8
	dynmultipush LunarSummit_JirachiGrantWish_Text_11, MULTI_B_PRESSED
	dynmultistack 1, 1, FALSE, 5, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq LunarSummit_JirachiGrantWish_5
	setvar VAR_0x8000, 0
	setvar VAR_0x8001, 0
	setvar VAR_0x8002, 0
	copyvar VAR_TEMP_8, VAR_RESULT
	setvar VAR_RESULT, NO
	switch VAR_TEMP_8
	case 0, LunarSummit_JirachiGrantWish_9
	case 1, LunarSummit_JirachiGrantWish_10
	case 4, LunarSummit_JirachiGrantWish_11
	case 5, LunarSummit_JirachiGrantWish_12
	case 8, LunarSummit_JirachiGrantWish_13
	case 2, LunarSummit_JirachiGrantWish_14
	case 3, LunarSummit_JirachiGrantWish_15
	case 6, LunarSummit_JirachiGrantWish_16
	case 7, LunarSummit_JirachiGrantWish_17
LunarSummit_JirachiGrantWish_7:
	compare VAR_RESULT, YES
	goto_if_eq LunarSummit_JirachiGrantWish_18
	goto LunarSummit_JirachiGrantWish_2

LunarSummit_JirachiGrantWish_1:
	setflag FLAG_JIRACHI_WISH_GRANTED
	msgbox LunarSummit_JirachiGrantWish_Text_17, MSGBOX_DEFAULT
	closemessage
	playse SE_M_HEAL_BELL
	applymovement 1, LunarSummit_JirachiGrantWishSpin
	waitmovement 0
	waitse
	delay 60
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 30
	msgbox LunarSummit_JirachiGrantWish_Text_18, MSGBOX_DEFAULT
	closemessage
	delay 60
	return

LunarSummit_JirachiGrantWish_5:
	setvar VAR_RESULT, FALSE
	return

LunarSummit_JirachiGrantWish_9:
	msgbox LunarSummit_JirachiGrantWish_Text_12, MSGBOX_YESNO
	goto LunarSummit_JirachiGrantWish_7

LunarSummit_JirachiGrantWish_10:
	msgbox LunarSummit_JirachiGrantWish_Text_13, MSGBOX_YESNO
	goto LunarSummit_JirachiGrantWish_7

LunarSummit_JirachiGrantWish_11:
	msgbox LunarSummit_JirachiGrantWish_Text_14, MSGBOX_YESNO
	goto LunarSummit_JirachiGrantWish_7

LunarSummit_JirachiGrantWish_12:
	msgbox LunarSummit_JirachiGrantWish_Text_15, MSGBOX_YESNO
	goto LunarSummit_JirachiGrantWish_7

LunarSummit_JirachiGrantWish_13:
	msgbox LunarSummit_JirachiGrantWish_Text_16, MSGBOX_YESNO
	goto LunarSummit_JirachiGrantWish_7

LunarSummit_JirachiGrantWish_14:
	call LunarSummit_JirachiGrantWish_Item
	goto LunarSummit_JirachiGrantWish_7

LunarSummit_JirachiGrantWish_15:
	call LunarSummit_JirachiGrantWish_Power
	goto LunarSummit_JirachiGrantWish_7

LunarSummit_JirachiGrantWish_16:
	call LunarSummit_JirachiGrantWish_Shiny
	goto LunarSummit_JirachiGrantWish_7

LunarSummit_JirachiGrantWish_17:
	call LunarSummit_JirachiGrantWish_TeachSketch
	goto LunarSummit_JirachiGrantWish_7

LunarSummit_JirachiGrantWish_18:
	goto LunarSummit_JirachiGrantWish_1


LunarSummit_JirachiGrantWish_Shiny::
LunarSummit_JirachiGrantWish_Shiny_1:
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_lt LunarSummit_JirachiGrantWish_Shiny_3
	setvar VAR_RESULT, NO
	return

LunarSummit_JirachiGrantWish_Shiny_3:
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq LunarSummit_JirachiGrantWish_Shiny_6
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	getmondataforpartymon VAR_0x8004, M_MON_DATA_IS_SHINY
	compare VAR_RESULT, TRUE
	goto_if_eq LunarSummit_JirachiGrantWish_Shiny_9
	copyvar VAR_0x8000, VAR_0x8004
	msgbox LunarSummit_JirachiGrantWish_Shiny_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LunarSummit_JirachiGrantWish_Shiny_13
LunarSummit_JirachiGrantWish_Shiny_12:
	return

LunarSummit_JirachiGrantWish_Shiny_6:
	msgbox LunarSummit_JirachiGrantWish_Shiny_Text_0, MSGBOX_DEFAULT
	closemessage
	goto LunarSummit_JirachiGrantWish_Shiny_1

LunarSummit_JirachiGrantWish_Shiny_9:
	msgbox LunarSummit_JirachiGrantWish_Shiny_Text_1, MSGBOX_DEFAULT
	closemessage
	goto LunarSummit_JirachiGrantWish_Shiny_1

LunarSummit_JirachiGrantWish_Shiny_13:
	setmondataforpartymon VAR_0x8004, M_MON_DATA_IS_SHINY, TRUE
	goto LunarSummit_JirachiGrantWish_Shiny_12


LunarSummit_JirachiGrantWish_Power::
LunarSummit_JirachiGrantWish_Power_1:
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_lt LunarSummit_JirachiGrantWish_Power_3
	setvar VAR_RESULT, NO
	return

LunarSummit_JirachiGrantWish_Power_3:
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq LunarSummit_JirachiGrantWish_Power_6
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	copyvar VAR_0x8000, VAR_0x8004
	msgbox LunarSummit_JirachiGrantWish_Power_Text_1, MSGBOX_YESNO
	return

LunarSummit_JirachiGrantWish_Power_6:
	msgbox LunarSummit_JirachiGrantWish_Power_Text_0, MSGBOX_DEFAULT
	closemessage
	goto LunarSummit_JirachiGrantWish_Power_1


LunarSummit_JirachiGrantWish_Item::
	choosebagitem FALSE, POCKET_ITEMS, FALSE
	compare VAR_ITEM_ID, ITEM_NONE
	goto_if_ne LunarSummit_JirachiGrantWish_Item_1
	setvar VAR_RESULT, NO
	return

LunarSummit_JirachiGrantWish_Item_1:
	bufferitemnameplural STR_VAR_1, VAR_ITEM_ID, 2
	msgbox LunarSummit_JirachiGrantWish_Item_Text_0, MSGBOX_YESNO
	return


LunarSummit_JirachiGrantWish_TeachSketch::
LunarSummit_JirachiGrantWish_TeachSketch_1:
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_lt LunarSummit_JirachiGrantWish_TeachSketch_3
	setvar VAR_RESULT, NO
	return

LunarSummit_JirachiGrantWish_TeachSketch_3:
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq LunarSummit_JirachiGrantWish_TeachSketch_6
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	buffermovename STR_VAR_2, MOVE_SKETCH
	clearflag FLAG_TEMP_10
	getmondataforpartymon VAR_0x8004, M_MON_DATA_MOVE1
	compare VAR_RESULT, MOVE_SKETCH
	goto_if_eq LunarSummit_JirachiGrantWish_TeachSketch_10
LunarSummit_JirachiGrantWish_TeachSketch_9:
	getmondataforpartymon VAR_0x8004, M_MON_DATA_MOVE2
	compare VAR_RESULT, MOVE_SKETCH
	goto_if_eq LunarSummit_JirachiGrantWish_TeachSketch_13
LunarSummit_JirachiGrantWish_TeachSketch_12:
	getmondataforpartymon VAR_0x8004, M_MON_DATA_MOVE3
	compare VAR_RESULT, MOVE_SKETCH
	goto_if_eq LunarSummit_JirachiGrantWish_TeachSketch_16
LunarSummit_JirachiGrantWish_TeachSketch_15:
	getmondataforpartymon VAR_0x8004, M_MON_DATA_MOVE4
	compare VAR_RESULT, MOVE_SKETCH
	goto_if_eq LunarSummit_JirachiGrantWish_TeachSketch_19
LunarSummit_JirachiGrantWish_TeachSketch_18:
	goto_if_set FLAG_TEMP_10, LunarSummit_JirachiGrantWish_TeachSketch_21
	copyvar VAR_0x8000, VAR_0x8004
	msgbox LunarSummit_JirachiGrantWish_TeachSketch_Text_2, MSGBOX_YESNO
	return

LunarSummit_JirachiGrantWish_TeachSketch_6:
	msgbox LunarSummit_JirachiGrantWish_TeachSketch_Text_0, MSGBOX_DEFAULT
	closemessage
	goto LunarSummit_JirachiGrantWish_TeachSketch_1

LunarSummit_JirachiGrantWish_TeachSketch_10:
	setflag FLAG_TEMP_10
	goto LunarSummit_JirachiGrantWish_TeachSketch_9

LunarSummit_JirachiGrantWish_TeachSketch_13:
	setflag FLAG_TEMP_10
	goto LunarSummit_JirachiGrantWish_TeachSketch_12

LunarSummit_JirachiGrantWish_TeachSketch_16:
	setflag FLAG_TEMP_10
	goto LunarSummit_JirachiGrantWish_TeachSketch_15

LunarSummit_JirachiGrantWish_TeachSketch_19:
	setflag FLAG_TEMP_10
	goto LunarSummit_JirachiGrantWish_TeachSketch_18

LunarSummit_JirachiGrantWish_TeachSketch_21:
	msgbox LunarSummit_JirachiGrantWish_TeachSketch_Text_1, MSGBOX_DEFAULT
	closemessage
	goto LunarSummit_JirachiGrantWish_TeachSketch_1


LunarSummit_JirachiGrantWishSpin:
	face_left
	delay_16
	face_up
	delay_16
	face_right
	delay_16
	face_down
	step_end

LunarSummit_FlightIn::
	lock
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_LUNAR_SUMMIT
	setobjectxyperm 2, 0, 0
	setobjectxyperm 4, 0, 0
	movefromoffscreen 3, 65, 2
	callnative FillPalBufferBlack
	playse SE_DOWNPOUR
	applymovement 3, LunarSummit_FlightIn_DownFast
	applymovement OBJ_EVENT_ID_PLAYER, LunarSummit_FlightIn_DownFast
	fadescreenspeed FADE_FROM_BLACK, 18
	waitmovement 3
	waitmovement OBJ_EVENT_ID_PLAYER
	playse SE_DOWNPOUR_STOP
	applymovement 3, LunarSummit_FlightIn_DownSlow
	applymovement OBJ_EVENT_ID_PLAYER, LunarSummit_FlightIn_DownSlow
	waitmovement 3
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 3
	setvar VAR_0x8007, 4
	special ShakeCamera
	playse SE_LAVARIDGE_FALL_WARP
	waitse
	delay 90
	playfanfare MUS_EVOLVED
	messageautoscroll LunarSummit_FlightIn_Text_0
	waitmessage
	waitfanfare
	delay 40
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LunarSummit_FlightIn_CameraToPlayer
	waitmovement 0
	movefromoffscreen 2, 65, 58
	applymovement 2, LunarSummit_FlightIn_Scientist1Exit
	playse SE_TRUCK_DOOR
	waitse
	waitmovement 0
	movefromoffscreen 4, 65, 58
	applymovement 4, LunarSummit_FlightIn_Scientist2Exit
	waitmovement 0
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_LUNAR_SUMMIT
	applymovement OBJ_EVENT_ID_PLAYER, LunarSummit_FlightIn_PlayerExit
	waitmovement 0
	playerfaceobject 2
	delay 20
	applymovement 2, Common_Movement_WalkInPlace
	waitmovement 0
	msgbox LunarSummit_FlightIn_Text_1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LunarSummit_Landed_PlayerWalkIn
	delay 30
	applymovement 4, LunarSummit_Landed_Scientist2WalkIn
	delay 30
	applymovement 2, LunarSummit_Landed_Scientist1WalkIn
	delay 30
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement 2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	delay 30
	msgbox LunarSummit_FlightIn_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LunarSummit_FlightIn_2
	msgbox LunarSummit_FlightIn_Text_4, MSGBOX_DEFAULT
LunarSummit_FlightIn_1:
	closemessage
	waitmovement 4
	fadescreen FADE_TO_BLACK
	setobjectxyperm 3, 65, 58
	setobjectxyperm 2, 63, 61
	setobjectxyperm 4, 61, 65
	setobjectxy 2, 63, 61
	setobjectxy 4, 61, 65
	turnobject 2, DIR_SOUTH
	turnobject 4, DIR_SOUTH
	fadescreen FADE_FROM_BLACK
	release
	return

LunarSummit_FlightIn_2:
	msgbox LunarSummit_FlightIn_Text_3, MSGBOX_DEFAULT
	goto LunarSummit_FlightIn_1


LunarSummit_FlightIn_DownFast:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
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
	walk_down
	walk_down
	walk_down
	step_end

LunarSummit_FlightIn_DownSlow:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

LunarSummit_FlightIn_CameraToPlayer:
	walk_down
	walk_down
	step_end

LunarSummit_FlightIn_Scientist1Exit:
	walk_slow_down
	walk_left
	face_right
	step_end

LunarSummit_FlightIn_Scientist2Exit:
	walk_slow_down
	walk_right
	face_left
	step_end

LunarSummit_FlightIn_PlayerExit:
	walk_slow_down
	step_end

LunarSummit_Landed_PlayerWalkIn:
	walk_down
	walk_down
	walk_down
	step_end

LunarSummit_Landed_Scientist1WalkIn:
	walk_right
	walk_down
	walk_down
	step_end

LunarSummit_Landed_Scientist2WalkIn:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
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

LunarSummit_JirachiBattle_Text_0:
	.string "Wishah wishah!$"

LunarSummit_JirachiBattle_Text_1:
	.string "Jirachi is watching carefully.$"

LunarSummit_JirachiBattle_Text_2:
	.string "Jirachi was enveloped by a sheen of\n"
	.string "light, and fully recovered.$"

LunarSummit_JirachiGrantWish_Text_0:
	.string "It looks as though Jirachi is waiting to\n"
	.string "hear your wish.$"

LunarSummit_JirachiGrantWish_Text_1:
	.string "What do you wish for?$"

LunarSummit_JirachiGrantWish_Text_2:
	.string "Lots of money!$"

LunarSummit_JirachiGrantWish_Text_3:
	.string "Lots of Master Balls!$"

LunarSummit_JirachiGrantWish_Text_4:
	.string "Make more of an item!$"

LunarSummit_JirachiGrantWish_Text_5:
	.string "Maximise a Pokémon's power!$"

LunarSummit_JirachiGrantWish_Text_6:
	.string "Unlimited repel! I hate grass!$"

LunarSummit_JirachiGrantWish_Text_7:
	.string "Pokérus!$"

LunarSummit_JirachiGrantWish_Text_8:
	.string "Make a Pokémon shiny!$"

LunarSummit_JirachiGrantWish_Text_9:
	.string "Teach me Sketch!$"

LunarSummit_JirachiGrantWish_Text_10:
	.string "Surprise me!$"

LunarSummit_JirachiGrantWish_Text_11:
	.string "Wait, let me think...$"

LunarSummit_JirachiGrantWish_Text_12:
	.string "You wish to be able to buy anything you\n"
	.string "wish? Are you sure?$"

LunarSummit_JirachiGrantWish_Text_13:
	.string "You wish to have lots of Master Balls?\n"
	.string "Are you sure?$"

LunarSummit_JirachiGrantWish_Text_14:
	.string "You wish to be able to have a\n"
	.string "never-ending supply of repel? Are you\l"
	.string "sure?$"

LunarSummit_JirachiGrantWish_Text_15:
	.string "You wish to have your party contract\n"
	.string "Pokérus? Are you sure?$"

LunarSummit_JirachiGrantWish_Text_16:
	.string "A surprise? That seems kind of risky...\n"
	.string "Are you absolutely sure about this?$"

LunarSummit_JirachiGrantWish_Text_17:
	.string "..............$"

LunarSummit_JirachiGrantWish_Text_18:
	.string "You feel your body become light\n"
	.string "momentarily...$"

LunarSummit_JirachiGrantWish_Shiny_Text_0:
	.string "An egg cannot be turned into a shiny.$"

LunarSummit_JirachiGrantWish_Shiny_Text_1:
	.string "{STR_VAR_1} is already shiny.$"

LunarSummit_JirachiGrantWish_Shiny_Text_2:
	.string "You want to make your {STR_VAR_1}\n"
	.string "shiny? This cannot be undone. Are you\l"
	.string "sure?$"

LunarSummit_JirachiGrantWish_Power_Text_0:
	.string "An egg cannot have its power improved.$"

LunarSummit_JirachiGrantWish_Power_Text_1:
	.string "You want to perfect the power of your\n"
	.string "{STR_VAR_1}? This cannot be\l"
	.string "undone. Are you sure?$"

LunarSummit_JirachiGrantWish_Item_Text_0:
	.string "You wish to make more {STR_VAR_1}?\n"
	.string "Are you sure?$"

LunarSummit_JirachiGrantWish_TeachSketch_Text_0:
	.string "An egg cannot learn moves.$"

LunarSummit_JirachiGrantWish_TeachSketch_Text_1:
	.string "{STR_VAR_1} already knows\n"
	.string "{STR_VAR_2}.$"

LunarSummit_JirachiGrantWish_TeachSketch_Text_2:
	.string "You want to teach {STR_VAR_2} to\n"
	.string "{STR_VAR_1}? Are you sure?$"

LunarSummit_FlightIn_Text_0:
	.string "Successful landing number 101!$"

LunarSummit_FlightIn_Text_1:
	.string "Here we are {PLAYER}.\n"
	.string "Please, after you...$"

LunarSummit_FlightIn_Text_2:
	.string "We are going to spend some time setting\n"
	.string "up and collecting data for the mission.\p"
	.string "Why don't you take a bit of a moonwalk\n"
	.string "in the meantime?\p"
	.string "See if you can get to the highest point\n"
	.string "around here. It should be the best\l"
	.string "place to view the Millennium Comet!\p"
	.string "Can we depend on you for this\n"
	.string "{PLAYER}?$"

LunarSummit_FlightIn_Text_3:
	.string "I knew we could! We will catch up to you\n"
	.string "soon okay?\p"
	.string "If you ever need to restore your team's\n"
	.string "health, come see us. Good luck!$"

LunarSummit_FlightIn_Text_4:
	.string "It's okay to be nervous. Don't worry, we\n"
	.string "have your back.\p"
	.string "If you ever need to restore your team's\n"
	.string "health, come see us. Good luck!$"
