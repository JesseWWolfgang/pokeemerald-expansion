Unova_Route17_MapScripts::
	.byte 0


Unova_Route17_SailorInteract::
	lock
	faceplayer
	msgbox Unova_Route17_SailorInteract_Text_0, MSGBOX_DEFAULT
	dynmultichoice 1, 1, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, Unova_Route17_SailorInteract_Text_1, Unova_Route17_SailorInteract_Text_2
	switch VAR_RESULT
	case 0, Unova_Route17_SailorInteract_3
Unova_Route17_SailorInteract_1:
	release
	return

Unova_Route17_SailorInteract_3:
	call Unova_Route17_AskHomeOrCasteliaCity
	goto Unova_Route17_SailorInteract_1


Unova_Route17_AskHomeOrCasteliaCity::
	msgbox Unova_Route17_AskHomeOrCasteliaCity_Text_0, MSGBOX_DEFAULT
	dynmultichoice 1, 1, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, Unova_Route17_AskHomeOrCasteliaCity_Text_1, Unova_Route17_AskHomeOrCasteliaCity_Text_2
	switch VAR_RESULT
	case 0, Unova_Route17_AskHomeOrCasteliaCity_2
	case 1, Unova_Route17_AskHomeOrCasteliaCity_3
	return

Unova_Route17_AskHomeOrCasteliaCity_2:
	msgbox Unova_Route17_AskHomeOrCasteliaCity_Text_3, MSGBOX_NPC
	call Unova_Route17_DepartWithSailor
	warp MAP_CASTELIA_CITY_LIBERTY_PIER, 10, 28
	waitstate
	return

Unova_Route17_AskHomeOrCasteliaCity_3:
	msgbox Unova_Route17_AskHomeOrCasteliaCity_Text_4, MSGBOX_NPC
	call Unova_Route17_DepartWithSailor
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	return


Unova_Route17_DepartWithSailor::
	applymovement 2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 30
	hideobjectat 2, MAP_UNOVA_ROUTE17
	switch VAR_FACING
	case DIR_NORTH, Unova_Route17_DepartWithSailor_3
	case DIR_EAST, Unova_Route17_DepartWithSailor_4
	case DIR_SOUTH, Unova_Route17_DepartWithSailor_5
Unova_Route17_DepartWithSailor_1:
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_UNOVA_ROUTE17
	delay 30
	call Unova_Route17_FerryDepart
	return

Unova_Route17_DepartWithSailor_3:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	goto Unova_Route17_DepartWithSailor_1

Unova_Route17_DepartWithSailor_4:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	goto Unova_Route17_DepartWithSailor_1

Unova_Route17_DepartWithSailor_5:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	goto Unova_Route17_DepartWithSailor_1


Unova_Route17_FerryDepart::
	delay 60
	playse SE_RG_SS_ANNE_HORN
	applymovement 1, Unova_Route17_FerryMovement
	waitmovement 0
	return


Unova_Route17_FerryMovement:
	walk_slow_left
	walk_slow_left
	walk_slow_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Unova_Route17_SailorInteract_Text_0:
	.string "It's quite pleasant out here isn't it? A\n"
	.string "bit wet though...\p"
	.string "Let me know when you are ready to\n"
	.string "depart.$"

Unova_Route17_SailorInteract_Text_1:
	.string "Let's go$"

Unova_Route17_SailorInteract_Text_2:
	.string "Stay$"

Unova_Route17_AskHomeOrCasteliaCity_Text_0:
	.string "Do you want to head to Castelia City, or\n"
	.string "back home to Lilycove?$"

Unova_Route17_AskHomeOrCasteliaCity_Text_1:
	.string "Castelia City$"

Unova_Route17_AskHomeOrCasteliaCity_Text_2:
	.string "Lilycove City$"

Unova_Route17_AskHomeOrCasteliaCity_Text_3:
	.string "Back to Castelia City it is then! Jump\n"
	.string "on the ship and lets get going.$"

Unova_Route17_AskHomeOrCasteliaCity_Text_4:
	.string "We've got a long voyage back to\n"
	.string "Lilycove City! All aboard!$"
