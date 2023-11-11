LibertyGarden_Exterior_MapScripts::
	.byte 0


LibertyGarden_LighthouseSign::
	msgbox LibertyGarden_LighthouseSign_Text_0, MSGBOX_SIGN
	return


LibertyGarden_DockWestSign::
	msgbox LibertyGarden_DockWestSign_Text_0, MSGBOX_SIGN
	return


LibertyGarden_DockEastSign::
	msgbox LibertyGarden_DockEastSign_Text_0, MSGBOX_SIGN
	return


LibertyGarden_SailorInteract::
	lock
	faceplayer
	msgbox LibertyGarden_SailorInteract_Text_0, MSGBOX_DEFAULT
	dynmultichoice 1, 1, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, LibertyGarden_SailorInteract_Text_1, LibertyGarden_SailorInteract_Text_2
	switch VAR_RESULT
	case 0, LibertyGarden_SailorInteract_3
LibertyGarden_SailorInteract_1:
	release
	return

LibertyGarden_SailorInteract_3:
	call LibertyGarden_AskHomeOrCasteliaCity
	goto LibertyGarden_SailorInteract_1


LibertyGarden_AskHomeOrCasteliaCity::
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LibertyGarden_AskHomeOrCasteliaCity_2
	msgbox LibertyGarden_AskHomeOrCasteliaCity_Text_1, MSGBOX_DEFAULT
LibertyGarden_AskHomeOrCasteliaCity_1:
	msgbox LibertyGarden_AskHomeOrCasteliaCity_Text_2, MSGBOX_DEFAULT
	dynmultichoice 1, 1, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, LibertyGarden_AskHomeOrCasteliaCity_Text_3, LibertyGarden_AskHomeOrCasteliaCity_Text_4
	switch VAR_RESULT
	case 0, LibertyGarden_AskHomeOrCasteliaCity_6
	case 1, LibertyGarden_AskHomeOrCasteliaCity_7
	return

LibertyGarden_AskHomeOrCasteliaCity_2:
	msgbox LibertyGarden_AskHomeOrCasteliaCity_Text_0, MSGBOX_DEFAULT
	goto LibertyGarden_AskHomeOrCasteliaCity_1

LibertyGarden_AskHomeOrCasteliaCity_6:
	msgbox LibertyGarden_AskHomeOrCasteliaCity_Text_5, MSGBOX_NPC
	call LibertyGarden_DepartWithSailor
	warp MAP_CASTELIA_CITY_LIBERTY_PIER, 2
	waitstate
	return

LibertyGarden_AskHomeOrCasteliaCity_7:
	msgbox LibertyGarden_AskHomeOrCasteliaCity_Text_6, MSGBOX_NPC
	call LibertyGarden_DepartWithSailor
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	return


LibertyGarden_DepartWithSailor::
	applymovement 2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	hideobjectat 2, MAP_LIBERTY_GARDEN_EXTERIOR
	switch VAR_FACING
	case DIR_NORTH, LibertyGarden_DepartWithSailor_3
	case DIR_EAST, LibertyGarden_DepartWithSailor_4
	case DIR_WEST, LibertyGarden_DepartWithSailor_5
LibertyGarden_DepartWithSailor_1:
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_LIBERTY_GARDEN_EXTERIOR
	delay 30
	call LibertyGarden_FerryDepart
	return

LibertyGarden_DepartWithSailor_3:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	goto LibertyGarden_DepartWithSailor_1

LibertyGarden_DepartWithSailor_4:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	goto LibertyGarden_DepartWithSailor_1

LibertyGarden_DepartWithSailor_5:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	goto LibertyGarden_DepartWithSailor_1


LibertyGarden_FerryDepart::
	delay 60
	playse SE_RG_SS_ANNE_HORN
	applymovement 1, LibertyGarden_FerryMovement
	waitmovement 0
	return


LibertyGarden_FerryMovement:
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LibertyGarden_LighthouseSign_Text_0:
	.string "This lighthouse shines with the light of\n"
	.string "freedom.\l"
	.string "Only authorized personnel may enter.$"

LibertyGarden_DockWestSign_Text_0:
	.string "Two hundred years ago, an ultra-rich\n"
	.string "family bought this island.\l"
	.string "They named it Liberty Garden.\p"
	.string "It's a place where people and Pokémon\n"
	.string "can live freely.$"

LibertyGarden_DockEastSign_Text_0:
	.string "Dock 2\n"
	.string "To board the tour boat, go to Dock 1.$"

LibertyGarden_SailorInteract_Text_0:
	.string "Quite the journey wouldn't you say kid?\p"
	.string "How is the lighthouse? As grand as you\n"
	.string "expected?\p"
	.string "Let me know when you are ready to\n"
	.string "depart.$"

LibertyGarden_SailorInteract_Text_1:
	.string "Let's go$"

LibertyGarden_SailorInteract_Text_2:
	.string "Stay$"

LibertyGarden_AskHomeOrCasteliaCity_Text_0:
	.string "We are a long way from home laddy.$"

LibertyGarden_AskHomeOrCasteliaCity_Text_1:
	.string "We are a long way from home lassy.$"

LibertyGarden_AskHomeOrCasteliaCity_Text_2:
	.string "Do you want to go to the docks at\n"
	.string "Castelia City for a refresher?\p"
	.string "If not, the ship is fuelled up and ready\n"
	.string "to take us back to Lilycove City in\l"
	.string "Hoenn.\p"
	.string "What do you say kid?$"

LibertyGarden_AskHomeOrCasteliaCity_Text_3:
	.string "Castelia City$"

LibertyGarden_AskHomeOrCasteliaCity_Text_4:
	.string "Lilycove City$"

LibertyGarden_AskHomeOrCasteliaCity_Text_5:
	.string "A short trip to Castelia City it is then!\n"
	.string "Jump on the ship and lets get going.$"

LibertyGarden_AskHomeOrCasteliaCity_Text_6:
	.string "We've got a long voyage back to\n"
	.string "Lilycove City! All aboard!$"
