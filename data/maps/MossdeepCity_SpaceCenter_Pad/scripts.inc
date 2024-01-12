MossdeepCity_SpaceCenter_Pad_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_LOAD:
	setflag FLAG_TEMP_1
	return

MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_LOADED, FALSE, MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	setvar VAR_TEMP_LOADED, TRUE
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 19
	goto_if_eq MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2
	return

MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
	call MossdeepCity_SpaceCenter_Pad_GuideLady_Entrance
	return

MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2:
	compare VAR_TEMP_1, 43
	goto_if_eq MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1
	return


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
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_Pad_PlayerBoardRocket
	messageautoscroll MossdeepCity_SpaceCenter_Pad_PrepareTakeOff_Text_0
	waitmovement 0
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
	warp MAP_LUNAR_SUMMIT, 0
	waitstate
	special RemoveCameraObject
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
	playse SE_EXIT
	delay 120
	msgbox MossdeepCity_SpaceCenter_Pad_RocketTakeOff_Text_0
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
	.string "Pleasure to see you sir.$"

MossdeepCity_SpaceCenter_Pad_Scientist1_Text_6:
	.string "You didn't think you were just gonna go\n"
	.string "up and leave to space without saying\l"
	.string "goodbye did you?\p"
	.string "I'm so proud of you {PLAYER}! Your\n"
	.string "father also sends his best wishes too.\l"
	.string "Go get em!$"

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
