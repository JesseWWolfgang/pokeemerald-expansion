MossdeepCity_SpaceCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_SpaceCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_SpaceCenter_1F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_SpaceCenter_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

MossdeepCity_SpaceCenter_1F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_TEMP_LOADED, 0, MossdeepCity_SpaceCenter_1F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

MossdeepCity_SpaceCenter_1F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
	setvar VAR_TEMP_LOADED, 1
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 7
	goto_if_eq MossdeepCity_SpaceCenter_1F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_2
	return

MossdeepCity_SpaceCenter_1F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_1:
	call MossdeepCity_SpaceCenter_1F_ReturnedFromSpaceSetup
	return

MossdeepCity_SpaceCenter_1F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_2:
	compare VAR_TEMP_1, 4
	goto_if_eq MossdeepCity_SpaceCenter_1F_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0_1
	return

MossdeepCity_SpaceCenter_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_LOADED, 1, MossdeepCity_SpaceCenter_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

MossdeepCity_SpaceCenter_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	setvar VAR_TEMP_LOADED, 2
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 7
	goto_if_eq MossdeepCity_SpaceCenter_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2
	return

MossdeepCity_SpaceCenter_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
	call MossdeepCity_SpaceCenter_1F_ReturnedFromSpace
	return

MossdeepCity_SpaceCenter_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2:
	compare VAR_TEMP_1, 4
	goto_if_eq MossdeepCity_SpaceCenter_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1
	return


MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter::
	lock
	faceplayer
	goto_if_set FLAG_TALKED_TO_WHITE_ROCK, MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter_2
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring STR_VAR_1, VAR_RESULT
	call_if_eq VAR_RESULT, 0, MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet
	call_if_ge VAR_RESULT, 1, MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter_2:
	goto_if_set FLAG_SPOKEN_ABOUT_MILLENNIUM_COMET, MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter_5
	call MossdeepCity_SpaceCenter_1F_ShowWhiteRock
MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter_4:
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter_5:
	call MossdeepCity_SpaceCenter_1F_ReadyForSpace
	goto MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter_4


MossdeepCity_SpaceCenter_1F_ShowWhiteRock::
	setflag FLAG_SPOKEN_ABOUT_MILLENNIUM_COMET
	buffernumberstring STR_VAR_1, 100
	call MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	msgbox MossdeepCity_SpaceCenter_1F_ShowWhiteRock_Text_0, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	applymovement 2, Common_Movement_FaceRight
	waitmovement 0
	waitse
	delay 20
	applymovement 2, MossdeepCity_SpaceCenter_1F_Scientist2ApproachPlayer
	waitmovement 0
	setvar VAR_TARGET_OBJECT_EVENT, 2
	compare VAR_FACING, DIR_EAST
	goto_if_eq MossdeepCity_SpaceCenter_1F_ShowWhiteRock_2
	compare VAR_FACING, DIR_WEST
	goto_if_eq MossdeepCity_SpaceCenter_1F_ShowWhiteRock_3
MossdeepCity_SpaceCenter_1F_ShowWhiteRock_1:
	applymovement 2, Common_Movement_WalkRight
	waitmovement 2
	waitmovement OBJ_EVENT_ID_PLAYER
	playerfaceobject 2
	faceobject 1, 2
	delay 20
	msgbox MossdeepCity_SpaceCenter_1F_ShowWhiteRock_Text_1, MSGBOX_DEFAULT
	objectfaceplayer 2
	msgbox MossdeepCity_SpaceCenter_1F_ShowWhiteRock_Text_2, MSGBOX_DEFAULT
	delay 20
	objectfaceplayer 1
	playerfaceobject 1
	applymovement 1, Common_Movement_WalkInPlace
	waitmovement 0
	delay 20
	msgbox MossdeepCity_SpaceCenter_1F_ShowWhiteRock_Text_3, MSGBOX_DEFAULT
	delay 20
	applymovement 2, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playerfaceobject 2
	delay 20
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq MossdeepCity_SpaceCenter_1F_ShowWhiteRock_7
	msgbox MossdeepCity_SpaceCenter_1F_ShowWhiteRock_Text_5, MSGBOX_DEFAULT
