.set LOCALID_ATTENDANT, 1
.set LOCALID_SS_TIDAL, 2
.set LOCALID_FERRY_SAILOR, 4
.set LOCALID_BRINEY, 5

LilycoveCity_Harbor_EventScript_FerryAttendant::
	call LilycoveHarbor_FerryAttendantDynamic
	return


LilycoveHarbor_FerryAttendantDynamic::
	lock
	faceplayer
	special PopulateFerryOptions
	goto_if_set FLAG_TEMP_SSTIDAL_HAS_SS_TICKET, LilycoveHarbor_FerryAttendantDynamic_2
	compare VAR_TEMP_SSTIDAL_EVENT_TICKET_COUNT, 0
	goto_if_gt LilycoveHarbor_FerryAttendantDynamic_3
	goto_if_set FLAG_HIDE_LILYCOVE_HARBOR_SSTIDAL, LilycoveHarbor_FerryAttendantDynamic_7
	msgbox LilycoveHarbor_FerryAttendantDynamic_Text_1, MSGBOX_NPC
LilycoveHarbor_FerryAttendantDynamic_1:
	release
	end

LilycoveHarbor_FerryAttendantDynamic_2:
	call LilycoveHarbor_PushDynTickets
	msgbox LilycoveCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	dynmultistack 1, 1, FALSE, 4, FALSE, ITEM_SS_TICKET, DYN_MULTICHOICE_CB_SHOW_ITEM
	call LilycoveHarbor_CheckTicketPresented
	goto LilycoveHarbor_FerryAttendantDynamic_1

LilycoveHarbor_FerryAttendantDynamic_3:
	call LilycoveHarbor_PushDynTickets
	msgbox LilycoveHarbor_FerryAttendantDynamic_Text_0, MSGBOX_NPC
	dynmultistack 1, 1, FALSE, 4, FALSE, ITEM_SS_TICKET, DYN_MULTICHOICE_CB_SHOW_ITEM
	call LilycoveHarbor_CheckTicketPresented
	goto LilycoveHarbor_FerryAttendantDynamic_1

LilycoveHarbor_FerryAttendantDynamic_7:
	msgbox LilycoveCity_Harbor_Text_FerryUnavailable, MSGBOX_NPC
	goto LilycoveHarbor_FerryAttendantDynamic_1


LilycoveHarbor_PushDynTickets::
	goto_if_set FLAG_TEMP_SSTIDAL_HAS_SS_TICKET, LilycoveHarbor_PushDynTickets_2
LilycoveHarbor_PushDynTickets_1:
	goto_if_set FLAG_TEMP_SSTIDAL_HAS_MYSTIC_TICKET, LilycoveHarbor_PushDynTickets_5
LilycoveHarbor_PushDynTickets_4:
	goto_if_set FLAG_TEMP_SSTIDAL_HAS_EON_TICKET, LilycoveHarbor_PushDynTickets_8
LilycoveHarbor_PushDynTickets_7:
	goto_if_set FLAG_TEMP_SSTIDAL_HAS_AURORA_TICKET, LilycoveHarbor_PushDynTickets_11
LilycoveHarbor_PushDynTickets_10:
	goto_if_set FLAG_TEMP_SSTIDAL_HAS_OLD_SEA_MAP, LilycoveHarbor_PushDynTickets_14
LilycoveHarbor_PushDynTickets_13:
	goto_if_set FLAG_TEMP_SSTIDAL_HAS_LIBERTY_PASS, LilycoveHarbor_PushDynTickets_16
	return

LilycoveHarbor_PushDynTickets_2:
	bufferitemname STR_VAR_1, ITEM_SS_TICKET
	dynmultipush LilycoveHarbor_PushDynTickets_Text_0, ITEM_SS_TICKET
	goto LilycoveHarbor_PushDynTickets_1

LilycoveHarbor_PushDynTickets_5:
	bufferitemname STR_VAR_1, ITEM_MYSTIC_TICKET
	dynmultipush LilycoveHarbor_PushDynTickets_Text_0, ITEM_MYSTIC_TICKET
	goto LilycoveHarbor_PushDynTickets_4

LilycoveHarbor_PushDynTickets_8:
	bufferitemname STR_VAR_1, ITEM_EON_TICKET
	dynmultipush LilycoveHarbor_PushDynTickets_Text_0, ITEM_EON_TICKET
	goto LilycoveHarbor_PushDynTickets_7

