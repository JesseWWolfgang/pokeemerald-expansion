CasteliaCity_CafeSonata_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CasteliaCity_CafeSonata_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

CasteliaCity_CafeSonata_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	hideobjectat 6, MAP_CASTELIA_CITY_CAFE_SONATA
	goto_if_set FLAG_CAUGHT_MELOETTA, CasteliaCity_CafeSonata_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	goto_if_unset FLAG_RELIC_SONG_PLAYED, CasteliaCity_CafeSonata_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	clearflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	return

CasteliaCity_CafeSonata_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	return


CafeSonata_Bard::
	lock
	faceplayer
	goto_if_set FLAG_CAUGHT_MELOETTA, CafeSonata_Bard_2
	goto_if_set FLAG_RELIC_SONG_PLAYED, CafeSonata_Bard_3
	call CafeSonata_Bard_NotCaughtMeloetta
CafeSonata_Bard_1:
	release
	return

CafeSonata_Bard_2:
	call CafeSonata_Bard_CaughtMeloetta
	goto CafeSonata_Bard_1

CafeSonata_Bard_3:
	msgbox CafeSonata_Bard_RememberedMelody, MSGBOX_NPC
	goto CafeSonata_Bard_1


CafeSonata_Bard_CaughtMeloetta::
	msgbox CafeSonata_Bard_CaughtMeloetta_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq CafeSonata_Bard_CaughtMeloetta_1
	return

CafeSonata_Bard_CaughtMeloetta_1:
	setvar VAR_0x8005, MOVE_RELIC_SONG
	call MoveTutor_EventScript_OpenPartyMenu
	return


CafeSonata_Bard_NotCaughtMeloetta::
	msgbox CafeSonata_Bard_NotCaughtMeloetta_Text_0, MSGBOX_NPC
	special Script_FadeOutMapMusic
	switch VAR_FACING
	case DIR_EAST, CafeSonata_Bard_NotCaughtMeloetta_3
	case DIR_WEST, CafeSonata_Bard_NotCaughtMeloetta_4
	applymovement OBJ_EVENT_ID_PLAYER, CafeSonata_WalkToSong_FacingNorth
CafeSonata_Bard_NotCaughtMeloetta_1:
	waitmovement 0
	delay 30
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, CafeSonata_Song_CameraUp
	waitmovement 0
	delay 20
	call CafeSonata_PlaySong
	fadeoutbgm 0
	applymovement OBJ_EVENT_ID_CAMERA, CafeSonata_Song_CameraFocusBard
	waitmovement 0
	delay 20
	msgbox CafeSonata_Bard_RememberedMelody, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, CafeSonata_Song_CameraDown
	waitmovement 0
	special RemoveCameraObject
	special Overworld_PlaySpecialMapMusic
	delay 30
	return

CafeSonata_Bard_NotCaughtMeloetta_3:
	applymovement OBJ_EVENT_ID_PLAYER, CafeSonata_WalkToSong_FacingEast
	goto CafeSonata_Bard_NotCaughtMeloetta_1

CafeSonata_Bard_NotCaughtMeloetta_4:
	applymovement OBJ_EVENT_ID_PLAYER, CafeSonata_WalkToSong_FacingWest
	goto CafeSonata_Bard_NotCaughtMeloetta_1


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

CafeSonata_Song_CameraFocusBard:
	walk_slow_up
	step_end

