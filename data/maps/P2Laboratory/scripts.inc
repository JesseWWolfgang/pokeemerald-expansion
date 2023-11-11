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
	goto_if_set FLAG_DEFEATED_P2_SCIENTIST, P2Laboratory_GenesectEvent_2
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

P2Laboratory_GenesectEvent_2:
	end


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
	addobject 2
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
	call P2Laboratory_ScientistPostGenesectCapture
	goto P2Laboratory_Genesect_1

P2Laboratory_Genesect_4:
	msgbox P2Laboratory_Genesect_Text_1, MSGBOX_DEFAULT
	goto P2Laboratory_Genesect_1


P2Laboratory_ScientistPostGenesectCapture::
	applymovement 1, P2Laboratory_ScientistWalkToGiveDrive
	waitmovement 0
	playerfaceobject 1
	msgbox P2Laboratory_ScientistPostGenesectCapture_Text_0, MSGBOX_DEFAULT
	call P2Laboratory_ScientistGiveFirstDrive
	closemessage
	applymovement 1, P2Laboratory_ScientistWalkBackFromeGiveDrive
	waitmovement 0
	return


P2Laboratory_ScientistGiveFirstDrive::
	msgbox P2Laboratory_ScientistGiveFirstDrive_Text_0, MSGBOX_DEFAULT
	dynmultipush P2Laboratory_ScientistGiveFirstDrive_Text_1, ITEM_SHOCK_DRIVE
	dynmultipush P2Laboratory_ScientistGiveFirstDrive_Text_2, ITEM_BURN_DRIVE
	dynmultipush P2Laboratory_ScientistGiveFirstDrive_Text_3, ITEM_CHILL_DRIVE
	dynmultipush P2Laboratory_ScientistGiveFirstDrive_Text_4, ITEM_DOUSE_DRIVE
	dynmultistack 1, 1, TRUE, 4, FALSE, ITEM_SHOCK_DRIVE, DYN_MULTICHOICE_CB_SHOW_ITEM
	giveitem VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_eq P2Laboratory_ScientistGiveFirstDrive_1
	setflag FLAG_OBTAINED_GENESECT_DRIVE
	msgbox P2Laboratory_ScientistGiveFirstDrive_Text_6, MSGBOX_DEFAULT
	return

P2Laboratory_ScientistGiveFirstDrive_1:
	msgbox P2Laboratory_ScientistGiveFirstDrive_Text_5, MSGBOX_DEFAULT
	return


P2Laboratory_ScientistSwapDrive::
	setvar VAR_TEMP_0, ITEM_NONE
	checkitem ITEM_SHOCK_DRIVE
	compare VAR_RESULT, 0
	goto_if_ne P2Laboratory_ScientistSwapDrive_2
P2Laboratory_ScientistSwapDrive_1:
	checkitem ITEM_BURN_DRIVE
	compare VAR_RESULT, 0
	goto_if_ne P2Laboratory_ScientistSwapDrive_5
P2Laboratory_ScientistSwapDrive_4:
	checkitem ITEM_CHILL_DRIVE
	compare VAR_RESULT, 0
	goto_if_ne P2Laboratory_ScientistSwapDrive_8
P2Laboratory_ScientistSwapDrive_7:
	checkitem ITEM_DOUSE_DRIVE
	compare VAR_RESULT, 0
	goto_if_ne P2Laboratory_ScientistSwapDrive_11
P2Laboratory_ScientistSwapDrive_10:
	compare VAR_TEMP_0, ITEM_NONE
	goto_if_eq P2Laboratory_ScientistSwapDrive_14
	compare VAR_TEMP_0, ITEM_SHOCK_DRIVE
	goto_if_ne P2Laboratory_ScientistSwapDrive_17
P2Laboratory_ScientistSwapDrive_16:
	compare VAR_TEMP_0, ITEM_BURN_DRIVE
	goto_if_ne P2Laboratory_ScientistSwapDrive_20
P2Laboratory_ScientistSwapDrive_19:
	compare VAR_TEMP_0, ITEM_CHILL_DRIVE
	goto_if_ne P2Laboratory_ScientistSwapDrive_23
P2Laboratory_ScientistSwapDrive_22:
	compare VAR_TEMP_0, ITEM_DOUSE_DRIVE
	goto_if_ne P2Laboratory_ScientistSwapDrive_26
P2Laboratory_ScientistSwapDrive_25:
	dynmultipush P2Laboratory_ScientistSwapDrive_Text_1, ITEM_NONE
	msgbox P2Laboratory_ScientistSwapDrive_Text_2, MSGBOX_DEFAULT
	dynmultistack 1, 1, FALSE, 4, FALSE, ITEM_NONE, DYN_MULTICHOICE_CB_SHOW_ITEM
	switch VAR_RESULT
	case ITEM_NONE, P2Laboratory_ScientistSwapDrive_30
	case MULTI_B_PRESSED, P2Laboratory_ScientistSwapDrive_30
	copyvar VAR_TEMP_1, VAR_RESULT
	removeitem VAR_TEMP_0
	giveitem VAR_TEMP_1
	return

P2Laboratory_ScientistSwapDrive_2:
	setvar VAR_TEMP_0, ITEM_SHOCK_DRIVE
	goto P2Laboratory_ScientistSwapDrive_1

P2Laboratory_ScientistSwapDrive_5:
	setvar VAR_TEMP_0, ITEM_BURN_DRIVE
	goto P2Laboratory_ScientistSwapDrive_4

P2Laboratory_ScientistSwapDrive_8:
	setvar VAR_TEMP_0, ITEM_CHILL_DRIVE
	goto P2Laboratory_ScientistSwapDrive_7