LilycoveHarbor_PushDynTickets_11:
	bufferitemname STR_VAR_1, ITEM_AURORA_TICKET
	dynmultipush LilycoveHarbor_PushDynTickets_Text_0, ITEM_AURORA_TICKET
	goto LilycoveHarbor_PushDynTickets_10

LilycoveHarbor_PushDynTickets_14:
	bufferitemname STR_VAR_1, ITEM_OLD_SEA_MAP
	dynmultipush LilycoveHarbor_PushDynTickets_Text_0, ITEM_OLD_SEA_MAP
	goto LilycoveHarbor_PushDynTickets_13

LilycoveHarbor_PushDynTickets_16:
	bufferitemname STR_VAR_1, ITEM_LIBERTY_PASS
	dynmultipush LilycoveHarbor_PushDynTickets_Text_0, ITEM_LIBERTY_PASS
	return


LilycoveHarbor_CheckTicketPresented::
	switch VAR_RESULT
	case ITEM_SS_TICKET, LilycoveHarbor_CheckTicketPresented_2
	case ITEM_MYSTIC_TICKET, LilycoveHarbor_CheckTicketPresented_3
	case ITEM_EON_TICKET, LilycoveHarbor_CheckTicketPresented_4
	case ITEM_AURORA_TICKET, LilycoveHarbor_CheckTicketPresented_5
	case ITEM_OLD_SEA_MAP, LilycoveHarbor_CheckTicketPresented_6
	case ITEM_LIBERTY_PASS, LilycoveHarbor_CheckTicketPresented_7
	return

LilycoveHarbor_CheckTicketPresented_2:
	call LilycoveHarbor_SelectedSSTicket
	return

LilycoveHarbor_CheckTicketPresented_3:
	call LilycoveHarbor_SelectedMysticTicket
	return

LilycoveHarbor_CheckTicketPresented_4:
	call LilycoveHarbor_SelectedEonTicket
	return

LilycoveHarbor_CheckTicketPresented_5:
	call LilycoveHarbor_SelectedAuroraTicket
	return

LilycoveHarbor_CheckTicketPresented_6:
	call LilycoveHarbor_SelectedOldSeaMap
	return

LilycoveHarbor_CheckTicketPresented_7:
	call LilycoveHarbor_SelectedLibertyPass
	return


LilycoveHarbor_SelectedSSTicket::
	msgbox LilycoveCity_Harbor_Text_FlashTicketWhereTo, MSGBOX_DEFAULT
	dynmultipush LilycoveHarbor_SelectedSSTicket_Text_0, 0
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, LilycoveHarbor_SelectedSSTicket_2
LilycoveHarbor_SelectedSSTicket_1:
	dynmultistack 1, 1, FALSE, 4, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, LilycoveHarbor_SelectedSSTicket_6
	case 1, LilycoveHarbor_SelectedSSTicket_7
LilycoveHarbor_SelectedSSTicket_4:
	release
	return

LilycoveHarbor_SelectedSSTicket_2:
	dynmultipush LilycoveHarbor_SelectedSSTicket_Text_1, 1
	goto LilycoveHarbor_SelectedSSTicket_1

LilycoveHarbor_SelectedSSTicket_6:
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
	waitstate
	goto LilycoveHarbor_SelectedSSTicket_4

LilycoveHarbor_SelectedSSTicket_7:
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
	waitstate
	goto LilycoveHarbor_SelectedSSTicket_4


LilycoveHarbor_SelectedMysticTicket::
	call LilycoveHarbor_LadyFetchesSailor
	goto_if_unset FLAG_SHOWN_MYSTIC_TICKET, LilycoveHarbor_SelectedMysticTicket_2
	msgbox LilycoveHarbor_SelectedMysticTicket_Text_0, MSGBOX_NPC
LilycoveHarbor_SelectedMysticTicket_1:
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_NAVEL_ROCK_HARBOR, 8, 4
	waitstate
	release
	return

LilycoveHarbor_SelectedMysticTicket_2:
	setflag FLAG_SHOWN_MYSTIC_TICKET
	msgbox EventTicket_Text_OddTicketGetOnBoard, MSGBOX_NPC
	goto LilycoveHarbor_SelectedMysticTicket_1


