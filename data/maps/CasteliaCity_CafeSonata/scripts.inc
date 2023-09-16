CasteliaCity_CafeSonata_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CasteliaCity_CafeSonata_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

CasteliaCity_CafeSonata_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_CAPTURED_VICTINI, CasteliaCity_CafeSonata_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	clearflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	return

CasteliaCity_CafeSonata_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	return


CafeSonata_Bard::
	lock
	faceplayer
	msgbox CafeSonata_Bard_Text_0, MSGBOX_NPC
	special Script_FadeOutMapMusic
	switch VAR_FACING
	case DIR_EAST, CafeSonata_Bard_3
	case DIR_WEST, CafeSonata_Bard_4
	applymovement OBJ_EVENT_ID_PLAYER, CafeSonata_WalkToSong_FacingNorth
CafeSonata_Bard_1:
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

CafeSonata_Bard_3:
	applymovement OBJ_EVENT_ID_PLAYER, CafeSonata_WalkToSong_FacingEast
	goto CafeSonata_Bard_1

CafeSonata_Bard_4:
	applymovement OBJ_EVENT_ID_PLAYER, CafeSonata_WalkToSong_FacingWest
	goto CafeSonata_Bard_1


CafeSonata_PlaySong::
	playbgm MUS_CAFE_SONATA_RELIC_SONG, FALSE
	applymovement 1, CafeSonata_Song_Bard
	applymovement 2, CafeSonata_Song_MeloettaLevitate
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
	step_end

CafeSonata_Song_MeloettaLevitate:
	levitate
	step_end

CafeSonata_MeloettaSong::
	return


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
