P2Laboratory_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, P2Laboratory_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, P2Laboratory_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

P2Laboratory_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_CAPTURED_GENESECT, P2Laboratory_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	goto_if_unset FLAG_DEFEATED_P2_SCIENTIST, P2Laboratory_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	clearflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	return

P2Laboratory_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	return

P2Laboratory_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_LOADED, 0, P2Laboratory_GenesectEvent
	.2byte 0


P2Laboratory_GenesectEvent::
	setvar VAR_TEMP_LOADED, 1
	lock
	delay 30
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, P2Laboratory_CameraMoveUp
	waitmovement 0
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	delay 45
	applymovement 1, Common_Movement_FaceDown
	waitmovement 0
	delay 45
	msgbox P2Laboratory_GenesectEvent_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, P2Laboratory_PlayerWalkToTalk
	applymovement 1, P2Laboratory_ScientistWalkToTalk
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement 1
	msgbox P2Laboratory_GenesectEvent_Text_1, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_WalkDown
	waitmovement 0
	msgbox P2Laboratory_GenesectEvent_Text_2, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_WalkDown
	waitmovement 0
	msgbox P2Laboratory_GenesectEvent_Text_3, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown
	waitmovement 1
	waitmovement OBJ_EVENT_ID_CAMERA
	msgbox P2Laboratory_GenesectEvent_Text_4, MSGBOX_DEFAULT
	closemessage
	special RemoveCameraObject
	call P2Laboratory_BattleScientist
	release
	return


P2Laboratory_BattleScientist::
	setflag FLAG_CUSTOM_BATTLE_MUSIC
	setvar VAR_TEMP_CUSTOM_BATTLE_MUSIC, MUS_UNOVA_VS_PLASMA
	trainerbattle_no_intro TRAINER_P2DUDLEY2, P2Laboratory_BattleScientist_Text_0
	msgbox P2Laboratory_BattleScientist_Text_1, MSGBOX_NPC
	applymovement 1, P2Laboratory_ScientistWalkUp
	waitmovement 0
	msgbox P2Laboratory_BattleScientist_Text_2, MSGBOX_NPC
	playse SE_BALL_THROW
	waitse
	playse SE_BALL_OPEN
	fadescreen FADE_TO_WHITE
	waitse
	setflag FLAG_DEFEATED_P2_SCIENTIST
	clearflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	showobjectat 2, MAP_P2LABORATORY
	fadescreen FADE_FROM_WHITE
	applymovement 1, P2Laboratory_ScientistWalkAway
	waitmovement 0
	return


P2Laboratory_Genesect::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GENESECT, CRY_MODE_ENCOUNTER
	msgbox P2Laboratory_Genesect_Text_0, MSGBOX_NPC
	delay 20
	waitmoncry
	setwildbattle SPECIES_GENESECT, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, P2Laboratory_Genesect_3
	case B_OUTCOME_RAN, P2Laboratory_Genesect_4
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject 2
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox P2Laboratory_Genesect_Text_2, MSGBOX_DEFAULT
P2Laboratory_Genesect_1:
	release
	end

P2Laboratory_Genesect_3:
	setflag FLAG_CAPTURED_GENESECT
	setflag FLAG_HIDE_SPECIAL_POKEMON_ON_MAP
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	goto P2Laboratory_Genesect_1

P2Laboratory_Genesect_4:
	msgbox P2Laboratory_Genesect_Text_1, MSGBOX_DEFAULT
	goto P2Laboratory_Genesect_1


P2Laboratory_CameraMoveUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

P2Laboratory_ScientistWalkToTalk:
	walk_right
	walk_right
	face_down
	step_end

P2Laboratory_PlayerWalkToTalk:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_up
	step_end

P2Laboratory_ScientistWalkUp:
	walk_up
	walk_up
	step_end

P2Laboratory_ScientistWalkAway:
	walk_up
	walk_left
	walk_left
	face_up
	step_end

P2Laboratory_GenesectEvent_Text_0:
	.string "Oh, it's that kid from before...$"

P2Laboratory_GenesectEvent_Text_1:
	.string "How did you find this place? We kept\n"
	.string "this entire route completely blocked\l"
	.string "off!\p"
	.string "The fact that you are here means you\n"
	.string "have come to stop whatever shady\l"
	.string "things I may or may not be doing here...$"

P2Laboratory_GenesectEvent_Text_2:
	.string "We, Team Plasma...\p"
	.string "...no, really it was I, the genius that I\n"
	.string "am, revived the ancient Pokémon\l"
	.string "Genesect from a fossil.\p"
	.string "Then we enhanced the Pokémon with the\n"
	.string "power of science!\p"
	.string "It is the strongest Pokémon in\n"
	.string "history!!$"

P2Laboratory_GenesectEvent_Text_3:
	.string "But, our lord N was not interested in\n"
	.string "this Genesect that was modified by the\l"
	.string "power of science!\p"
	.string "“Science damages the natural beauty of\n"
	.string "Pokémon! They're perfect beings!”\p"
	.string "That's what he said...\p"
	.string "So my research was halted, and this\n"
	.string "facility was closed...\p"
	.string "However!!\n"
	.string "The Genesect research is all mine!$"

P2Laboratory_GenesectEvent_Text_4:
	.string "So if you want to know Genesect's\n"
	.string "secret, you'll have to beat me in\l"
	.string "battle!\p"
	.string "At my full power!$"

P2Laboratory_BattleScientist_Text_0:
	.string "Oh!\nMy groundbreaking research...$"

P2Laboratory_BattleScientist_Text_1:
	.string "I've lost everything...\p"
	.string "I forgot my duty as a Scientist is to\n"
	.string "make the world happy.\p"
	.string "So, this must be what I get for trying\n"
	.string "to make a Pokémon into a tool for\l"
	.string "fighting...$"

P2Laboratory_BattleScientist_Text_2:
	.string "I'm going to wash my hands of this\n"
	.string "Genesect matter...\p"
	.string "I don't need this anymore...\n"
	.string "Do as you wish.$"

P2Laboratory_Genesect_Text_0:
	.string "GWEEEEOYUUU!$"

P2Laboratory_Genesect_Text_1:
	.string "Genesect is watching carefully.$"

P2Laboratory_Genesect_Text_2:
	.string "Genesect fled the laboratory...$"