LilycoveHarbor_SelectedEonTicket::
	call LilycoveHarbor_LadyFetchesSailor
	goto_if_unset FLAG_SHOWN_EON_TICKET, LilycoveHarbor_SelectedEonTicket_2
	msgbox LilycoveHarbor_SelectedEonTicket_Text_0, MSGBOX_NPC
LilycoveHarbor_SelectedEonTicket_1:
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 13, 22
	waitstate
	release
	return

LilycoveHarbor_SelectedEonTicket_2:
	setflag FLAG_SHOWN_EON_TICKET
	msgbox EventTicket_Text_ShowEonTicket, MSGBOX_NPC
	goto LilycoveHarbor_SelectedEonTicket_1


LilycoveHarbor_SelectedAuroraTicket::
	call LilycoveHarbor_LadyFetchesSailor
	goto_if_unset FLAG_SHOWN_AURORA_TICKET, LilycoveHarbor_SelectedAuroraTicket_2
	msgbox LilycoveHarbor_SelectedAuroraTicket_Text_0, MSGBOX_NPC
LilycoveHarbor_SelectedAuroraTicket_1:
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_BIRTH_ISLAND_HARBOR, 8, 4
	waitstate
	release
	return

LilycoveHarbor_SelectedAuroraTicket_2:
	setflag FLAG_SHOWN_AURORA_TICKET
	msgbox EventTicket_Text_OddTicketGetOnBoard, MSGBOX_NPC
	goto LilycoveHarbor_SelectedAuroraTicket_1


LilycoveHarbor_SelectedOldSeaMap::
	call LilycoveHarbor_LadyFetchesSailor
	goto_if_unset FLAG_SHOWN_OLD_SEA_MAP, LilycoveHarbor_SelectedOldSeaMap_2
	msgbox LilycoveHarbor_SelectedOldSeaMap_Text_0, MSGBOX_NPC
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
LilycoveHarbor_SelectedOldSeaMap_1:
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
	waitstate
	release
	return

LilycoveHarbor_SelectedOldSeaMap_2:
	setflag FLAG_SHOWN_OLD_SEA_MAP
	call LilycoveHarbor_OldSeaMapFirstTime
	goto LilycoveHarbor_SelectedOldSeaMap_1


LilycoveHarbor_OldSeaMapFirstTime::
	msgbox EventTicket_Text_OldSeaMapTooFar, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayNorth
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayEast
	addobject LOCALID_BRINEY
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_BrineyFaceSailorNorth
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_BrineyFaceSailorEast
	msgbox EventTicket_Text_BrineyHoldOnASecond, MSGBOX_DEFAULT
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_BrineyFacePlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_BrineyFacePlayerEast
	msgbox EventTicket_Text_BrineyLetsSail, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorNorth
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorEast
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepart
	return


LilycoveHarbor_SelectedLibertyPass::
	call LilycoveHarbor_LadyFetchesSailor
	goto_if_unset FLAG_SHOWN_LIBERTY_PASS, LilycoveHarbor_SelectedLibertyPass_2
LilycoveHarbor_SelectedLibertyPass_1:
	showmoneybox 1, 1
	msgbox LilycoveHarbor_SelectedLibertyPass_Text_4, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LilycoveHarbor_SelectedLibertyPass_5
	msgbox LilycoveHarbor_SelectedLibertyPass_Text_7, MSGBOX_NPC
	hidemoneybox
	call LilycoveHarbor_SailorComeBackIfYouChangeYourMind
LilycoveHarbor_SelectedLibertyPass_4:
	release
	return

LilycoveHarbor_SelectedLibertyPass_2:
	setflag FLAG_SHOWN_LIBERTY_PASS
	msgbox LilycoveHarbor_SelectedLibertyPass_Text_0, MSGBOX_NPC
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	msgbox LilycoveHarbor_SelectedLibertyPass_Text_1, MSGBOX_NPC
	delay 10
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	msgbox LilycoveHarbor_SelectedLibertyPass_Text_2, MSGBOX_DEFAULT
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_FacePlayer
	msgbox LilycoveHarbor_SelectedLibertyPass_Text_3, MSGBOX_DEFAULT
	goto LilycoveHarbor_SelectedLibertyPass_1