CafeSonata_Song_CameraDown:
	walk_slow_down
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
	force_face_left
	walk_slow_diag_northeast
	force_face_up
	walk_slow_diag_southeast
	force_face_right
	walk_slow_diag_southwest
	force_face_down
	walk_slow_left
	force_face_left
	walk_slow_left
	force_face_up
	walk_slow_diag_northwest
	force_face_right
	walk_slow_up
	force_face_down
	walk_diag_northeast
	walk_right
	force_face_left
	walk_right
	walk_right
	force_face_up
	walk_diag_southeast
	walk_down
	force_face_right
	walk_diag_southwest
	walk_diag_southwest
	force_face_down
	walk_left
	walk_left
	force_face_left
	walk_diag_northwest
	walk_diag_northwest
	force_face_up
	walk_up
	walk_diag_northeast
	force_face_right
	walk_diag_northeast
	walk_fast_right
	force_face_down
	walk_fast_right
	walk_fast_diag_southeast
	force_face_left
	walk_diag_southeast
	walk_down
	force_face_up
	walk_down
	walk_diag_southwest
	force_face_right
	walk_fast_diag_southwest
	walk_fast_left
	force_face_down
	walk_fast_left
	walk_fast_diag_northwest
	force_face_left
	walk_diag_northwest
	walk_up
	force_face_up
	walk_up
	walk_diag_northeast
	force_face_right
	unlock_facing_direction
	stop_levitate
	step_end

CafeSonata_Song_MeloettaDance_2:
	lock_facing_direction
	force_face_down
	walk_right
	walk_fast_right
	force_face_left
	walk_fast_right
	walk_right
	force_face_up
	levitate
	delay_16
	stop_levitate
	walk_down
	walk_fast_diag_southwest
	force_face_right
	walk_fast_down
	walk_down
	force_face_down
	levitate
	delay_16
	stop_levitate
	walk_diag_northwest
	walk_fast_up
	force_face_left
	walk_diag_northwest
	levitate
	delay_16
	stop_levitate
	walk_left
	force_face_up
	walk_fast_left
	walk_diag_southwest
	force_face_right
	levitate
	delay_16
	stop_levitate
	walk_diag_southeast
	walk_fast_right
	force_face_down
	walk_right
	levitate
	delay_16
	stop_levitate
	walk_diag_northeast
	walk_fast_right
	force_face_left
	walk_diag_northeast
	levitate
	delay_16
	stop_levitate
	walk_diag_southwest
	force_face_up
	walk_fast_down
	walk_down
	force_face_right
	levitate
	delay_16
	stop_levitate
	walk_diag_northwest
	walk_fast_left
	force_face_down
	walk_diag_northwest
	levitate
	delay_16
	stop_levitate
	unlock_facing_direction
	step_end

CafeSonata_Song_MeloettaDance_3:
	levitate
	lock_facing_direction
	force_face_down
	walk_up
	walk_fast_diag_northeast
	force_face_left
	walk_fast_right
	walk_fast_right
	force_face_up
	walk_fast_right
	walk_fast_diag_southeast
	force_face_right
	walk_down
	walk_diag_southwest
	force_face_down
	walk_fast_diag_southwest
	walk_fast_left
	force_face_left
	walk_fast_left
	walk_fast_diag_northwest
	force_face_up
	walk_diag_northwest
	walk_up
	force_face_right
	walk_diag_northeast
	walk_fast_diag_northeast
	force_face_down
	walk_fast_right
	walk_fast_right
	force_face_left
	walk_fast_diag_southeast
	walk_diag_southeast
	force_face_up
	walk_down
	walk_down
	force_face_right
	walk_diag_southwest
	walk_fast_diag_southwest
	force_face_down
	walk_fast_left
	walk_fast_left
	force_face_left
	walk_fast_diag_northwest
	walk_fast_diag_northwest
	force_face_up
	walk_up
	walk_up
	force_face_right
	walk_diag_northeast
	walk_right
	force_face_down
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
	setwildbattle SPECIES_MELOETTA, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, CafeSonata_Meloetta_3
	case B_OUTCOME_RAN, CafeSonata_Meloetta_4
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject 2
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox CafeSonata_Meloetta_Text_3, MSGBOX_DEFAULT
CafeSonata_Meloetta_1:
	release
	end

CafeSonata_Meloetta_3:
	setflag FLAG_CAUGHT_MELOETTA
	setflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	applymovement 1, Common_Movement_FaceDown
	waitmovement 0
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 20
	applymovementplayerfacing OBJ_EVENT_ID_PLAYER, CafeSonata_Song_WalkToBard_FacingNorth, CafeSonata_Song_WalkToBard_FacingSouth, CafeSonata_Song_WalkToBard_FacingEast, CafeSonata_Song_WalkToBard_FacingWest
	waitmovement 0
	msgbox CafeSonata_Meloetta_Text_1, MSGBOX_NPC
	goto CafeSonata_Meloetta_1

