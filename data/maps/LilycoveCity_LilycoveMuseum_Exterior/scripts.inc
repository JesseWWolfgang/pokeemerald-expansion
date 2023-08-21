LilycoveCity_LilycoveMuseum_Exterior_MapScripts::
	.byte 0


MysteryGiftGirl_GiveItems::
	msgbox MysteryGiftGirl_GiveItems_Text_0, MSGBOX_SIGN
	msgbox MysteryGiftGirl_GiveItems_Text_1, MSGBOX_NPC
	closemessage
	playse SE_M_RAZOR_WIND
	waitse
	msgbox MysteryGiftGirl_GiveItems_Text_2, MSGBOX_NPC
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	pokemart MysteryGiftGirl_Items
	return


	.align 2
MysteryGiftGirl_Items:
	.2byte ITEM_EON_TICKET
	.2byte ITEM_AURORA_TICKET
	.2byte ITEM_MYSTIC_TICKET
	.2byte ITEM_OLD_SEA_MAP
	.2byte ITEM_ENIGMA_BERRY
	.2byte ITEM_NONE

MysteryGiftGirl_GiveItems_Text_0:
	.string "............\p"
	.string "I'm from a distant land. I have\n"
	.string "travelled to countless places and seen\l"
	.string "many things.\p"
	.string "But this spot right where I'm standing...\n"
	.string "It is where I truly feel I belong...\p"
	.string "$"

MysteryGiftGirl_GiveItems_Text_1:
	.string "Do you smell the breeze?$"

MysteryGiftGirl_GiveItems_Text_2:
	.string "Pleasant isn't it? Thank you for\n"
	.string "listening to me.\p"
	.string "In my travels, I came across some\n"
	.string "curious items that you would perhaps\l"
	.string "like. Want to take a look?$"