LilycoveHarbor_SelectedLibertyPass_5:
	checkmoney 10000
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveHarbor_SelectedLibertyPass_8
	msgbox LilycoveHarbor_SelectedLibertyPass_Text_6, MSGBOX_NPC
	hidemoneybox
	call LilycoveHarbor_SailorComeBackIfYouChangeYourMind
	goto LilycoveHarbor_SelectedLibertyPass_4

LilycoveHarbor_SelectedLibertyPass_8:
	removemoney 10000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	msgbox LilycoveHarbor_SelectedLibertyPass_Text_5, MSGBOX_NPC
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_BIRTH_ISLAND_HARBOR, 8, 4
	waitstate
	goto LilycoveHarbor_SelectedLibertyPass_4


LilycoveHarbor_SailorComeBackIfYouChangeYourMind::
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LilycoveHarbor_SailorComeBackIfYouChangeYourMind_2
	msgbox LilycoveHarbor_SailorComeBackIfYouChangeYourMind_Text_1, MSGBOX_NPC
LilycoveHarbor_SailorComeBackIfYouChangeYourMind_1:
	call LilycoveHarbor_SailorReturns
	return

LilycoveHarbor_SailorComeBackIfYouChangeYourMind_2:
	msgbox LilycoveHarbor_SailorComeBackIfYouChangeYourMind_Text_0, MSGBOX_NPC
	goto LilycoveHarbor_SailorComeBackIfYouChangeYourMind_1


LilycoveHarbor_SailorReturns::
	closemessage
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	removeobject LOCALID_FERRY_SAILOR, MAP_LILYCOVE_CITY_HARBOR
	delay 60
	showobjectat LOCALID_ATTENDANT, MAP_LILYCOVE_CITY_HARBOR
	delay 30
	applymovement LOCALID_ATTENDANT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveHarbor_SailorReturns_Text_0, MSGBOX_NPC
	return


LilycoveHarbor_LadyFetchesSailor::
	msgbox LilycoveHarbor_LadyFetchesSailor_Text_0
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_LILYCOVE_CITY_HARBOR
	delay 60
	addobject LOCALID_FERRY_SAILOR
	delay 30
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_FacePlayer
	waitmovement 0
	return


LilycoveCity_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_Harbor_OnTransition
	.byte 0

LilycoveCity_Harbor_OnTransition:
	setescapewarp MAP_LILYCOVE_CITY, 12, 33
	end

@ First goto_if_eq is unnecessary; identical scripts
LilycoveCity_Harbor_EventScript_NoFirstTimeEventTickets::
	goto_if_eq VAR_TEMP_A, 0, LilycoveCity_Harbor_EventScript_NoEventTickets
	msgbox LilycoveCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message LilycoveCity_Harbor_Text_FlashTicketWhereTo
	waitmessage
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
	end

LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect::
	setvar VAR_0x8004, 0
	special ScriptMenu_CreateLilycoveSSTidalMultichoice
	waitstate
	special GetLilycoveSSTidalSelection
	switch VAR_RESULT
	case 0, LilycoveCity_Harbor_EventScript_GoToSlateport
	case 1, LilycoveCity_Harbor_EventScript_GoToBattleFrontier
	case 2, LilycoveCity_Harbor_EventScript_GoToSouthernIsland
	case 3, LilycoveCity_Harbor_EventScript_GoToNavelRock
	case 4, LilycoveCity_Harbor_EventScript_GoToBirthIsland
	case 5, LilycoveCity_Harbor_EventScript_GoToFarawayIsland
	case 6, LilycoveCity_Harbor_EventScript_ExitSailSelect
	case MULTI_B_PRESSED, LilycoveCity_Harbor_EventScript_ExitSailSelect
	end

LilycoveCity_Harbor_EventScript_GoToSouthernIsland::
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 13, 22
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToNavelRock::
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_NAVEL_ROCK_HARBOR, 8, 4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToBirthIsland::
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_BIRTH_ISLAND_HARBOR, 8, 4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToFarawayIsland::
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToSlateport::
	msgbox LilycoveCity_Harbor_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToBattleFrontier::
	msgbox LilycoveCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GetEonTicketState::
	setvar VAR_TEMP_E, 0
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, Common_EventScript_NopReturn
	checkitem ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	setvar VAR_TEMP_E, 1
	goto_if_set FLAG_SHOWN_EON_TICKET, Common_EventScript_NopReturn
	setvar VAR_TEMP_E, 2
	return