CafeSonata_Meloetta_4:
	msgbox CafeSonata_Meloetta_Text_2, MSGBOX_DEFAULT
	goto CafeSonata_Meloetta_1


CafeSonata_Song_WalkToBard_FacingNorth:
	walk_up
	walk_up
	step_end

CafeSonata_Song_WalkToBard_FacingSouth:
	face_up
	step_end

CafeSonata_Song_WalkToBard_FacingEast:
	walk_right
	walk_up
	step_end

CafeSonata_Song_WalkToBard_FacingWest:
	walk_left
	walk_up
	step_end

CafeSonata_ManAtBar::
	msgbox CafeSonata_ManAtBar_Text_0, MSGBOX_NPC
	return


CafeSonata_TableMan::
	msgbox CafeSonata_TableMan_Text_0, MSGBOX_NPC
	return


CafeSonata_Barista::
	lock
	faceplayer
	msgbox CafeSonata_Barista_Text_0, MSGBOX_DEFAULT
	pokemart CafeSonata_Mart
	release
	return


	.align 2
CafeSonata_Mart:
	.2byte ITEM_LEMONADE
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_BERRY_JUICE
	.2byte ITEM_BIG_MALASADA
	.2byte ITEM_PP_MAX
	.2byte ITEM_EXP_CANDY_XS
	.2byte ITEM_EXP_CANDY_S
	.2byte ITEM_EXP_CANDY_M
	.2byte ITEM_EXP_CANDY_L
	.2byte ITEM_EXP_CANDY_XL
	.2byte ITEM_MICLE_BERRY
	.2byte ITEM_CUSTAP_BERRY
	.2byte ITEM_JABOCA_BERRY
	.2byte ITEM_ROWAP_BERRY
	.2byte ITEM_KEE_BERRY
	.2byte ITEM_MARANGA_BERRY
	.2byte ITEM_NONE

CafeSonata_Bard_CaughtMeloetta_Text_0:
	.string "Let it sing the Relic Song.\p"
	.string "Aria Forme will become Pirouette Forme and vice versa.\p"
	.string "Want me to teach the Relic Song?$"

CafeSonata_Bard_NotCaughtMeloetta_Text_0:
	.string "The scent you brought me reminded me of a long-ago melody from the fringes of my sepia-toned memories.\p"
	.string "It was a song my mother loved...\n"
	.string "It makes me feel so nostalgic.\p"
	.string "Would you like to hear the melody?$"

CafeSonata_Meloetta_Text_0:
	.string "Aouueoeaa-{EMOJI_NOTE}$"

CafeSonata_Meloetta_Text_1:
	.string "My mother once told me of a Pokémon that played a melody and danced so lightly that it filled people's hearts with joy.\p"
	.string "Then sorrow darkened the entire world, and the Pokémon lost the melody...\p"
	.string "Also, at that time, some red shoes were lost somewhere...$"

CafeSonata_Meloetta_Text_2:
	.string "Meloetta is watching carefully.$"

CafeSonata_Meloetta_Text_3:
	.string "Meloetta fled the café...$"

CafeSonata_ManAtBar_Text_0:
	.string "When I listen to his guitar, it reminds me of leaving home for the first time, and the tears of farewell my mother cried...$"

CafeSonata_TableMan_Text_0:
	.string "After a tiring day of work, this café is a perfect spot to let your mind relax.$"

CafeSonata_Barista_Text_0:
	.string "You came all the way here.\n"
	.string "Enjoy...$"

CafeSonata_Bard_RememberedMelody::
	.string "When you came through the door, I remembered the melody!\p"
	.string "And the Pokémon that had forgotten how to dance began to step lightly once more!\p"
	.string "You are the inspiration.\n"
	.string "You are a mysterious child...$"
