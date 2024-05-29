MossdeepCity_SpaceCenter_Pad_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_LOAD:
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	return

MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_LOADED, FALSE, MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	setvar VAR_TEMP_LOADED, TRUE
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 19
	goto_if_eq MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_6
MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_4:
	compare VAR_TEMP_0, 28
	goto_if_eq MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_3
	return

MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
	call MossdeepCity_SpaceCenter_Pad_GuideLady_Entrance
	return

MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2:
	call MossdeepCity_SpaceCenter_Pad_LandingIn
	return

MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_3:
	compare VAR_TEMP_1, 0
	goto_if_eq MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2
	return

MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_6:
	compare VAR_TEMP_1, 43
	goto_if_eq MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1
	goto MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_4


TEST_Warp_to_Castelia::
	warp MAP_CASTELIA_CITY_LIBERTY_PIER, 0
	waitstate
	return


MossdeepCity_SpaceCenter_Pad_Sign::
	msgbox MossdeepCity_SpaceCenter_Pad_Sign_Text_0, MSGBOX_SIGN
	return


MossdeepCity_SpaceCenter_Pad_GuideLady::
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_Pad_GuideLady_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MossdeepCity_SpaceCenter_Pad_GuideLady_2
MossdeepCity_SpaceCenter_Pad_GuideLady_1:
	release
	return

MossdeepCity_SpaceCenter_Pad_GuideLady_2:
	msgbox MossdeepCity_SpaceCenter_Pad_GuideLady_Text_1, MSGBOX_DEFAULT
	warp MAP_MOSSDEEP_CITY_SPACE_CENTER_1F, 7, 3
	waitstate
	goto MossdeepCity_SpaceCenter_Pad_GuideLady_1


MossdeepCity_SpaceCenter_Pad_GuideLady_Entrance::
	lock
	objectfaceplayer 13
	msgbox MossdeepCity_SpaceCenter_Pad_GuideLady_Entrance_Text_0, MSGBOX_DEFAULT
	release
	return


MossdeepCity_SpaceCenter_Pad_Scientist2::
	msgbox MossdeepCity_SpaceCenter_Pad_Scientist2_Text_0, MSGBOX_NPC
	applymovement 3, Common_Movement_FaceDown
	waitmovement 0
	return


MossdeepCity_SpaceCenter_Pad_Scientist1::
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_Pad_Scientist1_Text_0, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_SpaceCenter_Pad_Scientist1_2
	compare VAR_FACING, DIR_WEST
	goto_if_eq MossdeepCity_SpaceCenter_Pad_Scientist1_5
MossdeepCity_SpaceCenter_Pad_Scientist1_4:
	msgbox MossdeepCity_SpaceCenter_Pad_Scientist1_Text_2, MSGBOX_DEFAULT
	closemessage
	applymovement 3, Common_Movement_WalkInPlace
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_Pad_Scientist1_Text_3, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 20
	clearflag FLAG_TEMP_1
	addobject 11, MAP_MOSSDEEP_CITY_SPACE_CENTER_PAD
	addobject 12, MAP_MOSSDEEP_CITY_SPACE_CENTER_PAD
	applymovement 11, MossdeepCity_SpaceCenter_Pad_BirchMoveToPlayer
	applymovement 12, MossdeepCity_SpaceCenter_Pad_MomMoveToPlayer
	waitmovement 11
	waitmovement 12
	applymovement 11, Common_Movement_WalkInPlace
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_Pad_Scientist1_Text_4, MSGBOX_DEFAULT
	closemessage
	applymovement 3, Common_Movement_WalkInPlace
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_Pad_Scientist1_Text_5, MSGBOX_DEFAULT
	closemessage
	applymovement 12, Common_Movement_WalkInPlace
	waitmovement 0
	playerfaceobject 12
	msgbox MossdeepCity_SpaceCenter_Pad_Scientist1_Text_6, MSGBOX_DEFAULT
	closemessage
	applymovement 11, Common_Movement_WalkInPlace
	waitmovement 0
	playerfaceobject 11
	msgbox MossdeepCity_SpaceCenter_Pad_Scientist1_Text_7, MSGBOX_DEFAULT
	closemessage
	applymovement 3, Common_Movement_WalkInPlace
	waitmovement 0
	playerfaceobject 3
	msgbox MossdeepCity_SpaceCenter_Pad_Scientist1_Text_8, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_WalkInPlace
	waitmovement 0
	playerfaceobject 4
	msgbox MossdeepCity_SpaceCenter_Pad_Scientist1_Text_9, MSGBOX_DEFAULT
	closemessage
	call MossdeepCity_SpaceCenter_Pad_PrepareTakeOff
	return