LilycoveCity_Harbor_EventScript_GetAuroraTicketState::
	setvar VAR_TEMP_D, 0
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, Common_EventScript_NopReturn
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	setvar VAR_TEMP_D, 1
	goto_if_set FLAG_SHOWN_AURORA_TICKET, Common_EventScript_NopReturn
	setvar VAR_TEMP_D, 2
	return

LilycoveCity_Harbor_EventScript_GetOldSeaMapState::
	setvar VAR_TEMP_C, 0
	goto_if_unset FLAG_ENABLE_SHIP_FARAWAY_ISLAND, Common_EventScript_NopReturn
	checkitem ITEM_OLD_SEA_MAP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	setvar VAR_TEMP_C, 1
	goto_if_set FLAG_SHOWN_OLD_SEA_MAP, Common_EventScript_NopReturn
	setvar VAR_TEMP_C, 2
	return

LilycoveCity_Harbor_EventScript_GetMysticTicketState::
	setvar VAR_TEMP_9, 0
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, Common_EventScript_NopReturn
	checkitem ITEM_MYSTIC_TICKET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	setvar VAR_TEMP_9, 1
	goto_if_set FLAG_SHOWN_MYSTIC_TICKET, Common_EventScript_NopReturn
	setvar VAR_TEMP_9, 2
	return

LilycoveCity_Harbor_EventScript_GetFirstTimeShowingTicket::
	setvar VAR_TEMP_B, 0
	call_if_eq VAR_TEMP_E, 2, LilycoveCity_Harbor_EventScript_SetFirstTimeShowingEonTicket
	call_if_eq VAR_TEMP_D, 2, LilycoveCity_Harbor_EventScript_SetFirstTimeShowingAuroraTicket
	call_if_eq VAR_TEMP_C, 2, LilycoveCity_Harbor_EventScript_SetFirstTimeShowingOldSeaMap
	call_if_eq VAR_TEMP_9, 2, LilycoveCity_Harbor_EventScript_SetFirstTimeShowingMysticTicket
	return

LilycoveCity_Harbor_EventScript_SetFirstTimeShowingEonTicket::
	addvar VAR_TEMP_B, 1
	return

LilycoveCity_Harbor_EventScript_SetFirstTimeShowingAuroraTicket::
	addvar VAR_TEMP_B, 2
	return

LilycoveCity_Harbor_EventScript_SetFirstTimeShowingOldSeaMap::
	addvar VAR_TEMP_B, 4
	return

LilycoveCity_Harbor_EventScript_SetFirstTimeShowingMysticTicket::
	addvar VAR_TEMP_B, 8
	return

LilycoveCity_Harbor_EventScript_GetHasTicketsState::
	setvar VAR_TEMP_A, 0
	call_if_eq VAR_TEMP_E, 1, LilycoveCity_Harbor_EventScript_SetHasEonTicket
	call_if_eq VAR_TEMP_D, 1, LilycoveCity_Harbor_EventScript_SetHasAuroraTicket
	call_if_eq VAR_TEMP_C, 1, LilycoveCity_Harbor_EventScript_SetHasOldSeaMap
	call_if_eq VAR_TEMP_9, 1, LilycoveCity_Harbor_EventScript_SetHasMysticTicket
	return

LilycoveCity_Harbor_EventScript_SetHasEonTicket::
	addvar VAR_TEMP_A, 1
	return

LilycoveCity_Harbor_EventScript_SetHasAuroraTicket::
	addvar VAR_TEMP_A, 2
	return

LilycoveCity_Harbor_EventScript_SetHasOldSeaMap::
	addvar VAR_TEMP_A, 4
	return

LilycoveCity_Harbor_EventScript_SetHasMysticTicket::
	addvar VAR_TEMP_A, 8
	return

LilycoveCity_Harbor_EventScript_EonTicketFirstTime::
	setflag FLAG_SHOWN_EON_TICKET
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
	msgbox EventTicket_Text_ShowEonTicket, MSGBOX_DEFAULT
	goto LilycoveCity_Harbor_EventScript_GoToSouthernIslandFirstTime
	end

