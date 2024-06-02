Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route119_WeatherInstitute_1F_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
	.byte 0

Route119_WeatherInstitute_1F_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS, Route119_WeatherInstitute_1F_MapScripts_MAP_SCRIPT_ON_LOAD_2
	clearflag FLAG_TEMP_A
Route119_WeatherInstitute_1F_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	goto_if_set FLAG_JIRACHI_WISH_PERFECT_BIDOOF, Route119_WeatherInstitute_1F_MapScripts_MAP_SCRIPT_ON_LOAD_7
Route119_WeatherInstitute_1F_MapScripts_MAP_SCRIPT_ON_LOAD_6:
	setflag FLAG_TEMP_B
	return

Route119_WeatherInstitute_1F_MapScripts_MAP_SCRIPT_ON_LOAD_2:
	setflag FLAG_TEMP_A
	goto Route119_WeatherInstitute_1F_MapScripts_MAP_SCRIPT_ON_LOAD_1

Route119_WeatherInstitute_1F_MapScripts_MAP_SCRIPT_ON_LOAD_5:
	playbgm MUS_MT_CHIMNEY, TRUE
	clearflag FLAG_TEMP_B
	return

Route119_WeatherInstitute_1F_MapScripts_MAP_SCRIPT_ON_LOAD_7:
	goto_if_unset FLAG_TRAVELLED_TO_EASTERN_ISLAND, Route119_WeatherInstitute_1F_MapScripts_MAP_SCRIPT_ON_LOAD_5
	goto Route119_WeatherInstitute_1F_MapScripts_MAP_SCRIPT_ON_LOAD_6


Route119_WeatherInstitute_1F_OnTransition::
	compare VAR_WEATHER_INSTITUTE_STATE, 0
	goto_if_eq Route119_WeatherInstitute_1F_OnTransition_1
	return

Route119_WeatherInstitute_1F_OnTransition_1:
	call Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
	return


Route119_WeatherInstitute_1F_EastIslandMan::
	lock
	faceplayer
	msgbox Route119_WeatherInstitute_1F_EastIslandMan_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route119_WeatherInstitute_1F_EastIslandMan_2
Route119_WeatherInstitute_1F_EastIslandMan_1:
	release
	return

Route119_WeatherInstitute_1F_EastIslandMan_2:
	msgbox Route119_WeatherInstitute_1F_EastIslandMan_Text_1, MSGBOX_NPC
	closemessage
	applymovementplayerfacing 6, Route119_WeatherInstitute_1F_EastIslandMan_MoveForPlayer_Left, Route119_WeatherInstitute_1F_EastIslandMan_MoveForPlayer_Left, Route119_WeatherInstitute_1F_EastIslandMan_MoveForPlayer_Right, Route119_WeatherInstitute_1F_EastIslandMan_MoveForPlayer_Left
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkForward
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	warp MAP_ROUTE119_WEATHER_INSTITUTE_2F, 0
	waitstate
	goto Route119_WeatherInstitute_1F_EastIslandMan_1


Route119_WeatherInstitute_1F_EastIslandMan_MoveForPlayer_Left:
	walk_left
	face_right
	step_end

Route119_WeatherInstitute_1F_EastIslandMan_MoveForPlayer_Right:
	walk_right
	face_left
	step_end

.set LOCALID_LITTLE_BOY, 5

@ Route119_WeatherInstitute_1F_MapScripts::
@ 	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
@ 	.byte 0

@ Route119_WeatherInstitute_1F_OnTransition:
@ 	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
@ 	end

Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
	setobjectxyperm LOCALID_LITTLE_BOY, 0, 5
	setobjectmovementtype LOCALID_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_1F_EventScript_LittleBoy::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_1F_EventScript_StudyingRain::
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
	end

Route119_WeatherInstitute_1F_EventScript_Bed::
	lockall
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

Route119_WeatherInstitute_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_1F_Text_Grunt1Intro:
	.string "The BOSS got interested in\n"
	.string "the research they have going here,\l"
	.string "so he sent us out.\p"
	.string "You quit meddling!$"

Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
	.string "Blast it…\n"
	.string "Blasted by a kid…$"

Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
	.string "Our BOSS knows everything.\p"
	.string "But I'm just a GRUNT. What would I know\n"
	.string "about what he's thinking?$"

Route119_WeatherInstitute_1F_Text_Grunt4Intro:
	.string "Huh?\n"
	.string "What's a kid doing here?$"

Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
	.string "Huh?\n"
	.string "I lost?!$"

Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
	.string "Oh, no…\n"
	.string "I'll catch an earful for losing to a kid…\p"
	.string "I should just take a nap in the bed…$"

Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
	.string "While I was sleeping, everyone went\n"
	.string "upstairs!$"

Route119_WeatherInstitute_1F_Text_WowYoureStrong:
	.string "Wow, you're really strong!\p"
	.string "I wish I could be a POKéMON TRAINER\n"
	.string "like you!$"

Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
	.string "The PROFESSOR loves rain.\n"
	.string "That's a fact.\p"
	.string "But if it keeps raining, people will be in\n"
	.string "trouble. That's another fact.\p"
	.string "And thus, the PROFESSOR is studying\n"
	.string "if the rain can be put to good use.$"

Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
	.string "On the 2nd floor of the INSTITUTE,\n"
	.string "we study the weather patterns over\l"
	.string "the HOENN region.\p"
	.string "We've been noticing temporary and\n"
	.string "isolated cases of droughts and\l"
	.string "heavy rain lately…$"

Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
	.string "Hello!\n"
	.string "We've been saved by your actions!\p"
	.string "What I don't understand is what on\n"
	.string "earth the AQUAS were up to.$"

Route119_WeatherInstitute_1F_Text_TakeRestInBed:
	.string "There's a bed…\n"
	.string "Let's take a rest.$"

Route119_WeatherInstitute_1F_EastIslandMan_Text_0:
	.string "Good to see you.\p"
	.string "Everyone is upstairs preparing for\n"
	.string "their investigation into the massive\l"
	.string "energy fluctuations.\p"
	.string "Are you ready to head up and join them?$"

Route119_WeatherInstitute_1F_EastIslandMan_Text_1:
	.string "Good luck!$"
