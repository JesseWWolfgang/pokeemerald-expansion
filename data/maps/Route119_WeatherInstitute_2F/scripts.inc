Route119_WeatherInstitute_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route119_WeatherInstitute_2F_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route119_WeatherInstitute_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Route119_WeatherInstitute_2F_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_JIRACHI_WISH_PERFECT_BIDOOF, Route119_WeatherInstitute_2F_MapScripts_MAP_SCRIPT_ON_LOAD_2
	return

Route119_WeatherInstitute_2F_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	playbgm MUS_MT_CHIMNEY, TRUE
	return

Route119_WeatherInstitute_2F_MapScripts_MAP_SCRIPT_ON_LOAD_2:
	goto_if_unset FLAG_TRAVELLED_TO_EASTERN_ISLAND, Route119_WeatherInstitute_2F_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

Route119_WeatherInstitute_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_LOADED, 0, Route119_WeatherInstitute_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

Route119_WeatherInstitute_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	setvar VAR_TEMP_LOADED, 1
	goto_if_set FLAG_JIRACHI_WISH_PERFECT_BIDOOF, Route119_WeatherInstitute_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2
	return

Route119_WeatherInstitute_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1:
	call Route119_WeatherInstitute_2F_BeginEastIslandScene
	return

Route119_WeatherInstitute_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_2:
	goto_if_unset FLAG_TRAVELLED_TO_EASTERN_ISLAND, Route119_WeatherInstitute_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_1
	return


Route119_WeatherInstitute_2F_OnTransition::
	setflag FLAG_TEMP_A
	switch VAR_WEATHER_INSTITUTE_STATE
	case 0, Route119_WeatherInstitute_2F_OnTransition_3
	case 1, Route119_WeatherInstitute_2F_OnTransition_4
Route119_WeatherInstitute_2F_OnTransition_1:
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_OnTransition_6
Route119_WeatherInstitute_2F_OnTransition_5:
	goto_if_set FLAG_JIRACHI_WISH_PERFECT_BIDOOF, Route119_WeatherInstitute_2F_OnTransition_9
	return

Route119_WeatherInstitute_2F_OnTransition_3:
	call Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere
	goto Route119_WeatherInstitute_2F_OnTransition_1

Route119_WeatherInstitute_2F_OnTransition_4:
	call Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone
	goto Route119_WeatherInstitute_2F_OnTransition_1

Route119_WeatherInstitute_2F_OnTransition_6:
	call Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear
	goto Route119_WeatherInstitute_2F_OnTransition_5

Route119_WeatherInstitute_2F_OnTransition_8:
	call Route119_WeatherInstitute_2F_SetActorsForIslandExpedition
	return

Route119_WeatherInstitute_2F_OnTransition_9:
	goto_if_unset FLAG_TRAVELLED_TO_EASTERN_ISLAND, Route119_WeatherInstitute_2F_OnTransition_8
	return


Route119_WeatherInstitute_2F_SetActorsForIslandExpedition::
	clearflag FLAG_TEMP_A
	setobjectxyperm 5, 10, 4
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_LEFT
	return


Route119_WeatherInstitute_2F_BeginEastIslandScene::
	lockall
	delay 10
	objectfaceplayer 9
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	delay 30
	applymovement 9, Common_Movement_WalkRight
	waitmovement 0
	playerfaceobject 9
	msgbox Route119_WeatherInstitute_2F_BeginEastIslandScene_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement 9, Common_Movement_WalkLeft
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_PlayerWalkToEastIslandTable
	waitmovement OBJ_EVENT_ID_PLAYER
	objectfaceplayer 5
	msgbox Route119_WeatherInstitute_2F_BeginEastIslandScene_Text_1, MSGBOX_DEFAULT
	closemessage
	applymovement 13, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playerfaceobject 13
	msgbox Route119_WeatherInstitute_2F_BeginEastIslandScene_Text_2, MSGBOX_DEFAULT
	closemessage
	applymovement 5, Common_Movement_WalkInPlace
	waitmovement 0
	playerfaceobject 5
	msgbox Route119_WeatherInstitute_2F_BeginEastIslandScene_Text_3, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement 10, Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	playerfaceobject 10
	faceobject 5, 10
	faceobject 13, 10
	msgbox Route119_WeatherInstitute_2F_BeginEastIslandScene_Text_4, MSGBOX_DEFAULT
	closemessage
	objectfaceplayer 5
	playerfaceobject 5
	faceobject 13, 5
	msgbox Route119_WeatherInstitute_2F_BeginEastIslandScene_Text_5, MSGBOX_DEFAULT
	closemessage
	warp MAP_PERFECT_BIDOOF_DESERT, 0
	waitstate
	return


Route119_WeatherInstitute_2F_PlayerWalkToEastIslandTable:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	face_left
	step_end

.set LOCALID_GRUNT_1, 1
.set LOCALID_GRUNT_2, 2
.set LOCALID_SHELLY, 3
.set LOCALID_SCIENTIST, 5
.set LOCALID_GRUNT_3, 7
.set LOCALID_GRUNT_4, 8