MossdeepCity_SpaceCenter_1F_ShowWhiteRock_6:
	msgbox MossdeepCity_SpaceCenter_1F_ShowWhiteRock_Text_6, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MossdeepCity_SpaceCenter_1F_ShowWhiteRock_10
	msgbox MossdeepCity_SpaceCenter_1F_ShowWhiteRock_Text_8, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_ShowWhiteRock_2:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	goto MossdeepCity_SpaceCenter_1F_ShowWhiteRock_1

MossdeepCity_SpaceCenter_1F_ShowWhiteRock_3:
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_SpaceCenter_1F_PlayerMoveToScientist2
	goto MossdeepCity_SpaceCenter_1F_ShowWhiteRock_1

MossdeepCity_SpaceCenter_1F_ShowWhiteRock_7:
	msgbox MossdeepCity_SpaceCenter_1F_ShowWhiteRock_Text_4, MSGBOX_DEFAULT
	goto MossdeepCity_SpaceCenter_1F_ShowWhiteRock_6

MossdeepCity_SpaceCenter_1F_ShowWhiteRock_10:
	msgbox MossdeepCity_SpaceCenter_1F_ShowWhiteRock_Text_7, MSGBOX_DEFAULT
	return


MossdeepCity_SpaceCenter_1F_Scientist2ApproachPlayer:
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_SpaceCenter_1F_PlayerMoveForScientist2:
	walk_down
	face_object
	step_end

MossdeepCity_SpaceCenter_1F_PlayerMoveToScientist2:
	walk_down
	walk_left
	step_end

MossdeepCity_SpaceCenter_1F_ReadyForSpace::
	msgbox MossdeepCity_SpaceCenter_1F_ReadyForSpace_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MossdeepCity_SpaceCenter_1F_ReadyForSpace_2
	msgbox MossdeepCity_SpaceCenter_1F_ReadyForSpace_Text_2, MSGBOX_DEFAULT
	warpdirection DIR_NORTH, MAP_MOSSDEEP_CITY_SPACE_CENTER_PAD, 0
	waitstate
	return

MossdeepCity_SpaceCenter_1F_ReadyForSpace_2:
	msgbox MossdeepCity_SpaceCenter_1F_ReadyForSpace_Text_1, MSGBOX_DEFAULT
	return


MossdeepCity_SpaceCenter_1F_ReturnedFromSpaceSetup::
	clearflag FLAG_TEMP_1
	goto_if_set FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN, MossdeepCity_SpaceCenter_1F_ReturnedFromSpaceSetup_2
MossdeepCity_SpaceCenter_1F_ReturnedFromSpaceSetup_1:
	setobjectxy 11, 8, 2
	setobjectxy 2, 6, 2
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject 11, DIR_SOUTH
	turnobject 2, DIR_SOUTH
	turnobject 1, DIR_SOUTH
	turnobject 4, DIR_WEST
	turnobject 3, DIR_NORTH
	return

MossdeepCity_SpaceCenter_1F_ReturnedFromSpaceSetup_2:
	setflag FLAG_TEMP_1
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	addobject 11
	goto MossdeepCity_SpaceCenter_1F_ReturnedFromSpaceSetup_1


MossdeepCity_SpaceCenter_1F_ReturnedFromSpace::
	lockall
	msgbox MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement 11, Common_Movement_WalkInPlace
	waitmovement 0
	goto_if_set FLAG_JIRACHI_WISH_PERFECT_BIDOOF, MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_2
	msgbox MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_2, MSGBOX_DEFAULT
MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_1:
	closemessage
	delay 20
	applymovement 1, Common_Movement_WalkInPlace
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_3, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement 2, MossdeepCity_SpaceCenter_1F_Scientist2GivePlayerGift
	waitmovement 0
	delay 30
	giveitem ITEM_BEAST_BALL, 20
	giveitem ITEM_ABILITY_PATCH, 3
	giveitem ITEM_LOADED_DICE
	closemessage
	delay 20
	applymovement 2, MossdeepCity_SpaceCenter_1F_Scientist2MoveBackAfterGift
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_4, MSGBOX_DEFAULT
	closemessage
	goto_if_set FLAG_JIRACHI_WISH_PERFECT_BIDOOF, MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_6
MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_5:
	goto_if_set FLAG_TEMP_1, MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_9
MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_8:
	warp MAP_MOSSDEEP_CITY_SPACE_CENTER_1F, 7, 3
	waitstate
	release
	return

MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_2:
	msgbox MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_1, MSGBOX_DEFAULT
	goto MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_1

MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_6:
	fadeoutbgm 0
	playse SE_PIN
	applymovement 4, MossdeepCity_SpaceCenter_1F_OldManTalkOnPhone
	waitmovement 0
	delay 90
	applymovement 4, MossdeepCity_SpaceCenter_1F_OldManMentionsHighEnergy
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_5, MSGBOX_DEFAULT
	closemessage
	delay 8
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject 11, DIR_EAST
	turnobject 2, DIR_EAST
	turnobject 1, DIR_EAST
	applymovement 4, Common_Movement_WalkInPlace
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_6, MSGBOX_DEFAULT
	closemessage
	applymovement 2, Common_Movement_WalkInPlace
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_7, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_WalkInPlace
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_8, MSGBOX_DEFAULT
	closemessage
	applymovement 11, Common_Movement_WalkInPlace
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_9, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_WalkInPlace
	waitmovement 0
	msgbox MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_10, MSGBOX_DEFAULT
	closemessage
	applymovement 11, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playerfaceobject 11
	msgbox MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_11, MSGBOX_DEFAULT
	closemessage
	turnobject 11, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_12, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement 11, MossdeepCity_SpaceCenter_1F_StevenConfused
	waitmovement 0
	playerfaceobject 11
	msgbox MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_13, MSGBOX_DEFAULT
	closemessage
	fadeinbgm 0
	goto MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_5

MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_9:
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	goto MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_8


MossdeepCity_SpaceCenter_1F_Scientist2GivePlayerGift:
	walk_down
	walk_right
	walk_in_place_down
	step_end

MossdeepCity_SpaceCenter_1F_Scientist2MoveBackAfterGift:
	walk_left
	walk_up
	walk_in_place_down
	step_end

MossdeepCity_SpaceCenter_1F_OldManTalkOnPhone:
	face_up
	emote_exclamation_mark
	step_end

MossdeepCity_SpaceCenter_1F_OldManMentionsHighEnergy:
	walk_down
	walk_left
	step_end

MossdeepCity_SpaceCenter_1F_StevenConfused:
	face_down
	emote_question_mark
	step_end

.set LOCALID_SCIENTIST_1, 1
.set LOCALID_SCIENTIST_2, 2
.set LOCALID_SAILOR, 3
.set LOCALID_OLD_MAN, 4
.set LOCALID_WOMAN, 5
.set LOCALID_STAIR_GRUNT, 9

MossdeepCity_SpaceCenter_1F_OnTransition:
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveObjectsForTeamMagma::
	setobjectxyperm LOCALID_SAILOR, 1, 9
	setobjectmovementtype LOCALID_SAILOR, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_WOMAN, 0, 8
	setobjectmovementtype LOCALID_WOMAN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_OLD_MAN, 1, 6
	setobjectmovementtype LOCALID_OLD_MAN, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_SCIENTIST_1, 3, 4
	setobjectmovementtype LOCALID_SCIENTIST_1, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_SCIENTIST_2, MOVEMENT_TYPE_FACE_RIGHT
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 1, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown
	goto_if_eq VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3, MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardLeft::
	setobjectxyperm LOCALID_STAIR_GRUNT, 12, 2
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardDown::
	setobjectxyperm LOCALID_STAIR_GRUNT, 13, 3
	end

@ Functionally unused. See comment on MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
MossdeepCity_SpaceCenter_1F_EventScript_MoveStairGuardRight::
	setobjectxyperm LOCALID_STAIR_GRUNT, 14, 2
	end

MossdeepCity_SpaceCenter_1F_OnLoad:
	goto_if_le VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote
	end

MossdeepCity_SpaceCenter_1F_EventScript_SetMagmaNote::
	setmetatile 2, 5, METATILE_Facility_DataPad, TRUE
	return

@ MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounter::
@ 	lock
@ 	faceplayer
@ 	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma
@ 	dotimebasedevents
@ 	specialvar VAR_RESULT, GetWeekCount
@ 	buffernumberstring STR_VAR_1, VAR_RESULT
@ 	call_if_eq VAR_RESULT, 0, MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet
@ 	call_if_ge VAR_RESULT, 1, MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber
@ 	closemessage
@ 	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
@ 	waitmovement 0
@ 	release
@ 	end

MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYet::
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumber::
	msgbox MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_RocketLaunchCounterMagma::
	dotimebasedevents
	specialvar VAR_RESULT, GetWeekCount
	buffernumberstring STR_VAR_1, VAR_RESULT
	call_if_eq VAR_RESULT, 0, MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma
	call_if_ge VAR_RESULT, 1, MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_NoLaunchesYetMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_ShowLaunchNumberMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber, MSGBOX_DEFAULT
	return

MossdeepCity_SpaceCenter_1F_EventScript_Scientist::
	lock
	faceplayer
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_ScientistMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_SunStoneMan::
	lock
	faceplayer
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone
	msgbox MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_SUN_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStone::
	msgbox MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_SunStoneManMagma::
	goto_if_set FLAG_RECEIVED_SUN_STONE_MOSSDEEP, MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_SUN_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_GaveSunStoneMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal
	goto MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_WomanNormal::
	msgbox MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_WomanMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
	goto_if_eq VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
	goto_if_lt VAR_MOSSDEEP_CITY_STATE, 2, MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal
	goto MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldManNormal::
	msgbox MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_OldManMagma::
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Steven::
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_MagmaNote::
	lockall
	msgbox MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_3, MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_1, MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SPACE_CENTER_4, MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro, MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt2::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F, MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_2, MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat
	setflag FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F
	copyobjectxytoperm LOCALID_STAIR_GRUNT
	switch VAR_FACING
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest
#ifdef BUGFIX
	case DIR_EAST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
#else
	case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast
#endif
	applymovement LOCALID_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 2
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_Grunt2Defeated::
	msgbox MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest::
	applymovement LOCALID_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 1
	release
	end

@ Functionally unused by mistake. The movement is handled anyway after the switch (see above)
@ This also means VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE can never be 3
MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast::
	applymovement LOCALID_STAIR_GRUNT, MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast
	waitmovement 0
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3
	release
	end

MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

@ Functionally unused. See above
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

@ This was meant to only handle the player facing North, but by mistake(?) it also handles the player facing East
MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs:
	face_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

MossdeepCity_SpaceCenter_1F_Text_RocketLaunchImminent:
	.string "The rocket's launch is imminent!$"

MossdeepCity_SpaceCenter_1F_Text_SuccessfulLaunchNumber:
	.string "The rocket launched safely!\n"
	.string "That's successful launch no. {STR_VAR_1}!$"

MossdeepCity_SpaceCenter_1F_Text_HaywireButRocketLaunchImminent:
	.string "I know that things are a little\n"
	.string "haywire right now, but…\p"
	.string "The rocket's launch is imminent!$"

MossdeepCity_SpaceCenter_1F_Text_HaywireButSuccessfulLaunchNumber:
	.string "I know that things are a little\n"
	.string "haywire right now, but…\p"
	.string "The rocket launched safely!\n"
	.string "That's successful launch no. {STR_VAR_1}!$"

MossdeepCity_SpaceCenter_1F_Text_RocketLaunchDemandsPerfection:
	.string "A rocket launch demands perfection.\n"
	.string "Not even a 1% margin of error is allowed.\p"
	.string "Even if it's 99% okay, the whole thing\n"
	.string "is useless if 1% happens to be no good.\p"
	.string "Despite that, we never stop trying.\n"
	.string "Why? It's a dream that never ends.$"

MossdeepCity_SpaceCenter_1F_Text_MagmaHaveSightsOnSpaceCenter:
	.string "Those MAGMA thugs have their sights\n"
	.string "set on our SPACE CENTER.\p"
	.string "But we can't allow anything that minor\n"
	.string "to interfere with our rocket launch!$"

