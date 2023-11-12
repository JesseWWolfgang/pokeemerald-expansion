LilycoveCity_LilycoveMuseum_Exterior_MapScripts::
	.byte 0


MysteryGiftGirl_GiveItems::
	lock
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_ENABLE_SHIP_LIBERTY_GARDEN
	goto_if_unset FLAG_LILYCOVE_MYSTERYGIFT_GIRL_SPOKEN, MysteryGiftGirl_GiveItems_2
	msgbox MysteryGiftGirl_GiveItems_Text_2, MSGBOX_NPC
MysteryGiftGirl_GiveItems_1:
	waitmessage
	pokemart MysteryGiftGirl_Items
	release
	return

MysteryGiftGirl_GiveItems_2:
	setflag FLAG_LILYCOVE_MYSTERYGIFT_GIRL_SPOKEN
	msgbox MysteryGiftGirl_GiveItems_Text_0, MSGBOX_SIGN
	closemessage
	playse SE_M_ICY_WIND
	waitse
	msgbox MysteryGiftGirl_GiveItems_Text_1, MSGBOX_NPC
	goto MysteryGiftGirl_GiveItems_1


	.align 2
MysteryGiftGirl_Items:
	.2byte ITEM_MYSTIC_TICKET
	.2byte ITEM_EON_TICKET
	.2byte ITEM_AURORA_TICKET
	.2byte ITEM_OLD_SEA_MAP
	.2byte ITEM_LIBERTY_PASS
	.2byte ITEM_WHITE_ROCK
	.2byte ITEM_ENIGMA_BERRY
	.2byte ITEM_NONE

LilycoveLookout_Sign::
	msgbox LilycoveLookout_Sign_Text_0, MSGBOX_SIGN
	return


MysteryGiftGirl_GiveItems_Text_0:
	.string "............\p"
	.string "You know... I come from a very distant\n"
	.string "land.\p"
	.string "I have travelled to wonderous places\n"
	.string "and seen many beautiful things.\p"
	.string "But this spot right where I'm standing...\n"
	.string "I just can't help but feel this is where\l"
	.string "I really belong...$"

MysteryGiftGirl_GiveItems_Text_1:
	.string "Do you feel that breeze?{PAUSE 60}\n"
	.string "Pleasant isn't it?\p"
	.string "Thank you for listening to me.\p"
	.string "In my travels, I came across a couple of\n"
	.string "curiosities that perhaps you would\l"
	.string "find interesting. Want to take a look?$"

MysteryGiftGirl_GiveItems_Text_2:
	.string "Oh hello again. Interested in my curious\n"
	.string "items?$"

LilycoveLookout_Sign_Text_0:
	.string "{UP_ARROW} LILYCOVE LOOKOUT$"
