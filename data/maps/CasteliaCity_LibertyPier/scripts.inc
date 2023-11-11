CasteliaCity_LibertyPier_MapScripts::
	.byte 0


CasteliaCity_SailorInteract::
	lock
	faceplayer
	goto_if_set FLAG_SEEN_P2_LAB_SCIENTIST_INTERVIEW, CasteliaCity_SailorInteract_3
CasteliaCity_SailorInteract_1:
	msgbox CasteliaCity_SailorInteract_Text_1, MSGBOX_DEFAULT
	dynmultichoice 1, 1, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CasteliaCity_SailorInteract_Text_2, CasteliaCity_SailorInteract_Text_3
	switch VAR_RESULT
	case 0, CasteliaCity_SailorInteract_8
CasteliaCity_SailorInteract_6:
	release
	return

CasteliaCity_SailorInteract_2:
	setflag FLAG_SPOKEN_TO_SAILOR_ABOUT_P2_LAB
	msgbox CasteliaCity_SailorInteract_Text_0, MSGBOX_DEFAULT
	goto CasteliaCity_SailorInteract_1

CasteliaCity_SailorInteract_3:
	goto_if_unset FLAG_SPOKEN_TO_SAILOR_ABOUT_P2_LAB, CasteliaCity_SailorInteract_2
	goto CasteliaCity_SailorInteract_1

CasteliaCity_SailorInteract_8:
	call CasteliaCity_AskHomeOrCasteliaCity
	goto CasteliaCity_SailorInteract_6


CasteliaCity_AskHomeOrCasteliaCity::
	dynmultipush CasteliaCity_AskHomeOrCasteliaCity_Text_0, 0
	goto_if_set FLAG_SEEN_P2_LAB_SCIENTIST_INTERVIEW, CasteliaCity_AskHomeOrCasteliaCity_2
	msgbox CasteliaCity_AskHomeOrCasteliaCity_Text_3, MSGBOX_DEFAULT
CasteliaCity_AskHomeOrCasteliaCity_1:
	dynmultipush CasteliaCity_AskHomeOrCasteliaCity_Text_4, 1
	dynmultistack 1, 1, FALSE, 4, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, CasteliaCity_AskHomeOrCasteliaCity_6
	case 1, CasteliaCity_AskHomeOrCasteliaCity_7
	case 2, CasteliaCity_AskHomeOrCasteliaCity_8
	return

CasteliaCity_AskHomeOrCasteliaCity_2:
	msgbox CasteliaCity_AskHomeOrCasteliaCity_Text_1, MSGBOX_DEFAULT
	dynmultipush CasteliaCity_AskHomeOrCasteliaCity_Text_2, 2
	goto CasteliaCity_AskHomeOrCasteliaCity_1

CasteliaCity_AskHomeOrCasteliaCity_6:
	msgbox CasteliaCity_AskHomeOrCasteliaCity_Text_5, MSGBOX_NPC
	call CasteliaCity_DepartWithSailor
	warp MAP_LIBERTY_GARDEN_EXTERIOR, 1
	waitstate
	return

CasteliaCity_AskHomeOrCasteliaCity_7:
	msgbox CasteliaCity_AskHomeOrCasteliaCity_Text_6, MSGBOX_NPC
	call CasteliaCity_DepartWithSailor
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	return

CasteliaCity_AskHomeOrCasteliaCity_8:
	msgbox CasteliaCity_AskHomeOrCasteliaCity_Text_7, MSGBOX_NPC
	call CasteliaCity_DepartWithSailor
	warp MAP_UNOVA_ROUTE17, 1
	waitstate
	return


CasteliaCity_DepartWithSailor::
	applymovement 2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 30
	hideobjectat 2, MAP_CASTELIA_CITY_LIBERTY_PIER
	switch VAR_FACING
	case DIR_NORTH, CasteliaCity_DepartWithSailor_3
	case DIR_EAST, CasteliaCity_DepartWithSailor_4
	case DIR_SOUTH, CasteliaCity_DepartWithSailor_5
CasteliaCity_DepartWithSailor_1:
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_CASTELIA_CITY_LIBERTY_PIER
	delay 30
	call CasteliaCity_FerryDepart
	return

CasteliaCity_DepartWithSailor_3:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	goto CasteliaCity_DepartWithSailor_1