MossdeepCity_SpaceCenter_Pad_Scientist1_2:
	msgbox MossdeepCity_SpaceCenter_Pad_Scientist1_Text_1, MSGBOX_DEFAULT
	applymovement 4, Common_Movement_FaceDown
	waitmovement 0
	closemessage
	release
	end

MossdeepCity_SpaceCenter_Pad_Scientist1_5:
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_Pad_MoveInFrontOfScientist
	waitmovement 0
	applymovement 4, Common_Movement_FaceDown
	waitmovement 0
	goto MossdeepCity_SpaceCenter_Pad_Scientist1_4


MossdeepCity_SpaceCenter_Pad_MoveInFrontOfScientist:
	walk_down
	walk_left
	face_up
	step_end

MossdeepCity_SpaceCenter_Pad_BirchMoveToPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MossdeepCity_SpaceCenter_Pad_MomMoveToPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

MossdeepCity_SpaceCenter_Pad_Scientist1BoardRocket:
	walk_slow_up
	walk_slow_up
	step_end

MossdeepCity_SpaceCenter_Pad_Scientist2BoardRocket:
	walk_right
	walk_slow_up
	walk_slow_up
	step_end

MossdeepCity_SpaceCenter_Pad_PlayerBoardRocket:
	walk_up
	walk_slow_up
	walk_slow_up
	step_end

MossdeepCity_SpaceCenter_Pad_PrepareTakeOff::
	applymovement 4, MossdeepCity_SpaceCenter_Pad_Scientist1BoardRocket
	waitmovement 0
	hideobjectat 4, MAP_MOSSDEEP_CITY_SPACE_CENTER_PAD
	playse SE_EXIT
	applymovement 3, MossdeepCity_SpaceCenter_Pad_Scientist2BoardRocket
	waitmovement 0
	hideobjectat 3, MAP_MOSSDEEP_CITY_SPACE_CENTER_PAD
	playse SE_EXIT
	applymovement 12, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_Pad_PlayerBoardRocket
	messageautoscroll MossdeepCity_SpaceCenter_Pad_PrepareTakeOff_Text_0
	waitmovement OBJ_EVENT_ID_PLAYER
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_MOSSDEEP_CITY_SPACE_CENTER_PAD
	playse SE_EXIT
	waitmessage
	delay 40
	closemessage
	delay 30
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MossdeepCity_SpaceCenter_Pad_PrepareTakeOffCameraToRocket
	waitmovement 0
	delay 30
	special StopMapMusic
	delay 10
	playbgm MUS_EVOLUTION_INTRO, FALSE
	messageautoscroll MossdeepCity_SpaceCenter_Pad_PrepareTakeOff_Text_1
	waitmessage
	playbgm MUS_RG_HALL_OF_FAME, FALSE
	delay 60
	closemessage
	delay 30
	call MossdeepCity_SpaceCenter_Pad_RocketTakeOff
	preventwarpfadeout
	preventwarpfadein
	warp MAP_LUNAR_SUMMIT, 0
	waitstate
	return


MossdeepCity_SpaceCenter_Pad_RocketTakeOff::
	playse SE_M_EARTHQUAKE
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 32
	setvar VAR_0x8007, 2
	special ShakeCamera
	delay 32
	applymovement 1, MossdeepCity_SpaceCenter_Pad_TakeOffRocketWarmUp
	waitmovement 1
	playse SE_M_EARTHQUAKE
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 50
	setvar VAR_0x8007, 2
	special ShakeCamera
	applymovement 1, MossdeepCity_SpaceCenter_Pad_TakeOffRocketMovement
	applymovement OBJ_EVENT_ID_CAMERA, MossdeepCity_SpaceCenter_Pad_TakeOffCameraMovement
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
	waitmovement 1
	waitmovement OBJ_EVENT_ID_CAMERA
	applymovement 1, MossdeepCity_SpaceCenter_Pad_TakeOffRocketFast
	applymovement OBJ_EVENT_ID_CAMERA, MossdeepCity_SpaceCenter_Pad_TakeOffRocketFast
	fadescreen FADE_TO_WHITE
	playse SE_M_SKY_UPPERCUT
	fadescreen FADE_FROM_WHITE
	waitmovement 1
	waitmovement OBJ_EVENT_ID_CAMERA
	applymovement 1, MossdeepCity_SpaceCenter_Pad_TakeOffRocketFast
	applymovement OBJ_EVENT_ID_CAMERA, MossdeepCity_SpaceCenter_Pad_TakeOffRocketFast
	fadescreen FADE_TO_WHITE
	playse SE_M_SKY_UPPERCUT
	fadescreen FADE_FROM_WHITE
	waitmovement 1
	waitmovement OBJ_EVENT_ID_CAMERA
	applymovement 1, MossdeepCity_SpaceCenter_Pad_TakeOffRocketExit
	applymovement OBJ_EVENT_ID_CAMERA, MossdeepCity_SpaceCenter_Pad_TakeOffRocketFast
	playse SE_INTRO_BLAST
	fadescreenspeed FADE_TO_BLACK, 18
	waitmovement 1
	waitmovement OBJ_EVENT_ID_CAMERA
	playse SE_RAIN_STOP
	waitse
	playse SE_EXIT
	waitse
	delay 100
	fadeoutbgm 0
	delay 60
	special StopMapMusic
	msgbox MossdeepCity_SpaceCenter_Pad_RocketTakeOff_Text_0, MSGBOX_DEFAULT
	closemessage
	return