MossdeepCity_SpaceCenter_1F_Text_FoundThisYouCanHaveIt:
	.string "I was taking a stroll down the beach\n"
	.string "when I found this.\p"
	.string "It's not anything I need, so you can\n"
	.string "have it.$"

MossdeepCity_SpaceCenter_1F_Text_HoennFamousForMeteorShowers:
	.string "The HOENN region has been famous for \n"
	.string "its meteor showers for a long time.$"

MossdeepCity_SpaceCenter_1F_Text_MagmaCantStealFuelTakeThis:
	.string "TEAM MAGMA can't be allowed to steal\n"
	.string "the rocket fuel.\p"
	.string "Oh, by the way, you can have this stone\n"
	.string "I found on the beach.$"

MossdeepCity_SpaceCenter_1F_Text_CantStrollOnBeachWithMagma:
	.string "With TEAM MAGMA around, I guess\n"
	.string "strolls on the beach aren't safe.$"

MossdeepCity_SpaceCenter_1F_Text_DidPokemonComeFromSpace:
	.string "Some people claim that POKéMON came\n"
	.string "from space. Could it be true?$"

MossdeepCity_SpaceCenter_1F_Text_AquaShouldBeatMagma:
	.string "TEAM AQUA should take care of\n"
	.string "TEAM MAGMA!\p"
	.string "But if they did that, TEAM AQUA will\n"
	.string "become bold and brazen, won't they?$"

MossdeepCity_SpaceCenter_1F_Text_RocketsBoggleMyMind:
	.string "A giant chunk of metal bursts through\n"
	.string "the skies and flies into space…\p"
	.string "It boggles my mind!$"

MossdeepCity_SpaceCenter_1F_Text_MagmaWantsToSpoilMyDream:
	.string "A giant chunk of metal bursts through\n"
	.string "the skies and flies into space…\p"
	.string "But TEAM MAGMA wants to spoil\n"
	.string "that dream of mine!\p"
	.string "I'm not having any of that!$"

MossdeepCity_SpaceCenter_1F_Text_StevenMagmaCantBeAllowedToTakeFuel:
	.string "STEVEN: {PLAYER}{KUN}, have you read that\n"
	.string "proclamation already?\p"
	.string "TEAM MAGMA is coming after the rocket\n"
	.string "fuel on this island.\p"
	.string "I don't know what they'd need it for,\n"
	.string "but they can't be allowed to take it.\p"
	.string "I'll keep an eye on things for\n"
	.string "a while longer.\p"
	.string "In the meantime, why don't you go\n"
	.string "check out the town?$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3Intro:
	.string "As promised, we've come for\n"
	.string "the rocket fuel!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3Defeat:
	.string "Ran out of fuel…$"

MossdeepCity_SpaceCenter_1F_Text_Grunt3PostBattle:
	.string "Don't think you're on a roll just\n"
	.string "because you've beaten me!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1Intro:
	.string "We gave you fair warning!\n"
	.string "There's nothing sneaky about us!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1Defeat:
	.string "Grrr…\n"
	.string "We should've used sneaky treachery…$"

MossdeepCity_SpaceCenter_1F_Text_Grunt1PostBattle:
	.string "Okay, I get it already! The next time,\n"
	.string "we'll come unannounced.$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4Intro:
	.string "The rocket fuel the SPACE CENTER has\n"
	.string "in storage--that's what we're after.\p"
	.string "We mean to take every last bit of it!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4Defeat:
	.string "Please, can you spare some fuel?\n"
	.string "Even a chintzy cup will do!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt4PostBattle:
	.string "What are we going to do with\n"
	.string "the rocket fuel?\p"
	.string "How would I know?\n"
	.string "Ask our leader upstairs!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2Intro:
	.string "Our leader said no one, but no one,\n"
	.string "gets past me!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2Defeat:
	.string "Ack! Ack! Aaack!$"

MossdeepCity_SpaceCenter_1F_Text_Grunt2PostBattle:
	.string "Please, tell our leader that\n"
	.string "I never abandoned my post.\l"
	.string "That I stayed to the bitter end…$"