LilycoveCity_Harbor_EventScript_GoToSouthernIslandFirstTime::
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 13, 22
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_AuroraTicketFirstTime::
	setflag FLAG_SHOWN_AURORA_TICKET
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
	msgbox EventTicket_Text_OddTicketGetOnBoard, MSGBOX_DEFAULT
	goto LilycoveCity_Harbor_EventScript_GoToBirthIslandFirstTime
	end

LilycoveCity_Harbor_EventScript_GoToBirthIslandFirstTime::
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_BIRTH_ISLAND_HARBOR, 8, 4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_OldSeaMapFirstTime::
	setflag FLAG_SHOWN_OLD_SEA_MAP
	msgbox EventTicket_Text_ShowOldSeaMap, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
	msgbox EventTicket_Text_OldSeaMapTooFar, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayNorth
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayEast
	addobject LOCALID_BRINEY
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_BrineyFaceSailorNorth
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_BrineyFaceSailorEast
	msgbox EventTicket_Text_BrineyHoldOnASecond, MSGBOX_DEFAULT
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_BrineyFacePlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_BrineyFacePlayerEast
	msgbox EventTicket_Text_BrineyLetsSail, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorNorth
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorEast
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepart
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToFarawayIslandFirstTime::
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_MysticTicketFirstTime::
	setflag FLAG_SHOWN_MYSTIC_TICKET
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
	msgbox EventTicket_Text_OddTicketGetOnBoard, MSGBOX_DEFAULT
	goto LilycoveCity_Harbor_EventScript_GoToNavelRockFirstTime
	end

LilycoveCity_Harbor_EventScript_GoToNavelRockFirstTime::
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_NAVEL_ROCK_HARBOR, 8, 4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_MultipleEventTicketsFirstTime::
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
	message EventTicket_Text_OddTicketsWhereTo
	waitmessage
	setvar VAR_0x8004, 1
	special ScriptMenu_CreateLilycoveSSTidalMultichoice
	waitstate
	special GetLilycoveSSTidalSelection
	switch VAR_RESULT
	case 2, LilycoveCity_Harbor_EventScript_GoToSouthernIslandFirstTime
	case 3, LilycoveCity_Harbor_EventScript_GoToNavelRockFirstTime
	case 4, LilycoveCity_Harbor_EventScript_GoToBirthIslandFirstTime
	case 5, LilycoveCity_Harbor_EventScript_GoToFarawayIslandFirstTime
	case 6, LilycoveCity_Harbor_EventScript_ExitFirstTimeTicketSailSelect
	case MULTI_B_PRESSED, LilycoveCity_Harbor_EventScript_ExitFirstTimeTicketSailSelect
	release
	end

LilycoveCity_Harbor_EventScript_ExitFirstTimeTicketSailSelect::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	removeobject LOCALID_FERRY_SAILOR
	delay 30
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	showobjectat LOCALID_ATTENDANT, MAP_LILYCOVE_CITY_HARBOR
	delay 30
	msgbox LilycoveCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_GetEventTicketSailor::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_LILYCOVE_CITY_HARBOR
	delay 60
	addobject LOCALID_FERRY_SAILOR
	delay 30
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_FacePlayer
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BoardFerryWithSailor::
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	removeobject LOCALID_FERRY_SAILOR
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_PlayerBoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_PlayerBoardFerryEast
	delay 30
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

LilycoveCity_Harbor_EventScript_FerryUnavailable::
	msgbox LilycoveCity_Harbor_Text_FerryUnavailable, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_NoEventTickets::
	msgbox LilycoveCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message LilycoveCity_Harbor_Text_FlashTicketWhereTo
	waitmessage
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
	end

@ Unused
LilycoveCity_Harbor_EventScript_NoTicket::
	msgbox LilycoveCity_Harbor_Text_NoTicket, MSGBOX_DEFAULT
	release
	end

@ Unused
LilycoveCity_Harbor_EventScript_GoToSlateportUnused::
	msgbox LilycoveCity_Harbor_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
	waitstate
	release
	end

@ Unused
LilycoveCity_Harbor_EventScript_GoToBattleFrontierUnused::
	msgbox LilycoveCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind::
	message LilycoveCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
	end

LilycoveCity_Harbor_EventScript_BoardFerry::
	msgbox LilycoveCity_Harbor_Text_PleaseBoard, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_LILYCOVE_CITY_HARBOR
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_PlayerBoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_PlayerBoardFerryEast
	delay 30
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