@ Route119_WeatherInstitute_2F_OnTransition:
@ 	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere
@ 	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone
@ 	call_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear
@ 	end

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere::
	setobjectxyperm LOCALID_SCIENTIST, 1, 6
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone::
	setobjectxyperm LOCALID_SCIENTIST, 4, 6
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear::
	setobjectxyperm LOCALID_SCIENTIST, 2, 2
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_UP
	return

Route119_WeatherInstitute_2F_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_5, Route119_WeatherInstitute_2F_Text_Grunt5Intro, Route119_WeatherInstitute_2F_Text_Grunt5Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_2, Route119_WeatherInstitute_2F_Text_Grunt2Intro, Route119_WeatherInstitute_2F_Text_Grunt2Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_3, Route119_WeatherInstitute_2F_Text_Grunt3Intro, Route119_WeatherInstitute_2F_Text_Grunt3Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_WEATHER_INSTITUTE, Route119_WeatherInstitute_2F_Text_ShellyIntro, Route119_WeatherInstitute_2F_Text_ShellyDefeat, Route119_WeatherInstitute_2F_EventScript_ShellyDefeated
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_ShellyDefeated::
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_GRUNT_3
	applymovement LOCALID_GRUNT_3, Route119_WeatherInstitute_2F_Movement_GruntApproachShelly
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SHELLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SHELLY, Common_Movement_Delay48
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre, MSGBOX_DEFAULT
	closemessage
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_SHELLY
	removeobject LOCALID_GRUNT_4
	removeobject LOCALID_GRUNT_3
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_SCIENTIST, Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer
	waitmovement 0
	copyobjectxytoperm LOCALID_SCIENTIST
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastform::
	msgbox Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CASTFORM_NORMAL
	givemon SPECIES_CASTFORM_NORMAL, 25, ITEM_MYSTIC_WATER
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	end

Route119_WeatherInstitute_2F_EventScript_SendCastformToPC::
	call Common_EventScript_TransferredToPC
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM_NORMAL
	return

Route119_WeatherInstitute_2F_EventScript_ExplainCastform::
	msgbox Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_CASTFORM
	release
	end

Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather::
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather
	msgbox Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather::
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather  @ Both defeated
	call_if_unset FLAG_TEMP_2, Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather
	specialvar VAR_RESULT, GetAbnormalWeatherMapNameAndType
	goto_if_eq VAR_RESULT, 1, Route119_WeatherInstitute_2F_EventScript_KyogreWeather
	msgbox Route119_WeatherInstitute_2F_Text_GroudonWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_KyogreWeather::
	msgbox Route119_WeatherInstitute_2F_Text_KyogreWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather::
	special CreateAbnormalWeatherEvent
	setflag FLAG_TEMP_2
	return

Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather::
	msgbox Route119_WeatherInstitute_2F_Text_NoAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_Movement_GruntApproachShelly:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	ride_water_current_up
	walk_in_place_faster_down
	step_end

Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition:
	slide_down
	walk_in_place_faster_left
	step_end

Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer:
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_WeatherScientist::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_Text_Grunt2Intro:
	.string "The INSTITUTE created a type of\n"
	.string "POKéMON that has something to do with\l"
	.string "the weather. We're here to take them!$"

Route119_WeatherInstitute_2F_Text_Grunt2Defeat:
	.string "Our plan's being spoiled by a kid?$"

Route119_WeatherInstitute_2F_Text_Grunt2PostBattle:
	.string "If the POKéMON they made here can\n"
	.string "control the weather freely, then we of\l"
	.string "TEAM AQUA definitely need it!$"

Route119_WeatherInstitute_2F_Text_Grunt3Intro:
	.string "We're TEAM AQUA!\n"
	.string "We appear wherever anything rare is\l"
	.string "found!$"

Route119_WeatherInstitute_2F_Text_Grunt3Defeat:
	.string "You got me!$"

Route119_WeatherInstitute_2F_Text_Grunt3PostBattle:
	.string "You don't have any idea what we of\n"
	.string "TEAM AQUA are working towards!\l"
	.string "You stay out of our way!$"

Route119_WeatherInstitute_2F_Text_Grunt5Intro:
	.string "Don't tell me you're looking for that\n"
	.string "weather POKéMON, too?\p"
	.string "That's a no-no!\n"
	.string "We were here to get it first!$"

Route119_WeatherInstitute_2F_Text_Grunt5Defeat:
	.string "Oh, will you look at my POKéMON?$"

Route119_WeatherInstitute_2F_Text_Grunt5PostBattle:
	.string "Humph, so what?\n"
	.string "What we want…\p"
	.string "What we really want isn't here…\n"
	.string "Ihihihihi…$"

Route119_WeatherInstitute_2F_Text_ShellyIntro:
	.string "Ahahahaha!\p"
	.string "You're going to meddle in TEAM AQUA's\n"
	.string "affairs?\p"
	.string "You're either absolutely fearless,\n"
	.string "simply ignorant, or both!\p"
	.string "You're so cute, you're disgusting!\n"
	.string "I'll put you down, kiddy!$"