MossdeepCity_SpaceCenter_1F_Text_MagmaIntentToStealNotice:
	.string "This is…\n"
	.string "An intent-to-steal notice?\p"
	.string "“To the staff of the SPACE CENTER:\n"
	.string "How are you? We are doing fine.\p"
	.string "“We will soon visit you to take your\n"
	.string "rocket fuel.\p"
	.string "“Please don't try to stop us.\n"
	.string "We will take the fuel no matter what.\p"
	.string "“Let there be more land!\n"
	.string "                                          TEAM MAGMA”$"

MossdeepCity_SpaceCenter_1F_ShowWhiteRock_Text_0:
	.string "Is that... a piece of the white rock just\n"
	.string "outside the space center?\p"
	.string "It's not? Goodness it is remarkably\n"
	.string "similar!\p"
	.string "This is incredible, these stones are\n"
	.string "very special to us here.\p"
	.string "They are small fragments of the\n"
	.string "Millennium Comet, a pure-white comet\l"
	.string "that is seen for only a single week\l"
	.string "every thousand years.\p"
	.string "You might have heard this is due to\n"
	.string "happen very soon.\p"
	.string "You've seen it on TV right?\p"
	.string "The Milennium Festival where the comet\n"
	.string "is visible at night is being prepared in\l"
	.string "the coming weeks...$"

MossdeepCity_SpaceCenter_1F_ShowWhiteRock_Text_1:
	.string "I couldn't help but overhear you pair\n"
	.string "talking about the Millennium Comet.\p"
	.string "We have performed many geological\n"
	.string "studies on the white rock here in\l"
	.string "Mossdeep.\p"
	.string "No other fragments have ever been\n"
	.string "reported showing up on Earth except\l"
	.string "the one right here.$"

MossdeepCity_SpaceCenter_1F_ShowWhiteRock_Text_2:
	.string "And now of course this one you have\n"
	.string "right here...\p"
	.string "To deepen the mystery, we also\n"
	.string "discovered minerals in the white rock\l"
	.string "that we have never identified in any\l"
	.string "other recorded comet.\p"
	.string "Many of us here at the space center\n"
	.string "believe that the Millennium Comet is\l"
	.string "something very special.$"

MossdeepCity_SpaceCenter_1F_ShowWhiteRock_Text_3:
	.string "Showing up right here at the space\n"
	.string "center now of all times is very\l"
	.string "bizarre...\p"
	.string "With the festival just around the\n"
	.string "corner, the 100th successful rocket\l"
	.string "launch, and the comet approaching very\l"
	.string "soon...\p"
	.string "I think it can't just be a coincidence.\p"
	.string ".........\p"
	.string "The comet is due to pass very close to\n"
	.string "our moon in about 2 weeks time.\p"
	.string "You should join the spacecraft crew on\n"
	.string "their next journey to the moon for the\l"
	.string "event.\p"
	.string "I'm not kidding either, this is truly a\n"
	.string "once in a lifetime opportunity to try\l"
	.string "and unravel the secrets the comet\l"
	.string "must hold.\p"
	.string "It must either be destiny that brought\n"
	.string "you here today, or a long held wish from\l"
	.string "the cosmos...$"

MossdeepCity_SpaceCenter_1F_ShowWhiteRock_Text_4:
	.string "What do you say young man?$"

MossdeepCity_SpaceCenter_1F_ShowWhiteRock_Text_5:
	.string "What do you say young lady?$"

MossdeepCity_SpaceCenter_1F_ShowWhiteRock_Text_6:
	.string "Would you like to join the crew on the\n"
	.string "next expedition to the moon?$"

MossdeepCity_SpaceCenter_1F_ShowWhiteRock_Text_7:
	.string "You will be able to help us out with some\n"
	.string "incredible research. You should be\l"
	.string "proud!\p"
	.string "Our team will help arrange the\n"
	.string "paperwork and prepare you for space\l"
	.string "travel.\p"
	.string "Please return here as soon as you are\n"
	.string "ready for take-off.$"

MossdeepCity_SpaceCenter_1F_ShowWhiteRock_Text_8:
	.string "I understand. It's a huge decision to\n"
	.string "make, travelling into space. Think it\l"
	.string "over and come back and talk to us if\l"
	.string "you decide to join.$"