MossdeepCity_SpaceCenter_Pad_PrepareTakeOffCameraToRocket:
	walk_up
	walk_up
	step_end

MossdeepCity_SpaceCenter_Pad_TakeOffRocketWarmUp:
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	step_end

MossdeepCity_SpaceCenter_Pad_TakeOffRocketMovement:
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
	step_end

MossdeepCity_SpaceCenter_Pad_TakeOffRocketFast:
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
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

MossdeepCity_SpaceCenter_Pad_TakeOffRocketExit:
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

MossdeepCity_SpaceCenter_Pad_TakeOffCameraMovement:
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
	step_end

MossdeepCity_SpaceCenter_Pad_LandingIn::
	clearflag FLAG_MAP_MUSIC_OVERRIDE
	lock
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_MOSSDEEP_CITY_SPACE_CENTER_PAD
	setobjectxyperm 4, 0, 0
	setobjectxyperm 3, 0, 0
	movefromoffscreen 1, 28, 2
	callnative FillPalBufferWhite
	playse SE_DOWNPOUR
	applymovement 1, MossdeepCity_SpaceCenter_Pad_LandingIn_Down
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_Pad_LandingIn_Down
	fadescreenspeed FADE_FROM_WHITE, 18
	waitmovement 1
	waitmovement OBJ_EVENT_ID_PLAYER
	playse SE_DOWNPOUR_STOP
	applymovement 1, MossdeepCity_SpaceCenter_Pad_LandingIn_DownSlow
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_Pad_LandingIn_DownSlow
	waitmovement 1
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
	messageautoscroll MossdeepCity_SpaceCenter_Pad_LandingIn_Text_0
	waitmessage
	waitfanfare
	delay 40
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_Pad_LandingIn_CameraToPlayer
	waitmovement 0
	movefromoffscreen 4, 28, 39
	applymovement 4, MossdeepCity_SpaceCenter_Pad_LandingIn_Scientist1Exit
	playse SE_TRUCK_DOOR
	waitse
	waitmovement 0
	movefromoffscreen 3, 28, 39
	applymovement 3, MossdeepCity_SpaceCenter_Pad_LandingIn_Scientist2Exit
	waitmovement 0
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_MOSSDEEP_CITY_SPACE_CENTER_PAD
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_Pad_LandingIn_PlayerExit
	waitmovement 0
	playerfaceobject 4
	delay 20
	applymovement 4, Common_Movement_WalkInPlace
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_Pad_LandingIn_Text_1, MSGBOX_DEFAULT
	applymovement 4, Common_Movement_WalkInPlaceLeft
	msgbox MossdeepCity_SpaceCenter_Pad_LandingIn_Text_2, MSGBOX_DEFAULT
	closemessage
	delay 30
	playse SE_RG_SS_ANNE_HORN
	waitse
	delay 30
	special Overworld_PlaySpecialMapMusic
	delay 20
	clearflag FLAG_TEMP_2
	addobject 14, MAP_MOSSDEEP_CITY_SPACE_CENTER_PAD
	applymovement 14, MossdeepCity_SpaceCenter_Pad_BoatRide_BoatEnter
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_Pad_BoatRide_PlayerToBoat
	delay 30
	applymovement 4, MossdeepCity_SpaceCenter_Pad_BoatRide_Scientist1ToBoat
	applymovement 3, MossdeepCity_SpaceCenter_Pad_BoatRide_Scientist2ToBoat
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement 4
	waitmovement 3
	delay 60
	clearflag FLAG_TEMP_3
	addobject 15, MAP_MOSSDEEP_CITY_SPACE_CENTER_PAD
	applymovement 15, Common_Movement_WalkRight
	waitmovement 0
	delay 30
	msgbox MossdeepCity_SpaceCenter_Pad_LandingIn_Text_3, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_WalkInPlace
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_Pad_LandingIn_Text_4, MSGBOX_DEFAULT
	closemessage
	applymovement 15, Common_Movement_WalkInPlace
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_Pad_LandingIn_Text_5, MSGBOX_DEFAULT
	closemessage
	applymovement 15, MossdeepCity_SpaceCenter_Pad_BoatRide_StevenBoard
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_Pad_BoatRide_PlayerBoard
	applymovement 4, MossdeepCity_SpaceCenter_Pad_BoatRide_Scientist1Board
	applymovement 3, MossdeepCity_SpaceCenter_Pad_BoatRide_Scientist2Board
	waitmovement 15
	removeobject 15
	waitmovement OBJ_EVENT_ID_PLAYER
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_MOSSDEEP_CITY_SPACE_CENTER_PAD
	playse SE_EXIT
	waitmovement 4
	setobjectxyperm 4, 0, 0
	removeobject 4
	waitmovement 3
	setobjectxyperm 3, 0, 0
	removeobject 3
	delay 60
	applymovement 14, MossdeepCity_SpaceCenter_Pad_BoatRide_BoatToSpaceCenter
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_Pad_BoatRide_BoatToSpaceCenter
	waitmovement 0
	warp MAP_MOSSDEEP_CITY_SPACE_CENTER_1F, 7, 4
	waitstate
	release
	return


