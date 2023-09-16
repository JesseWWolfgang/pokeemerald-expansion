CasteliaCity_CafeSonata_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CasteliaCity_CafeSonata_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

CasteliaCity_CafeSonata_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	hideobjectat 6, MAP_CASTELIA_CITY_CAFE_SONATA
	goto_if_set FLAG_CAPTURED_MELOETTA, CasteliaCity_CafeSonata_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	goto_if_unset FLAG_RELIC_SONG_PLAYED, CasteliaCity_CafeSonata_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	clearflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	return

CasteliaCity_CafeSonata_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	return


CafeSonata_Bard::
	lock
	faceplayer
	goto_if_set FLAG_RELIC_SONG_PLAYED, CafeSonata_Bard_2
	msgbox CafeSonata_Bard_Text_0, MSGBOX_NPC
	special Script_FadeOutMapMusic
	switch VAR_FACING
	case DIR_EAST, CafeSonata_Bard_6
	case DIR_WEST, CafeSonata_Bard_7
	applymovement OBJ_EVENT_ID_PLAYER, CafeSonata_WalkToSong_FacingNorth
CafeSonata_Bard_4:
	waitmovement 0
	delay 30
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, CafeSonata_Song_CameraUp
	waitmovement 0
	delay 20
	call CafeSonata_PlaySong
	applymovement OBJ_EVENT_ID_CAMERA, CafeSonata_Song_CameraDown
	waitmovement 0
	delay 20
	special RemoveCameraObject
	special Overworld_PlaySpecialMapMusic
	release
	return

CafeSonata_Bard_2:
	release
	return

CafeSonata_Bard_6:
	applymovement OBJ_EVENT_ID_PLAYER, CafeSonata_WalkToSong_FacingEast
	goto CafeSonata_Bard_4

CafeSonata_Bard_7:
	applymovement OBJ_EVENT_ID_PLAYER, CafeSonata_WalkToSong_FacingWest
	goto CafeSonata_Bard_4


CafeSonata_PlaySong::
	setflag FLAG_RELIC_SONG_PLAYED
	clearflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	addobject 2
	showobjectat 2, MAP_CASTELIA_CITY_CAFE_SONATA
	setobjectxy 2, 4, 1
	lockelevation 2, 4
	playbgm MUS_CAFE_SONATA_RELIC_SONG, FALSE
	applymovement 1, CafeSonata_Song_Bard
	delay 80
	applymovement 2, CafeSonata_Song_MeloettaDance_1
	waitmovement 2
	fadescreen FADE_TO_WHITE
	hideobjectat 2, MAP_CASTELIA_CITY_CAFE_SONATA
	addobject 6, MAP_CASTELIA_CITY_CAFE_SONATA
	showobjectat 6, MAP_CASTELIA_CITY_CAFE_SONATA
	setobjectxy 6, 2, 8
	lockelevation 6, 4
	dofieldeffectsparkle 2, 7, 1
	dofieldeffectsparkle 2, 8, 1
	dofieldeffectsparkle 2, 9, 1
	dofieldeffectsparkle 3, 7, 1
	dofieldeffectsparkle 2, 9, 1
	fadescreen FADE_FROM_WHITE
	applymovement 6, CafeSonata_Song_MeloettaDance_2
	waitmovement 6
	fadescreen FADE_TO_WHITE
	hideobjectat 6, MAP_CASTELIA_CITY_CAFE_SONATA
	showobjectat 2, MAP_CASTELIA_CITY_CAFE_SONATA
	setobjectxy 2, 2, 10
	lockelevation 2, 4
	dofieldeffectsparkle 2, 9, 1
	dofieldeffectsparkle 2, 10, 1
	dofieldeffectsparkle 2, 11, 1
	dofieldeffectsparkle 3, 9, 1
	dofieldeffectsparkle 2, 11, 1
	fadescreen FADE_FROM_WHITE
	applymovement 2, CafeSonata_Song_MeloettaDance_3
	waitmovement 2
	resetelevation 2
	delay 120
	return


CafeSonata_WalkToSong_FacingEast:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	face_up
	step_end

CafeSonata_WalkToSong_FacingNorth:
	walk_down
	walk_down
	walk_down
	walk_down
	face_up
	step_end

CafeSonata_WalkToSong_FacingWest:
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	face_up
	step_end

CafeSonata_Song_CameraUp:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

CafeSonata_Song_CameraDown:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

CafeSonata_Song_Bard:
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	walk_in_place_slow_down
	step_end