P2Laboratory_ScientistSwapDrive_11:
	setvar VAR_TEMP_0, ITEM_DOUSE_DRIVE
	goto P2Laboratory_ScientistSwapDrive_10

P2Laboratory_ScientistSwapDrive_14:
	msgbox P2Laboratory_ScientistSwapDrive_Text_0, MSGBOX_DEFAULT
	return

P2Laboratory_ScientistSwapDrive_17:
	dynmultipush P2Laboratory_ScientistGiveFirstDrive_Text_1, ITEM_SHOCK_DRIVE
	goto P2Laboratory_ScientistSwapDrive_16

P2Laboratory_ScientistSwapDrive_20:
	dynmultipush P2Laboratory_ScientistGiveFirstDrive_Text_2, ITEM_BURN_DRIVE
	goto P2Laboratory_ScientistSwapDrive_19

P2Laboratory_ScientistSwapDrive_23:
	dynmultipush P2Laboratory_ScientistGiveFirstDrive_Text_3, ITEM_CHILL_DRIVE
	goto P2Laboratory_ScientistSwapDrive_22

P2Laboratory_ScientistSwapDrive_26:
	dynmultipush P2Laboratory_ScientistGiveFirstDrive_Text_4, ITEM_DOUSE_DRIVE
	goto P2Laboratory_ScientistSwapDrive_25

P2Laboratory_ScientistSwapDrive_30:
	return


P2Laboratory_Scientist::
	lock
	faceplayer
	goto_if_unset FLAG_CAPTURED_GENESECT, P2Laboratory_Scientist_2
	goto_if_set FLAG_OBTAINED_GENESECT_DRIVE, P2Laboratory_Scientist_5
	call P2Laboratory_ScientistGiveFirstDrive
P2Laboratory_Scientist_1:
	release
	return

P2Laboratory_Scientist_2:
	msgbox P2Laboratory_Scientist_Text_0
	goto P2Laboratory_Scientist_1

P2Laboratory_Scientist_5:
	call P2Laboratory_ScientistSwapDrive
	goto P2Laboratory_Scientist_1


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

P2Laboratory_ScientistWalkToGiveDrive:
	walk_right
	face_player
	step_end

P2Laboratory_ScientistWalkBackFromeGiveDrive:
	walk_left
	face_up
	step_end

P2Laboratory_GenesectEvent_Text_0:
	.string "Oh, it's that kid from before...$"

P2Laboratory_GenesectEvent_Text_1:
	.string "How did you find this place? We kept\n"
	.string "this entire route completely blocked\l"
	.string "off!\p"
	.string "The fact that you are here surely means\n"
	.string "you have come to stop whatever\l"
	.string "“shady” things I may or may not be\l"
	.string "doing...$"

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
	.string "I don't have the right to continue\n"
	.string "holding on to it anymore...\l"
	.string "Kid, you may do as you wish.\p"
	.string "Goodbye, Genesect...$"

P2Laboratory_Genesect_Text_0:
	.string "GWEEEEOYUUU!$"

P2Laboratory_Genesect_Text_1:
	.string "Genesect is watching carefully.$"

P2Laboratory_Genesect_Text_2:
	.string "Genesect fled the laboratory...$"

P2Laboratory_ScientistPostGenesectCapture_Text_0:
	.string "Genesect deserves a proper trainer who\n"
	.string "will treat it well...\n"
	.string "Not a lab rat like me.\p"
	.string "You seem to fit the bill.\n"
	.string "Thank you for helping me see my errors.\p"
	.string "I have one more thing before you\n"
	.string "leave...\p"
	.string "Genesect has been artificially\n"
	.string "reconstructed with an extremely\l"
	.string "powerful cannon on its back, giving it\l"
	.string "the move Techno Blast.\p"
	.string "By inserting a special drive into the\n"
	.string "cannon, the move's type can be\l"
	.string "changed.\p"
	.string "You should take the one you want. If\n"
	.string "you ever feel like swapping, you can\l"
	.string "always come back and ask.$"

P2Laboratory_ScientistGiveFirstDrive_Text_0:
	.string "Which drive would you like?$"

P2Laboratory_ScientistGiveFirstDrive_Text_1:
	.string "Shock Drive$"

P2Laboratory_ScientistGiveFirstDrive_Text_2:
	.string "Burn Drive$"

P2Laboratory_ScientistGiveFirstDrive_Text_3:
	.string "Chill Drive$"

P2Laboratory_ScientistGiveFirstDrive_Text_4:
	.string "Douse Drive$"

P2Laboratory_ScientistGiveFirstDrive_Text_5:
	.string "Looks like you don't have enough space\n"
	.string "to carry it... Come back when you make\l"
	.string "some space.$"

P2Laboratory_ScientistGiveFirstDrive_Text_6:
	.string "Remember, you can always come back\n"
	.string "again later if you want to swap.$"

P2Laboratory_ScientistSwapDrive_Text_0:
	.string "It seems you don't have the last drive I\n"
	.string "gave you.\p"
	.string "You'll have to find it if you want to\n"
	.string "swap.$"

P2Laboratory_ScientistSwapDrive_Text_1:
	.string "No thanks!$"

P2Laboratory_ScientistSwapDrive_Text_2:
	.string "Would you like to swap Genesect's\n"
	.string "drive?$"

P2Laboratory_Scientist_Text_0:
	.string "Despite Genesect being a lab\n"
	.string "experiment, it still needs a home - a\l"
	.string "partner...\p"
	.string "You should show it what it means to be\n"
	.string "with a trustworthy trainer.$"