Route119_WeatherInstitute_2F_Text_ShellyDefeat:
	.string "Ahahahaha!\n"
	.string "You're disgustingly strong!$"

Route119_WeatherInstitute_2F_Text_ShellyPostBattle:
	.string "It's bad enough to have TEAM MAGMA\n"
	.string "blunder about, but now there's you!\p"
	.string "What makes you want to sniff around\n"
	.string "in our business, anyway?$"

Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy:
	.string "We have a situation here!\p"
	.string "A TEAM MAGMA mob just passed\n"
	.string "the WEATHER INSTITUTE.\p"
	.string "They appear to be headed for\n"
	.string "MT. PYRE!$"

Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre:
	.string "What?!\p"
	.string "We can't waste any more time here!\n"
	.string "We have to hurry to MT. PYRE, too!\p"
	.string "Ahahahaha!\n"
	.string "TEAM MAGMA, just you wait!$"

Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon:
	.string "Thanks!\n"
	.string "Thanks to you, we're safe!\p"
	.string "It might be an odd way of thanking you,\n"
	.string "but take this POKéMON.$"

@ Unused
Route119_WeatherInstitute_2F_Text_NoRoomForPokemon:
	.string "Hm? You don't seem to have any room\n"
	.string "for this POKéMON.$"

Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform:
	.string "{PLAYER} received CASTFORM!$"

Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather:
	.string "That POKéMON changes shape according\n"
	.string "to the weather conditions.\p"
	.string "There're plenty of them in the\n"
	.string "INSTITUTE--go ahead and take it.$"

Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous:
	.string "I've been researching rain for many\n"
	.string "years, but it's ridiculous to think that\l"
	.string "humans can freely change the weather.$"

Route119_WeatherInstitute_2F_Text_GroudonWeather:
	.string "I track weather patterns over\n"
	.string "the HOENN region.\p"
	.string "Presently, a drought has been recorded\n"
	.string "in {STR_VAR_1}.\p"
	.string "Could that mean, somewhere near\n"
	.string "{STR_VAR_1}…$"

Route119_WeatherInstitute_2F_Text_KyogreWeather:
	.string "I track weather patterns over\n"
	.string "the HOENN region.\p"
	.string "Presently, heavy rainfall has been\n"
	.string "recorded over {STR_VAR_1}.\p"
	.string "Could that mean, somewhere near\n"
	.string "{STR_VAR_1}…$"

Route119_WeatherInstitute_2F_Text_NoAbnormalWeather:
	.string "Abnormal weather conditions are\n"
	.string "no longer being reported.\p"
	.string "The occasional rainfall is a blessing,\n"
	.string "really.$"

Route119_WeatherInstitute_2F_BeginEastIslandScene_Text_0:
	.string "Hey, it's {PLAYER}! Welcome.\n"
	.string "We're in the midst of planning our\l"
	.string "investigation.\p"
	.string "Come over and take a look with us.$"

Route119_WeatherInstitute_2F_BeginEastIslandScene_Text_1:
	.string "Thanks for coming {PLAYER}. We are\n"
	.string "bound for a large island far east of\l"
	.string "the Hoenn region.\p"
	.string "It is named the Zenith Isle.\p"
	.string "The island is completely uninhabited by\n"
	.string "humans as governments forbid\l"
	.string "settlement there.\p"
	.string "This is primarily due to its harsh local\n"
	.string "climate and weather patterns.\l"
	.string "About 80% of the landmass is desert\l"
	.string "shrouded in perpetual sandstorms\l"
	.string "caused by tropical ocean wind.$"

Route119_WeatherInstitute_2F_BeginEastIslandScene_Text_2:
	.string "There are some rugged species of\n"
	.string "Pokémon that live there, so be careful.\l"
	.string "Thankfully, you already have the\l"
	.string "equipment necessary to traverse the\l"
	.string "island, so you will be part of the land\l"
	.string "team.$"

Route119_WeatherInstitute_2F_BeginEastIslandScene_Text_3:
	.string "If we take a seaplane, we can be at the\n"
	.string "shore within an hour of depature...\l"
	.string "but we will need to investigate further\l"
	.string "on foot.\p"
	.string "That is where you come in.\p"
	.string "Once there, you should explore into the\n"
	.string "desert and try to locate the origin of\l"
	.string "this phenomenon.$"

Route119_WeatherInstitute_2F_BeginEastIslandScene_Text_4:
	.string "Holy...!\p"
	.string "Guys, I'm detecting another huge spike\n"
	.string "of magnetism coming from the island\l"
	.string "again!\l"
	.string "That's the largest one I have seen yet.$"

Route119_WeatherInstitute_2F_BeginEastIslandScene_Text_5:
	.string "It's getting stronger...\p"
	.string "There's no time to lose {PLAYER}.\n"
	.string "Let's get our move on!$"