CasteliaCity_DepartWithSailor_4:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	goto CasteliaCity_DepartWithSailor_1

CasteliaCity_DepartWithSailor_5:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	goto CasteliaCity_DepartWithSailor_1


CasteliaCity_FerryDepart::
	delay 60
	playse SE_RG_SS_ANNE_HORN
	applymovement 1, CasteliaCity_FerryMovement
	waitmovement 0
	return


CasteliaCity_FerryMovement:
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

CasteliaCity_LibertyPierSign::
	msgbox CasteliaCity_LibertyPierSign_Text_0, MSGBOX_SIGN
	return


CasteliaCity_FleaMarketsSign::
	msgbox CasteliaCity_FleaMarketsSign_Text_0, MSGBOX_SIGN
	return


CasteliaCity_StreetSign::
	msgbox CasteliaCity_StreetSign_Text_0, MSGBOX_SIGN
	return


CasteliaCity_PierMan::
	msgbox CasteliaCity_PierMan_Text_0, MSGBOX_NPC
	return


CasteliaCity_PierBoy::
	msgbox CasteliaCity_PierBoy_Text_0, MSGBOX_NPC
	return


CasteliaCity_MarketLittleGirl::
	msgbox CasteliaCity_MarketLittleGirl_Text_0, MSGBOX_NPC
	return


CasteliaCity_MarketGirl::
	msgbox CasteliaCity_MarketGirl_Text_0, MSGBOX_NPC
	return


CasteliaCity_MarketMan2::
	msgbox CasteliaCity_MarketMan2_Text_0, MSGBOX_NPC
	return


CasteliaCity_MarketPikachu::
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox CasteliaCity_MarketPikachu_Text_0, MSGBOX_NPC
	return


CasteliaCity_CafeSonataLady::
	msgbox CasteliaCity_CafeSonataLady_Text_0, MSGBOX_NPC
	return


CasteliaCity_ShadyBoatMan::
	msgbox CasteliaCity_ShadyBoatMan_Text_0, MSGBOX_NPC
	applymovement 22, Common_Movement_FaceRight
	waitmovement 0
	return


CasteliaCity_MarketMan1::
	lock
	goto_if_set FLAG_GIVEN_CASTELIA_MARKET_MAN_RAGE_CANDY_BAR, CasteliaCity_MarketMan1_2
	msgbox CasteliaCity_MarketMan1_Text_1, MSGBOX_NPC
	checkitem ITEM_RAGE_CANDY_BAR, 1
	compare VAR_RESULT, 0
	goto_if_ne CasteliaCity_MarketMan1_5
CasteliaCity_MarketMan1_1:
	release
	return

CasteliaCity_MarketMan1_2:
	msgbox CasteliaCity_MarketMan1_Text_0, MSGBOX_NPC
	goto CasteliaCity_MarketMan1_1

CasteliaCity_MarketMan1_5:
	msgbox CasteliaCity_MarketMan1_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq CasteliaCity_MarketMan1_7
	msgbox CasteliaCity_MarketMan1_Text_4, MSGBOX_NPC
	goto CasteliaCity_MarketMan1_1

CasteliaCity_MarketMan1_7:
	setflag FLAG_GIVEN_CASTELIA_MARKET_MAN_RAGE_CANDY_BAR
	msgbox CasteliaCity_MarketMan1_Text_3, MSGBOX_NPC
	removeitem ITEM_RAGE_CANDY_BAR, 1
	giveitem ITEM_SALAMENCITE, 1
	goto CasteliaCity_MarketMan1_1


CasteliaCity_Nurse::
	lock
	faceplayer
	msgbox CasteliaCity_Nurse_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_ne CasteliaCity_Nurse_2
	msgbox CasteliaCity_Nurse_Text_3, MSGBOX_DEFAULT
CasteliaCity_Nurse_1:
	release
	return

CasteliaCity_Nurse_2:
	msgbox CasteliaCity_Nurse_Text_1, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	delay 30
	msgbox CasteliaCity_Nurse_Text_2, MSGBOX_DEFAULT
	goto CasteliaCity_Nurse_1


CasteliaCity_MarketSaleslady::
	lock
	faceplayer
	msgbox CasteliaCity_MarketSaleslady_Text_0, MSGBOX_DEFAULT
	pokemart CasteliaCity_FleaMarketLadyMart
	release
	return


