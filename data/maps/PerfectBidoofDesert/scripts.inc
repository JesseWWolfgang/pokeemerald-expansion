PerfectBidoofDesert_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PerfectBidoofDesert_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

PerfectBidoofDesert_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_CAUGHT_PERFECT_BIDOOF, PerfectBidoofDesert_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	clearflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	return

PerfectBidoofDesert_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	return


PerfectBidoofDesert_GoBack::
	lockall
	msgbox PerfectBidoofDesert_GoBack_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkBackward
	waitmovement 0
	releaseall
	return


PerfectBidoofDesert_Perfect_Bidoof::
	lock
	faceplayer
	waitse
	playse SE_M_THUNDERBOLT
	fadescreenspeed FADE_TO_WHITE, 0
	fadescreenspeed FADE_FROM_WHITE, 16
	waitse
	playse SE_M_CONFUSE_RAY
	setweather WEATHER_SHADE
	doweather
	special Script_FadeOutMapMusic
	delay 30
	msgbox PerfectBidoofDesert_Perfect_Bidoof_Text_0, MSGBOX_DEFAULT
	messageveryslowprint PerfectBidoofDesert_Perfect_Bidoof_Text_1
	waitmessage
	delay 90
	closemessage
	delay 40
	playmoncry SPECIES_BIDOOF, CRY_MODE_ECHO_START
	delay 10
	playmoncry SPECIES_BIDOOF, CRY_MODE_ECHO_END
	delay 60
	waitmoncry
	setflag FLAG_FORCE_SHINY
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 3, 0, 0, 3, 0, 0
	setwildbattle SPECIES_BIDOOF_PERFECT, 70
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_FORCE_SHINY
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, PerfectBidoofDesert_Perfect_Bidoof_3
	case B_OUTCOME_RAN, PerfectBidoofDesert_Perfect_Bidoof_4
	msgbox PerfectBidoofDesert_Perfect_Bidoof_Text_3, MSGBOX_DEFAULT
PerfectBidoofDesert_Perfect_Bidoof_1:
	setweather WEATHER_SANDSTORM
	doweather
	releaseall
	return

PerfectBidoofDesert_Perfect_Bidoof_3:
	setflag FLAG_CAUGHT_PERFECT_BIDOOF
	setflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	call Common_EventScript_RemoveStaticPokemon
	special Overworld_PlaySpecialMapMusic
	goto PerfectBidoofDesert_Perfect_Bidoof_1

PerfectBidoofDesert_Perfect_Bidoof_4:
	msgbox PerfectBidoofDesert_Perfect_Bidoof_Text_2, MSGBOX_DEFAULT
	goto PerfectBidoofDesert_Perfect_Bidoof_1


PerfectBidoofDesert_GoHome::
	lock
	warpwhitefade MAP_MOSSDEEP_CITY_SPACE_CENTER_1F, 7, 3
	waitstate
	release
	return


PerfectBidoofDesert_GoBack_Text_0:
	.string "Going any further is too dangerous. I\n"
	.string "must turn back.$"

PerfectBidoofDesert_Perfect_Bidoof_Text_0:
	.string "At last.\p"
	.string "We are reunited.\p"
	.string "I have been searching for you for so\n"
	.string "long.\p"
	.string "Come. Let us become the very best...$"

PerfectBidoofDesert_Perfect_Bidoof_Text_1:
	.string "Like no one ever was...$"

PerfectBidoofDesert_Perfect_Bidoof_Text_2:
	.string "Do not fear me.\p"
	.string "I live only to sate your bloodthirst.$"

PerfectBidoofDesert_Perfect_Bidoof_Text_3:
	.string "Why do you resist?\p"
	.string "Do not fear me.$"