MossdeepCity_SpaceCenter_Pad_LandingIn_Down:
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

MossdeepCity_SpaceCenter_Pad_LandingIn_DownSlow:
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

MossdeepCity_SpaceCenter_Pad_LandingIn_CameraToPlayer:
	walk_down
	walk_down
	step_end

MossdeepCity_SpaceCenter_Pad_LandingIn_Scientist1Exit:
	walk_slow_down
	walk_left
	face_right
	step_end

MossdeepCity_SpaceCenter_Pad_LandingIn_Scientist2Exit:
	walk_slow_down
	walk_right
	face_left
	step_end

MossdeepCity_SpaceCenter_Pad_LandingIn_PlayerExit:
	walk_slow_down
	step_end

MossdeepCity_SpaceCenter_Pad_BoatRide_BoatEnter:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	step_end

MossdeepCity_SpaceCenter_Pad_BoatRide_PlayerToBoat:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_SpaceCenter_Pad_BoatRide_Scientist1ToBoat:
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_SpaceCenter_Pad_BoatRide_Scientist2ToBoat:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_SpaceCenter_Pad_BoatRide_StevenBoard:
	walk_left
	walk_left
	step_end

MossdeepCity_SpaceCenter_Pad_BoatRide_PlayerBoard:
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_SpaceCenter_Pad_BoatRide_Scientist1Board:
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_SpaceCenter_Pad_BoatRide_Scientist2Board:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_SpaceCenter_Pad_BoatRide_BoatToSpaceCenter:
	walk_slow_left
	walk_slow_left
	walk_slow_down
	walk_slow_down
	walk_down
	walk_down
	walk_down
	walk_down
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
	walk_slow_down
	walk_slow_down
	step_end

MossdeepCity_SpaceCenter_Pad_Sign_Text_0:
	.string "Mossdeep Space Center Launch Pad$"

MossdeepCity_SpaceCenter_Pad_GuideLady_Text_0:
	.string "Are you not prepared? Would you like to\n"
	.string "return inside?$"

MossdeepCity_SpaceCenter_Pad_GuideLady_Text_1:
	.string "Okay, but please don't dawdle, you are\n"
	.string "due to leave imminently.$"

MossdeepCity_SpaceCenter_Pad_GuideLady_Entrance_Text_0:
	.string "Here is the launch pad for the Mossdeep\n"
	.string "Space Shuttle. Your crew are up ahead.\p"
	.string "I wish you the best of luck!$"

MossdeepCity_SpaceCenter_Pad_Scientist2_Text_0:
	.string "How are you feeling {PLAYER}? I'm\n"
	.string "excited to see what this journey holds\l"
	.string "in store for us.$"