CasteliaCity_FleaMarketGirl::
	lock
	faceplayer
	msgbox CasteliaCity_FleaMarketGirl_Text_0, MSGBOX_DEFAULT
	pokemart CasteliaCity_FleaMarketGirlMart
	release
	return


	.align 2
CasteliaCity_FleaMarketLadyMart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_CASTELIACONE
	.2byte ITEM_RAGE_CANDY_BAR
	.2byte ITEM_SWEET_HEART
	.2byte ITEM_ROCKY_HELMET
	.2byte ITEM_PP_MAX
	.2byte ITEM_PROTECTIVE_PADS
	.2byte ITEM_ASSAULT_VEST
	.2byte ITEM_BLUNDER_POLICY
	.2byte ITEM_EJECT_BUTTON
	.2byte ITEM_EJECT_PACK
	.2byte ITEM_RED_CARD
	.2byte ITEM_NONE

	.align 2
CasteliaCity_FleaMarketGirlMart:
	.2byte ITEM_MEGA_RING
	.2byte ITEM_SCEPTILITE
	.2byte ITEM_SWAMPERTITE
	.2byte ITEM_BLAZIKENITE
	.2byte ITEM_GARDEVOIRITE
	.2byte ITEM_GALLADITE
	.2byte ITEM_AGGRONITE
	.2byte ITEM_MEDICHAMITE
	.2byte ITEM_MAWILITE
	.2byte ITEM_GLALITITE
	.2byte ITEM_MANECTITE
	.2byte ITEM_BANETTITE
	.2byte ITEM_ABSOLITE
	.2byte ITEM_LATIASITE
	.2byte ITEM_LATIOSITE
	.2byte ITEM_SHARPEDONITE
	.2byte ITEM_CAMERUPTITE
	.2byte ITEM_ALTARIANITE
	.2byte ITEM_METAGROSSITE
	.2byte ITEM_NONE

CasteliaCity_InterviewerF::
	lock
	goto_if_unset FLAG_SEEN_P2_LAB_SCIENTIST_INTERVIEW, CasteliaCity_InterviewerF_2
	msgbox CasteliaCity_InterviewerF_Text_1, MSGBOX_NPC
CasteliaCity_InterviewerF_1:
	release
	return

CasteliaCity_InterviewerF_2:
	msgbox CasteliaCity_InterviewerF_Text_0, MSGBOX_DEFAULT
	closemessage
	goto CasteliaCity_P2ScientistInterview
	goto CasteliaCity_InterviewerF_1


CasteliaCity_InterviewerM::
	lock
	goto_if_unset FLAG_SEEN_P2_LAB_SCIENTIST_INTERVIEW, CasteliaCity_InterviewerM_2
	msgbox CasteliaCity_InterviewerM_Text_1, MSGBOX_NPC
CasteliaCity_InterviewerM_1:
	release
	return

CasteliaCity_InterviewerM_2:
	msgbox CasteliaCity_InterviewerM_Text_0, MSGBOX_DEFAULT
	closemessage
	goto CasteliaCity_P2ScientistInterview
	goto CasteliaCity_InterviewerM_1


CasteliaCity_P2Scientist::
	lock
	msgbox CasteliaCity_P2Scientist_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 30
	goto CasteliaCity_P2ScientistInterview
	release
	return


CasteliaCity_P2ScientistInterview::
	lock
	special Script_FadeOutMapMusic
	compare VAR_LAST_TALKED, 7
	goto_if_eq CasteliaCity_P2ScientistInterview_2
	compare VAR_LAST_TALKED, 8
	goto_if_eq CasteliaCity_P2ScientistInterview_3
	compare VAR_LAST_TALKED, 9
	goto_if_eq CasteliaCity_P2ScientistInterview_4