CafeSonata_Song_MeloettaDance_1:
	levitate
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	lock_facing_direction
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	force_face_up
	force_face_right
	force_face_down
	force_face_left
	walk_slow_diag_northeast
	walk_slow_diag_southeast
	walk_slow_diag_southwest
	walk_slow_left
	walk_slow_left
	walk_slow_diag_northwest
	walk_slow_up
	walk_diag_northeast
	walk_right
	walk_right
	walk_right
	walk_diag_southeast
	walk_down
	walk_diag_southwest
	walk_diag_southwest
	walk_left
	walk_left
	walk_diag_northwest
	walk_diag_northwest
	walk_up
	walk_diag_northeast
	walk_diag_northeast
	walk_fast_right
	walk_fast_right
	walk_diag_southeast
	walk_diag_southeast
	walk_down
	walk_down
	walk_diag_southwest
	walk_diag_southwest
	walk_fast_left
	walk_fast_left
	walk_diag_northwest
	walk_diag_northwest
	walk_up
	walk_up
	walk_diag_northeast
	unlock_facing_direction
	stop_levitate
	step_end

CafeSonata_Song_MeloettaDance_2:
	lock_facing_direction
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_right
	levitate
	delay_16
	stop_levitate
	walk_fast_down
	walk_fast_diag_southwest
	walk_fast_down
	walk_down
	levitate
	delay_16
	stop_levitate
	walk_fast_diag_northwest
	walk_fast_up
	walk_diag_northwest
	levitate
	delay_16
	stop_levitate
	walk_fast_left
	walk_fast_left
	walk_diag_southwest
	levitate
	delay_16
	stop_levitate
	walk_fast_diag_southeast
	walk_fast_right
	walk_right
	levitate
	delay_16
	stop_levitate
	walk_fast_diag_northeast
	walk_fast_right
	walk_diag_northeast
	levitate
	delay_16
	stop_levitate
	walk_fast_diag_southwest
	walk_fast_down
	walk_down
	levitate
	delay_16
	stop_levitate
	walk_fast_diag_northwest
	walk_fast_left
	walk_diag_northwest
	levitate
	delay_16
	stop_levitate
	unlock_facing_direction
	step_end

CafeSonata_Song_MeloettaDance_3:
	levitate
	lock_facing_direction
	walk_fast_up
	walk_fast_diag_northeast
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_diag_southeast
	walk_fast_down
	walk_fast_diag_southwest
	walk_fast_diag_southwest
	walk_fast_left
	walk_fast_left
	walk_fast_diag_northwest
	walk_fast_diag_northwest
	walk_fast_up
	walk_fast_diag_northeast
	walk_fast_diag_northeast
	walk_fast_right
	walk_fast_right
	walk_fast_diag_southeast
	walk_fast_diag_southeast
	walk_fast_down
	walk_fast_down
	walk_fast_diag_southwest
	walk_fast_diag_southwest
	walk_fast_left
	walk_fast_left
	walk_fast_diag_northwest
	walk_fast_diag_northwest
	walk_fast_up
	walk_fast_up
	walk_diag_northeast
	walk_right
	walk_slow_diag_southeast
	walk_slow_down
	unlock_facing_direction
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	stop_levitate
	step_end

CafeSonata_Meloetta::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MELOETTA, CRY_MODE_ENCOUNTER
	msgbox CafeSonata_Meloetta_Text_0, MSGBOX_NPC
	delay 20
	waitmoncry
	setwildbattle SPECIES_MELOETTA, 40
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, CafeSonata_Meloetta_3
	case B_OUTCOME_RAN, CafeSonata_Meloetta_4
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject 2
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox CafeSonata_Meloetta_Text_2, MSGBOX_DEFAULT
CafeSonata_Meloetta_1:
	release
	end

CafeSonata_Meloetta_3:
	setflag FLAG_CAPTURED_VICTINI
	setflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	call Common_EventScript_RemoveStaticPokemon
	goto CafeSonata_Meloetta_1

CafeSonata_Meloetta_4:
	msgbox CafeSonata_Meloetta_Text_1, MSGBOX_DEFAULT
	goto CafeSonata_Meloetta_1


CafeSonata_Bard_Text_0:
	.string "The scent you brought me reminded me\n"
	.string "of a long-ago melody from the fringes\l"
	.string "of my sepia-toned memories.\p"
	.string "It was a song my mother loved...\n"
	.string "It makes me feel so nostalgic.\p"
	.string "Would you like to hear the melody?$"

CafeSonata_Meloetta_Text_0:
	.string "Ta-ta-ta-tah!$"

CafeSonata_Meloetta_Text_1:
	.string "Meloetta is watching carefully.$"

CafeSonata_Meloetta_Text_2:
	.string "Meloetta fled behind the furniture...$"
