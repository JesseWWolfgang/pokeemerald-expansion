CasteliaCity_LibertyPier_MapScripts::
	.byte 0


CasteliaCity_SailorInteract::
	lock
	faceplayer
	msgbox CasteliaCity_SailorInteract_Text_0, MSGBOX_DEFAULT
	dynmultichoice 1, 1, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CasteliaCity_SailorInteract_Text_1, CasteliaCity_SailorInteract_Text_2
	switch VAR_RESULT
	case 0, CasteliaCity_SailorInteract_3
CasteliaCity_SailorInteract_1:
	release
	return

CasteliaCity_SailorInteract_3:
	call CasteliaCity_AskHomeOrCasteliaCity
	goto CasteliaCity_SailorInteract_1


CasteliaCity_AskHomeOrCasteliaCity::
	msgbox CasteliaCity_AskHomeOrCasteliaCity_Text_0, MSGBOX_DEFAULT
	dynmultichoice 1, 1, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CasteliaCity_AskHomeOrCasteliaCity_Text_1, CasteliaCity_AskHomeOrCasteliaCity_Text_2
	switch VAR_RESULT
	case 0, CasteliaCity_AskHomeOrCasteliaCity_2
	case 1, CasteliaCity_AskHomeOrCasteliaCity_3
	return

CasteliaCity_AskHomeOrCasteliaCity_2:
	msgbox CasteliaCity_AskHomeOrCasteliaCity_Text_3, MSGBOX_NPC
	call CasteliaCity_DepartWithSailor
	warp MAP_LIBERTY_GARDEN_EXTERIOR, 6, 15
	waitstate
	return

CasteliaCity_AskHomeOrCasteliaCity_3:
	msgbox CasteliaCity_AskHomeOrCasteliaCity_Text_4, MSGBOX_NPC
	call CasteliaCity_DepartWithSailor
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
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


CasteliaCity_CafeSonataLady::
	msgbox CasteliaCity_CafeSonataLady_Text_0, MSGBOX_NPC
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


CasteliaCity_InterviewerF::
	lock
	msgbox CasteliaCity_InterviewerF_Text_0, MSGBOX_DEFAULT
	release
	return


CasteliaCity_InterviewerM::
	msgbox CasteliaCity_InterviewerM_Text_0, MSGBOX_NPC
	return


CasteliaCity_Chef::
	lock
	msgbox CasteliaCity_Chef_Text_0, MSGBOX_DEFAULT
	release
	return


CasteliaCity_SailorInteract_Text_0:
	.string "Let me know when you are ready to\n"
	.string "depart.$"

CasteliaCity_SailorInteract_Text_1:
	.string "Let's go$"

CasteliaCity_SailorInteract_Text_2:
	.string "Stay$"

CasteliaCity_AskHomeOrCasteliaCity_Text_0:
	.string "Do you want to go to Liberty Garden not\n"
	.string "far west of here?\p"
	.string "Or do you want to head back to Lilycove\n"
	.string "City in Hoenn.\p"
	.string "What do you reckon?$"

CasteliaCity_AskHomeOrCasteliaCity_Text_1:
	.string "Liberty Garden$"

CasteliaCity_AskHomeOrCasteliaCity_Text_2:
	.string "Lilycove City$"

CasteliaCity_AskHomeOrCasteliaCity_Text_3:
	.string "Alright, off to Liberty Garden. We're\n"
	.string "setting sail!$"

CasteliaCity_AskHomeOrCasteliaCity_Text_4:
	.string "We've a few days travel ahead of us! All\n"
	.string "aboard for the Hoenn region!$"

CasteliaCity_LibertyPierSign_Text_0:
	.string "Castelia City\n"
	.string "Liberty Pier$"

CasteliaCity_FleaMarketsSign_Text_0:
	.string "Castelia City's Flea Markets!\n"
	.string "Permanently set up for all your\l"
	.string "second-hand shopping needs!$"

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

CasteliaCity_CafeSonataLady_Text_0:
	.string "Oh hello there youngster. Wondering\n"
	.string "where I got this coffee from?\p"
	.string "A café that I visit often, just down the\n"
	.string "road here and up a narrow street, it's\l"
	.string "easy to miss.$"

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

CasteliaCity_InterviewerF_Text_0:
	.string "Can you tell us more about what diners\n"
	.string "can expect at your legendary\l"
	.string "restaurant?\p"
	.string "I hear the legendary boeuf bourguignon\n"
	.string "is simply divine...$"

CasteliaCity_InterviewerM_Text_0:
	.string "Get out of the way kid.\l"
	.string "We're busy interviewing this fine\l"
	.string "gentleman...$"

CasteliaCity_Chef_Text_0:
	.string "...with the most exquisite views of the\n"
	.string "Castelia City harbour...\p"
	.string "...finest of chefs and staff with\n"
	.string "unparalleled expertise...\p"
	.string "...our menu is simply unmatched anywhere\n"
	.string "else in the city...\p"
	.string "...always served the absolute finest of\n"
	.string "dishes...$"