MossdeepCity_SpaceCenter_Pad_Scientist1_Text_0:
	.string "Here we are {PLAYER}!\p"
	.string "You're absolutely sure you're all set to\n"
	.string "leave?$"

MossdeepCity_SpaceCenter_Pad_Scientist1_Text_1:
	.string "Take a brief moment to collect\n"
	.string "yourself, we will be waiting here.$"

MossdeepCity_SpaceCenter_Pad_Scientist1_Text_2:
	.string "Our ground team has already briefed you\n"
	.string "and your Pokémon on our spaceship\l"
	.string "travel protocol.\p"
	.string "You will be responsible for them during\n"
	.string "the journey.\p"
	.string "I'm also sure they will do their absolute\n"
	.string "best for you, should you need them.$"

MossdeepCity_SpaceCenter_Pad_Scientist1_Text_3:
	.string "Hey {PLAYER}, looks like there are\n"
	.string "some people here to see you...$"

MossdeepCity_SpaceCenter_Pad_Scientist1_Text_4:
	.string "Would you look at this. I'd never have\n"
	.string "imagined our own {PLAYER} being\l"
	.string "invited to the moon!$"

MossdeepCity_SpaceCenter_Pad_Scientist1_Text_5:
	.string "Well if it isn't Professor Birch.\p"
	.string "Pleasure to see you, sir.$"

MossdeepCity_SpaceCenter_Pad_Scientist1_Text_6:
	.string "You didn't think you were just gonna go\n"
	.string "up and leave to space without saying\l"
	.string "goodbye, did you?\p"
	.string "I'm so proud of you {PLAYER}! Your\n"
	.string "father also sends his best wishes too.\l"
	.string "Go get 'em!$"

MossdeepCity_SpaceCenter_Pad_Scientist1_Text_7:
	.string "I wish I got the chance to come with\n"
	.string "you.\p"
	.string "Give it your all and good luck with your\n"
	.string "mission!\p"
	.string "We will be watching the news coverage\n"
	.string "and waiting for you back down here at\l"
	.string "home!\p"
	.string "I hope you uncover the mystery of the\n"
	.string "Millennium Comet!$"

MossdeepCity_SpaceCenter_Pad_Scientist1_Text_8:
	.string "I'm sure there will be a next time\n"
	.string "Professor. You're always welcome.$"

MossdeepCity_SpaceCenter_Pad_Scientist1_Text_9:
	.string "Alright {PLAYER}.\p"
	.string "It's time to board the space shuttle.\n"
	.string "Please follow us.$"

MossdeepCity_SpaceCenter_Pad_PrepareTakeOff_Text_0:
	.string "Good luck and farewell {PLAYER}!$"

MossdeepCity_SpaceCenter_Pad_PrepareTakeOff_Text_1:
	.string "T-minus-5...\p"
	.string "4...\p"
	.string "3...\p"
	.string "2...\p"
	.string "1...\p"
	.string "Lift off!$"

MossdeepCity_SpaceCenter_Pad_RocketTakeOff_Text_0:
	.string "After a number of long days in space\n"
	.string "flight...$"

MossdeepCity_SpaceCenter_Pad_LandingIn_Text_0:
	.string "Successfully landed home safely!$"

MossdeepCity_SpaceCenter_Pad_LandingIn_Text_1:
	.string "We've returned in one piece {PLAYER}!\p"
	.string "The landing party should be here any\n"
	.string "moment to take us back.$"

MossdeepCity_SpaceCenter_Pad_LandingIn_Text_2:
	.string "In fact.\p"
	.string "Here they are now!$"

MossdeepCity_SpaceCenter_Pad_LandingIn_Text_3:
	.string "Welcome home {PLAYER}. Enjoy your\n"
	.string "trip?$"

MossdeepCity_SpaceCenter_Pad_LandingIn_Text_4:
	.string "Aha! Mr. Stone himself! A pleasure to\n"
	.string "see you again.$"

MossdeepCity_SpaceCenter_Pad_LandingIn_Text_5:
	.string "Hope you all had a safe journey back.\p"
	.string "I've seen the footage that you\n"
	.string "transmitted.\p"
	.string "{PLAYER}.\p"
	.string "You have exceeded all our\n"
	.string "expectations.\l"
	.string "That was a once in a millennia\l"
	.string "encounter, and you pulled it off in\l"
	.string "style.\p"
	.string "Anyway, let's get you lot aboard and\n"
	.string "back to the space center!\p"
	.string "Shall we?$"