CasteliaCity_P2ScientistInterview_1:
	switch VAR_TEMP_0
	case 0, CasteliaCity_P2ScientistInterview_10
	case 1, CasteliaCity_P2ScientistInterview_11
	case 2, CasteliaCity_P2ScientistInterview_12
	case 3, CasteliaCity_P2ScientistInterview_13
	case 4, CasteliaCity_P2ScientistInterview_14
	case 5, CasteliaCity_P2ScientistInterview_15
	case 6, CasteliaCity_P2ScientistInterview_16
	case 8, CasteliaCity_P2ScientistInterview_17
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_None
CasteliaCity_P2ScientistInterview_8:
	applymovement 7, CasteliaCity_P2ScientistInterview_ReporterF_MoveToInterview
	applymovement 8, CasteliaCity_P2ScientistInterview_ReporterM_MoveToInterview
	waitmovement 7
	waitmovement 8
	waitmovement OBJ_EVENT_ID_PLAYER
	switch VAR_TEMP_0
	case 7, CasteliaCity_P2ScientistInterview_34
	case 9, CasteliaCity_P2ScientistInterview_35
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_None
CasteliaCity_P2ScientistInterview_32:
	waitmovement OBJ_EVENT_ID_PLAYER
	playse SE_PIN
	applymovement 9, CasteliaCity_P2ScientistInterview_Scientist_Startled
	waitmovement 9
	delay 30
	switch VAR_TEMP_0
	case 0, CasteliaCity_P2ScientistInterview_39
	case 1, CasteliaCity_P2ScientistInterview_40
	case 2, CasteliaCity_P2ScientistInterview_41
	case 3, CasteliaCity_P2ScientistInterview_42
	case 4, CasteliaCity_P2ScientistInterview_43
	case 5, CasteliaCity_P2ScientistInterview_44
	case 6, CasteliaCity_P2ScientistInterview_45
	case 7, CasteliaCity_P2ScientistInterview_46
	case 8, CasteliaCity_P2ScientistInterview_47
	case 9, CasteliaCity_P2ScientistInterview_48
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_None
CasteliaCity_P2ScientistInterview_37:
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 10
	applymovement 7, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 10
	msgbox CasteliaCity_P2ScientistInterview_Text_0, MSGBOX_DEFAULT
	delay 10
	applymovement 9, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement 9, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement 9, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	msgbox CasteliaCity_P2ScientistInterview_Text_1, MSGBOX_DEFAULT
	delay 10
	applymovement 7, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 10
	msgbox CasteliaCity_P2ScientistInterview_Text_2, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox CasteliaCity_P2ScientistInterview_Text_3, MSGBOX_DEFAULT
	applymovement 9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox CasteliaCity_P2ScientistInterview_Text_4, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_MAP_MUSIC_OVERRIDE
	setvar VAR_MAP_MUSIC_OVERRIDE, MUS_NONE
	setflag FLAG_CUSTOM_BATTLE_MUSIC
	setvar VAR_TEMP_CUSTOM_BATTLE_MUSIC, MUS_UNOVA_VS_PLASMA
	trainerbattle_no_intro TRAINER_P2DUDLEY1, CasteliaCity_P2ScientistInterview_Text_5
	clearflag FLAG_MAP_MUSIC_OVERRIDE
	msgbox CasteliaCity_P2ScientistInterview_Text_6, MSGBOX_DEFAULT
	closemessage
	compare VAR_TEMP_0, 8
	goto_if_eq CasteliaCity_P2ScientistInterview_51
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_None
CasteliaCity_P2ScientistInterview_50:
	applymovement 9, CasteliaCity_P2ScientistInterview_Scientist_RunAway
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement 7, Common_Movement_FaceLeft
	applymovement 8, Common_Movement_FaceLeft
	waitmovement 9
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement 7
	waitmovement 8
	removeobject 9
	setflag FLAG_SEEN_P2_LAB_SCIENTIST_INTERVIEW
	delay 60
	playse SE_RG_SS_ANNE_HORN
	waitse
	applymovement 7, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox CasteliaCity_P2ScientistInterview_Text_7, MSGBOX_DEFAULT
	closemessage
	special Overworld_PlaySpecialMapMusic
	release
	return

CasteliaCity_P2ScientistInterview_2:
	switch VAR_FACING
	case DIR_NORTH, CasteliaCity_P2ScientistInterview_20
	case DIR_SOUTH, CasteliaCity_P2ScientistInterview_21
	case DIR_EAST, CasteliaCity_P2ScientistInterview_22
	goto CasteliaCity_P2ScientistInterview_1