MossdeepCity_SpaceCenter_1F_ReadyForSpace_Text_0:
	.string "Have you prepared yourself for the trip\n"
	.string "to the moon?\p"
	.string "Once we take off, we won't be returning\n"
	.string "until we have completed the expedition\l"
	.string "or the mission is cancelled.\p"
	.string "Additionally, we will have NO connection\n"
	.string "to the Pokémon Storage System, so\l"
	.string "make sure you have your best team with\l"
	.string "you.\p"
	.string "Are you ready?$"

MossdeepCity_SpaceCenter_1F_ReadyForSpace_Text_1:
	.string "Please get yourself ready and return\n"
	.string "ASAP, you won't want to miss this.$"

MossdeepCity_SpaceCenter_1F_ReadyForSpace_Text_2:
	.string "I will go and find one of our guides,\n"
	.string "they will show you to the launch pad.\l"
	.string "Please wait here a moment.$"

MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_0:
	.string "Well done {PLAYER} on a successful\n"
	.string "mission!\p"
	.string "You played an instrumental role in our\n"
	.string "research, proving beyond a shadow of a\l"
	.string "doubt that the Millennium Comet holds\l"
	.string "amazing secrets.$"

MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_1:
	.string "Take good care of that Jirachi\n"
	.string "{PLAYER}.\p"
	.string "I hope your wish comes true.\l"
	.string "I'm certain it will.$"

MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_2:
	.string "Take good care of that Jirachi\n"
	.string "{PLAYER}.\p"
	.string "I could see in the footage, your wish\n"
	.string "was beautiful.\l"
	.string "Cherish that moment.$"

MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_3:
	.string "We at the institute have a few gifts\n"
	.string "for you to commemorate this\l"
	.string "significant achievement,\l"
	.string "and of course, as a personal thank-you\l"
	.string "from us...$"

MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_4:
	.string "I hope you get some good use out of\n"
	.string "these.\p"
	.string "We will get back to our usual business\n"
	.string "after a well-deserved rest.\p"
	.string "Thank you again {PLAYER}.\l"
	.string "We hope to see you around.$"

MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_5:
	.string "Very sorry to interrupt...$"

MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_6:
	.string "I've just received an urgent message\n"
	.string "from the weather institute.\p"
	.string "A few minutes ago, radars started\n"
	.string "recording unprecedented levels of\l"
	.string "energy radiating from a landmass to\l"
	.string "the far east of Hoenn.$"

MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_7:
	.string "Is that so? Is it a powerful weather\n"
	.string "system?$"

MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_8:
	.string "No it doesn't appear so. They said it's\n"
	.string "manifesting as intense fluctuations in\l"
	.string "heat and magnetism.\p"
	.string "That's not all.\l"
	.string "The landmass it originates from\l"
	.string "consists mainly of a harsh desert.\p"
	.string "It's restricted by governments as it is\n"
	.string "completely uninhabitable for humans\l"
	.string "and most foreign Pokémon.$"

MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_9:
	.string "I'm going to presume that we will be\n"
	.string "sending out a team of researchers?$"

MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_10:
	.string "Naturally.\n"
	.string "We are coordinating with the weather\l"
	.string "institute and assembling a team to\l"
	.string "travel there.$"

MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_11:
	.string "This sounds like another opportunity\n"
	.string "{PLAYER}!\p"
	.string "You were the good luck charm for the\n"
	.string "Space Center on their mission, and it\l"
	.string "was a flawless success.\p"
	.string "Why not do the same for the Weather\n"
	.string "Institute?$"

MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_12:
	.string "They would appreciate your presence on\n"
	.string "this mission {PLAYER}.\p"
	.string "Steven could be right you know. Why\n"
	.string "don't you go and pay the Weather\l"
	.string "Institute a visit? Do it soon, I'm sure\l"
	.string "they will be preparing as we speak.$"

MossdeepCity_SpaceCenter_1F_ReturnedFromSpace_Text_13:
	.string "This can't be just a coincedence...\p"
	.string "Perhaps this is your wish coming to\n"
	.string "fruition...?$"