LilycoveCity_Harbor_EventScript_PlayerBoardFerryEast::
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardFerryEast
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_PlayerBoardFerryNorth::
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardFerryNorth
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_ExitSailSelect::
	msgbox LilycoveCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_Movement_PlayerBoardFerryEast:
	walk_right
	walk_in_place_faster_up
	step_end

LilycoveCity_Harbor_Movement_PlayerBoardFerryNorth:
	walk_up
	step_end

LilycoveCity_Harbor_Movement_UnusedBoardFerry:
	walk_up
	step_end

LilycoveCity_Harbor_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_Harbor_EventScript_SailorFerryAvailable
	msgbox LilycoveCity_Harbor_Text_SailorFerryUnavailable, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_SailorFerryAvailable::
	msgbox LilycoveCity_Harbor_Text_SailorFerryAvailable, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayNorth::
	applymovement LOCALID_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorOutOfWayNorth
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayEast::
	applymovement LOCALID_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorOutOfWayEast
	waitmovement 0
	return

LilycoveCity_Harbor_Movement_SailorOutOfWayNorth:
	walk_in_place_faster_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_Harbor_Movement_SailorOutOfWayEast:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

LilycoveCity_Harbor_EventScript_BrineyFaceSailorNorth::
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BrineyFaceSailorEast::
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BrineyFacePlayerNorth::
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BrineyFacePlayerEast::
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorNorth::
	applymovement LOCALID_BRINEY, LilycoveCity_Harbor_Movement_BrineyBoardFerry
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyNorth
	applymovement LOCALID_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorBoardWithBrineyNorth
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorEast::
	applymovement LOCALID_BRINEY, LilycoveCity_Harbor_Movement_BrineyBoardFerry
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyEast
	applymovement LOCALID_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorBoardWithBrineyEast
	waitmovement 0
	return

LilycoveCity_Harbor_Movement_BrineyBoardFerry:
	walk_in_place_faster_up
	delay_8
	set_invisible
	step_end

LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyNorth:
	delay_16
	walk_up
	delay_16
	set_invisible
	step_end

LilycoveCity_Harbor_Movement_SailorBoardWithBrineyNorth:
	delay_16
	delay_16
	delay_16
	walk_right
	walk_in_place_faster_up
	delay_16
	set_invisible
	step_end

LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyEast:
	delay_16
	walk_right
	walk_in_place_faster_up
	delay_16
	set_invisible
	step_end

LilycoveCity_Harbor_Movement_SailorBoardWithBrineyEast:
	delay_16
	delay_16
	delay_16
	walk_up
	delay_16
	set_invisible
	step_end

LilycoveCity_Harbor_Text_FerryUnavailable:
	.string "I beg your pardon?\n"
	.string "You're looking for a ship?\p"
	.string "I'm sorry, the ferry service isn't\n"
	.string "available at present…$"

LilycoveCity_Harbor_Text_MayISeeYourTicket:
	.string "Hello, are you here for the ferry?\n"
	.string "May I see your TICKET?$"

LilycoveCity_Harbor_Text_NoTicket:
	.string "{PLAYER} doesn't have the TICKET…\p"
	.string "I'm terribly sorry.\p"
	.string "You must have a TICKET to board\n"
	.string "the ferry.$"

LilycoveCity_Harbor_Text_FlashTicketWhereTo:
	.string "{PLAYER} flashed the TICKET.\p"
	.string "Perfect! That's all you need!\p"
	.string "And where would you like to go?$"

LilycoveCity_Harbor_Text_SailAnotherTime:
	.string "Please sail with us another time!$"

LilycoveCity_Harbor_Text_SlateportItIs:
	.string "SLATEPORT CITY it is, then!$"

LilycoveCity_Harbor_Text_BattleFrontierItIs:
	.string "BATTLE FRONTIER it is, then!$"

LilycoveCity_Harbor_Text_PleaseBoard:
	.string "Please board the ferry and wait for\n"
	.string "departure.$"

LilycoveCity_Harbor_Text_WhereWouldYouLikeToGo:
	.string "Then, where would you like to go?$"

LilycoveCity_Harbor_Text_SailorFerryUnavailable:
	.string "Until they finish making the ferry,\n"
	.string "we sailors have nothing to do…\p"
	.string "I wish they'd get a move on, the folks\n"
	.string "at the SHIPYARD in SLATEPORT.$"