CasteliaCity_P2ScientistInterview_3:
	switch VAR_FACING
	case DIR_NORTH, CasteliaCity_P2ScientistInterview_24
	case DIR_EAST, CasteliaCity_P2ScientistInterview_25
	case DIR_WEST, CasteliaCity_P2ScientistInterview_26
	goto CasteliaCity_P2ScientistInterview_1

CasteliaCity_P2ScientistInterview_4:
	switch VAR_FACING
	case DIR_NORTH, CasteliaCity_P2ScientistInterview_28
	case DIR_SOUTH, CasteliaCity_P2ScientistInterview_29
	case DIR_EAST, CasteliaCity_P2ScientistInterview_30
	case DIR_WEST, CasteliaCity_P2ScientistInterview_31
	goto CasteliaCity_P2ScientistInterview_1

CasteliaCity_P2ScientistInterview_10:
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_ReporterF_North_1
	goto CasteliaCity_P2ScientistInterview_8

CasteliaCity_P2ScientistInterview_11:
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_ReporterF_South_1
	goto CasteliaCity_P2ScientistInterview_8

CasteliaCity_P2ScientistInterview_12:
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_ReporterF_East_1
	goto CasteliaCity_P2ScientistInterview_8

CasteliaCity_P2ScientistInterview_13:
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_ReporterM_North_1
	goto CasteliaCity_P2ScientistInterview_8

CasteliaCity_P2ScientistInterview_14:
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_ReporterM_East_1
	goto CasteliaCity_P2ScientistInterview_8

CasteliaCity_P2ScientistInterview_15:
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_ReporterM_West_1
	goto CasteliaCity_P2ScientistInterview_8

CasteliaCity_P2ScientistInterview_16:
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_Scientist_North_1
	goto CasteliaCity_P2ScientistInterview_8

CasteliaCity_P2ScientistInterview_17:
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_Scientist_East_1
	goto CasteliaCity_P2ScientistInterview_8

CasteliaCity_P2ScientistInterview_20:
	setvar VAR_TEMP_0, 0
	goto CasteliaCity_P2ScientistInterview_1

CasteliaCity_P2ScientistInterview_21:
	setvar VAR_TEMP_0, 1
	goto CasteliaCity_P2ScientistInterview_1

CasteliaCity_P2ScientistInterview_22:
	setvar VAR_TEMP_0, 2
	goto CasteliaCity_P2ScientistInterview_1

CasteliaCity_P2ScientistInterview_24:
	setvar VAR_TEMP_0, 3
	goto CasteliaCity_P2ScientistInterview_1

CasteliaCity_P2ScientistInterview_25:
	setvar VAR_TEMP_0, 4
	goto CasteliaCity_P2ScientistInterview_1

CasteliaCity_P2ScientistInterview_26:
	setvar VAR_TEMP_0, 5
	goto CasteliaCity_P2ScientistInterview_1

CasteliaCity_P2ScientistInterview_28:
	setvar VAR_TEMP_0, 6
	goto CasteliaCity_P2ScientistInterview_1

CasteliaCity_P2ScientistInterview_29:
	setvar VAR_TEMP_0, 7
	goto CasteliaCity_P2ScientistInterview_1

CasteliaCity_P2ScientistInterview_30:
	setvar VAR_TEMP_0, 8
	goto CasteliaCity_P2ScientistInterview_1

CasteliaCity_P2ScientistInterview_31:
	setvar VAR_TEMP_0, 9
	goto CasteliaCity_P2ScientistInterview_1

CasteliaCity_P2ScientistInterview_34:
	playse SE_WALL_HIT
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_Scientist_South_1
	goto CasteliaCity_P2ScientistInterview_32

CasteliaCity_P2ScientistInterview_35:
	playse SE_WALL_HIT
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_Scientist_West_1
	goto CasteliaCity_P2ScientistInterview_32

CasteliaCity_P2ScientistInterview_39:
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_ReporterF_North_2
	goto CasteliaCity_P2ScientistInterview_37

CasteliaCity_P2ScientistInterview_40:
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_ReporterF_South_2
	goto CasteliaCity_P2ScientistInterview_37

CasteliaCity_P2ScientistInterview_41:
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_ReporterF_East_2
	goto CasteliaCity_P2ScientistInterview_37

CasteliaCity_P2ScientistInterview_42:
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_ReporterM_North_2
	goto CasteliaCity_P2ScientistInterview_37

CasteliaCity_P2ScientistInterview_43:
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_ReporterM_East_2
	goto CasteliaCity_P2ScientistInterview_37

CasteliaCity_P2ScientistInterview_44:
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_ReporterM_West_2
	goto CasteliaCity_P2ScientistInterview_37

CasteliaCity_P2ScientistInterview_45:
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_Scientist_North_2
	goto CasteliaCity_P2ScientistInterview_37

CasteliaCity_P2ScientistInterview_46:
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_Scientist_South_2
	goto CasteliaCity_P2ScientistInterview_37

CasteliaCity_P2ScientistInterview_47:
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_Scientist_East_2
	goto CasteliaCity_P2ScientistInterview_37

CasteliaCity_P2ScientistInterview_48:
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_Scientist_West_2
	goto CasteliaCity_P2ScientistInterview_37

CasteliaCity_P2ScientistInterview_51:
	playse SE_WALL_HIT
	applymovement OBJ_EVENT_ID_PLAYER, CasteliaCity_P2ScientistInterview_Scientist_East_3
	goto CasteliaCity_P2ScientistInterview_50


CasteliaCity_P2ScientistInterview_None:
	delay_1
	step_end

CasteliaCity_P2ScientistInterview_ReporterF_North_1:
	player_run_left
	face_down
	step_end

CasteliaCity_P2ScientistInterview_ReporterF_South_1:
	face_down
	step_end

CasteliaCity_P2ScientistInterview_ReporterF_East_1:
	face_down
	step_end

CasteliaCity_P2ScientistInterview_ReporterM_North_1:
	face_left
	step_end

CasteliaCity_P2ScientistInterview_ReporterM_East_1:
	player_run_left
	face_down
	step_end

CasteliaCity_P2ScientistInterview_ReporterM_West_1:
	face_down
	step_end

CasteliaCity_P2ScientistInterview_Scientist_North_1:
	face_up
	step_end

CasteliaCity_P2ScientistInterview_Scientist_South_1:
	player_run_left
	face_right
	step_end

CasteliaCity_P2ScientistInterview_Scientist_East_1:
	face_right
	step_end

CasteliaCity_P2ScientistInterview_Scientist_West_1:
	player_run_down
	face_up
	step_end

CasteliaCity_P2ScientistInterview_ReporterF_MoveToInterview:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	face_left
	step_end

CasteliaCity_P2ScientistInterview_ReporterM_MoveToInterview:
	walk_fast_left
	walk_fast_down
	walk_fast_left
	face_down
	step_end

CasteliaCity_P2ScientistInterview_Scientist_Startled:
	emote_exclamation_mark
	delay_16
	delay_16
	face_up
	step_end

CasteliaCity_P2ScientistInterview_ReporterF_North_2:
	walk_left
	walk_down
	face_right
	step_end

CasteliaCity_P2ScientistInterview_ReporterF_South_2:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	face_right
	step_end

CasteliaCity_P2ScientistInterview_ReporterF_East_2:
	walk_left
	walk_down
	walk_down
	face_right
	step_end

CasteliaCity_P2ScientistInterview_ReporterM_North_2:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_down
	face_right
	step_end

CasteliaCity_P2ScientistInterview_ReporterM_East_2:
	walk_left
	walk_down
	face_right
	step_end

CasteliaCity_P2ScientistInterview_ReporterM_West_2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	face_right
	step_end

CasteliaCity_P2ScientistInterview_Scientist_North_2:
	face_up
	step_end

CasteliaCity_P2ScientistInterview_Scientist_South_2:
	face_right
	step_end

CasteliaCity_P2ScientistInterview_Scientist_East_2:
	face_right
	step_end

CasteliaCity_P2ScientistInterview_Scientist_West_2:
	face_up
	step_end

CasteliaCity_P2ScientistInterview_Scientist_East_3:
	player_run_up
	face_down
	step_end

CasteliaCity_P2ScientistInterview_Scientist_RunAway:
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

CasteliaCity_SailorInteract_Text_0:
	.string "I just saw a man in a white coat in a\n"
	.string "huge hurry to board a small boat on the\l"
	.string "other side of the dock. They sped out\l"
	.string "of the port at a very dangerous speed\l"
	.string "too.\p"
	.string ".......\p"
	.string "He was working for Team Plasma on\n"
	.string "something suspicious...?\p"
	.string "I see... I don't know what Team Plasma\n"
	.string "is, but if you're intent on following,\l"
	.string "just give me the word and I'll take you\l"
	.string "to wherever they were headed.$"