LilycoveCity_Harbor_Text_SailorFerryAvailable:
	.string "The ferry S.S. TIDAL is finally in\n"
	.string "operation.\p"
	.string "The folks at the SHIPYARD in SLATEPORT\n"
	.string "must've worked extra hard.\p"
	.string "Well, it's my turn to get busy now!$"

LilycoveHarbor_FerryAttendantDynamic_Text_0:
	.string "The ferry to SLATEPORT is…\p"
	.string "Oh? That PASS…$"

LilycoveHarbor_FerryAttendantDynamic_Text_1:
	.string "I'm sorry, the ferry service isn't\n"
	.string "available at the moment due to\l"
	.string "maintenance.\p"
	.string "Sorry for the inconvenience.$"

LilycoveHarbor_PushDynTickets_Text_0:
	.string "{STR_VAR_1}$"

LilycoveHarbor_SelectedSSTicket_Text_0:
	.string "Slateport City$"

LilycoveHarbor_SelectedSSTicket_Text_1:
	.string "Battle Frontier$"

LilycoveHarbor_SelectedMysticTicket_Text_0:
	.string "We're setting sail for Navel Rock!$"

LilycoveHarbor_SelectedEonTicket_Text_0:
	.string "We're setting sail for the Southern\n"
	.string "Island!$"

LilycoveHarbor_SelectedAuroraTicket_Text_0:
	.string "We're setting sail for Birth Island!$"

LilycoveHarbor_SelectedOldSeaMap_Text_0:
	.string "We're setting sail for Faraway Island!$"

LilycoveHarbor_SelectedLibertyPass_Text_0:
	.string "Is it you who brought that odd ticket?\p"
	.string "Ahh... I recognise this place.\p"
	.string "It's for an island known as Liberty\n"
	.string "Garden, not far west of Castelia City\l"
	.string "in the Unova region.$"

LilycoveHarbor_SelectedLibertyPass_Text_1:
	.string "You do realise, this ticket is from\n"
	.string "Unova right?! The Hoenn ferry service\l"
	.string "doesn't provide passage there.$"

LilycoveHarbor_SelectedLibertyPass_Text_2:
	.string "Hmmmmm...\p"
	.string "Unova is VERY far away from here...\p"
	.string "It would probably take at least 3 days\n"
	.string "of sailing there, 3 days back, minimum...\l"
	.string "likely some rougher currents... a bottle\l"
	.string "of whiskey or two...$"

LilycoveHarbor_SelectedLibertyPass_Text_3:
	.string "You know what?\p"
	.string "I think we can make the journey. I\n"
	.string "really need to strech my sea legs out\l"
	.string "after all this time anyway. Yarrr!\p"
	.string "This won't be a free trip however.\p"
	.string "Given the time and distance, this\n"
	.string "voyage will come at a hefty cost of\l"
	.string "¥10000.\p"
	.string "Pretty standard for sea travel of this\n"
	.string "sort.$"

LilycoveHarbor_SelectedLibertyPass_Text_4:
	.string "So what do you say? ¥10000 for a trip\n"
	.string "to Liberty Garden?$"

LilycoveHarbor_SelectedLibertyPass_Text_5:
	.string "We're setting sail for the Libery Garden\n"
	.string "in Unova. All aboard!$"

LilycoveHarbor_SelectedLibertyPass_Text_6:
	.string "You might want to check your cash first\n"
	.string "before you think about travelling\l"
	.string "abroad...\p"
	.string "$"

LilycoveHarbor_SelectedLibertyPass_Text_7:
	.string "I understand, voyages of this kind do\n"
	.string "not come cheap.$"

LilycoveHarbor_SailorComeBackIfYouChangeYourMind_Text_0:
	.string "Come back and talk to me again if you\n"
	.string "change your mind lad.$"

LilycoveHarbor_SailorComeBackIfYouChangeYourMind_Text_1:
	.string "Come back and talk to me again if you\n"
	.string "change your mind lass.$"

LilycoveHarbor_SailorReturns_Text_0:
	.string "Please come back again.$"

LilycoveHarbor_LadyFetchesSailor_Text_0:
	.string "Hold on, let me find someone who can\n"
	.string "help you better.$"