CasteliaCity_SailorInteract_Text_1:
	.string "Let me know when you are ready to\n"
	.string "depart.$"

CasteliaCity_SailorInteract_Text_2:
	.string "Let's go$"

CasteliaCity_SailorInteract_Text_3:
	.string "Stay$"

CasteliaCity_AskHomeOrCasteliaCity_Text_0:
	.string "Liberty Garden$"

CasteliaCity_AskHomeOrCasteliaCity_Text_1:
	.string "Do you want to head to Liberty Garden,\n"
	.string "the warehouse on Route 17, or back\l"
	.string "home to Lilycove?\p"
	.string "What do you reckon?$"

CasteliaCity_AskHomeOrCasteliaCity_Text_2:
	.string "Unova Route 17$"

CasteliaCity_AskHomeOrCasteliaCity_Text_3:
	.string "Do you want to go to Liberty Garden not\n"
	.string "far west of here?\p"
	.string "Or do you want to head back to Lilycove\n"
	.string "City in Hoenn.\p"
	.string "What do you reckon?$"

CasteliaCity_AskHomeOrCasteliaCity_Text_4:
	.string "Lilycove City$"

CasteliaCity_AskHomeOrCasteliaCity_Text_5:
	.string "Alright, off to Liberty Garden. We're\n"
	.string "setting sail!$"

CasteliaCity_AskHomeOrCasteliaCity_Text_6:
	.string "We've a few days travel ahead of us! All\n"
	.string "aboard for the Hoenn region!$"

CasteliaCity_AskHomeOrCasteliaCity_Text_7:
	.string "Let me pull out my old Unova map.\n"
	.string "Hopefully it's still up to date. All\l"
	.string "aboard!$"

CasteliaCity_LibertyPierSign_Text_0:
	.string "Castelia City\n"
	.string "Liberty Pier$"

CasteliaCity_FleaMarketsSign_Text_0:
	.string "Castelia City's Flea Markets!\n"
	.string "Permanently set up for all your\l"
	.string "second-hand shopping needs!$"

CasteliaCity_StreetSign_Text_0:
	.string "{LEFT_ARROW} Liberty Pier\n"
	.string "Narrow Street {RIGHT_ARROW}$"

CasteliaCity_PierMan_Text_0:
	.string "My goodness, this sure is a magnificent\n"
	.string "view. Its one of Castelia City's finest.$"

CasteliaCity_PierBoy_Text_0:
	.string "Hey man, check out all of those sick\n"
	.string "boats aye. That's heaps good, yeah.$"

CasteliaCity_MarketLittleGirl_Text_0:
	.string "Wow, there are so many things! Look at\n"
	.string "all the baloons!$"

CasteliaCity_MarketGirl_Text_0:
	.string "I could really do with an extra pair of\n"
	.string "shoes...\p"
	.string "Oh, but maybe I would be better off with\n"
	.string "this nice scented candle for my\l"
	.string "apartment...$"

CasteliaCity_MarketMan2_Text_0:
	.string "This area of Castelia City was famous\n"
	.string "for its seasonal flea markets.\p"
	.string "Perhaps it was due to the beautiful\n"
	.string "view, or the refreshing sea breeze.\l"
	.string "Most likely both.\p"
	.string "Eventually, it just became so popular\n"
	.string "that Castelia's Gym Leader Burgh made\l"
	.string "it a year round attraction for the\l"
	.string "City.\p"
	.string "He is, after all, an avid attendee of\n"
	.string "course.$"

CasteliaCity_MarketPikachu_Text_0:
	.string "Pika... pikaaaa!$"

CasteliaCity_CafeSonataLady_Text_0:
	.string "Oh hello there youngster. Wondering\n"
	.string "where I got this coffee from?\p"
	.string "A café that I visit often, just down the\n"
	.string "road here and up a narrow street, it's\l"
	.string "easy to miss.$"

CasteliaCity_ShadyBoatMan_Text_0:
	.string "This is a private boat, and I am waiting\n"
	.string "for someone important.\p"
	.string "Access is restricted for the likes of\n"
	.string "you.$"

CasteliaCity_MarketMan1_Text_0:
	.string "...om nom, nom...$"

CasteliaCity_MarketMan1_Text_1:
	.string "I wonder if anyone here sells Rage\n"
	.string "Candy Bars?\p"
	.string "Oh man I could use one right about now.$"

CasteliaCity_MarketMan1_Text_2:
	.string "No way, do I spot one poking out of your\n"
	.string "bag right there?\p"
	.string "Here, I've got this weird colourful rock.\n"
	.string "You can have it in return for that\l"
	.string "delicious candy bar?$"

CasteliaCity_MarketMan1_Text_3:
	.string "AH YES! What a tasty Rage Candy Bar!\n"
	.string "Thank you. Here is the nice rock.$"

CasteliaCity_MarketMan1_Text_4:
	.string "Aww man, thats such a bummer...$"

CasteliaCity_Nurse_Text_0:
	.string "Hello, I'm the Pokémon nurse for the\n"
	.string "Liberty Pier flea markets. Would you\l"
	.string "like me to heal your Pokémon?$"

CasteliaCity_Nurse_Text_1:
	.string "Let me take your Pokémon for a moment...$"

CasteliaCity_Nurse_Text_2:
	.string "Thank you for waiting. Your Pokémon\n"
	.string "have been fully healed.\l"
	.string "Please come again.$"

CasteliaCity_Nurse_Text_3:
	.string "Please come again.$"

CasteliaCity_MarketSaleslady_Text_0:
	.string "Hello hello! Please take a look at my\n"
	.string "fine items.$"

CasteliaCity_FleaMarketGirl_Text_0:
	.string "Hi there, please have a look around and\n"
	.string "enjoy yourself!$"

CasteliaCity_InterviewerF_Text_0:
	.string "Quickly! There he is!$"

CasteliaCity_InterviewerF_Text_1:
	.string "He ran off...\n"
	.string "Clearly he is involved in something\l"
	.string "fishy...\p"
	.string "We had reports of a warehouse on Route\n"
	.string "17 being used by Team Plasma to hide\l"
	.string "suspicious activity.$"

CasteliaCity_InterviewerM_Text_0:
	.string "Three...\p"
	.string "Two...\p"
	.string "One...\p"
	.string "Camera's rolling!$"

CasteliaCity_InterviewerM_Text_1:
	.string "What an absolute donkey...$"

CasteliaCity_P2Scientist_Text_0:
	.string ".......\p"
	.string "He seems to be on an important sounding\n"
	.string "phone call. Better leave him alone...$"

CasteliaCity_P2ScientistInterview_Text_0:
	.string "...Mr. Dudley! What can you tell us about\n"
	.string "the rumours of a secret experiment\l"
	.string "you're allegedly undertaking for Team\l"
	.string "Plasma?$"

CasteliaCity_P2ScientistInterview_Text_1:
	.string "You seem to be mistaken! I'm not Dudley.\p"
	.string "I don't know what you're talking about!$"

CasteliaCity_P2ScientistInterview_Text_2:
	.string "We have our sources. You are no doubt\n"
	.string "Mr. Dudley.\p"
	.string "Is there some sort of operation\n"
	.string "stationed on Route 17, Mr. Dudley? Can\l"
	.string "you please tell us about that?$"

CasteliaCity_P2ScientistInterview_Text_3:
	.string "............\p"
	.string "Argh! To hell with it!\n"
	.string "I don't have the time to deal with this\l"
	.string "now!\p"
	.string "Team Plasma will soon rule all of Unova!\n"
	.string "Just you wait!$"

CasteliaCity_P2ScientistInterview_Text_4:
	.string "Now move it kid! I have an important\n"
	.string "ferry to catch!$"

CasteliaCity_P2ScientistInterview_Text_5:
	.string "My god, what is this nonsense?!$"

CasteliaCity_P2ScientistInterview_Text_6:
	.string "Enough!\p"
	.string "I know nothing about any warehouse on\n"
	.string "Route 17.\p"
	.string "Now out of my way!$"

CasteliaCity_P2ScientistInterview_Text_7:
	.string "Hmm...\n"
	.string "I didn't say anything about a\l"
	.string "warehouse...$"
