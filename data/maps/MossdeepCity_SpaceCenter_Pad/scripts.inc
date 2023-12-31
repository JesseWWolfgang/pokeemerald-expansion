MossdeepCity_SpaceCenter_Pad_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

MossdeepCity_SpaceCenter_Pad_MapScripts_MAP_SCRIPT_ON_LOAD:
	setflag FLAG_TEMP_1
	return


TEST_Warp_to_Castelia::
	warp MAP_CASTELIA_CITY_LIBERTY_PIER, 0
	waitstate
	return


MossdeepCity_SpaceCenter_Pad_Sign::
	msgbox MossdeepCity_SpaceCenter_Pad_Sign_Text_0, MSGBOX_SIGN
	return


MossdeepCity_SpaceCenter_Pad_GuideLady::
	lock
	faceplayer
	msgbox MossdeepCity_SpaceCenter_Pad_GuideLady_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MossdeepCity_SpaceCenter_Pad_GuideLady_2
MossdeepCity_SpaceCenter_Pad_GuideLady_1:
	release
	return

MossdeepCity_SpaceCenter_Pad_GuideLady_2:
	msgbox MossdeepCity_SpaceCenter_Pad_GuideLady_Text_1, MSGBOX_DEFAULT
	warp MAP_MOSSDEEP_CITY_SPACE_CENTER_1F, 7, 3
	waitstate
	goto MossdeepCity_SpaceCenter_Pad_GuideLady_1


MossdeepCity_SpaceCenter_Pad_Sign_Text_0:
	.string "Mossdeep Space Center Launch Pad$"

MossdeepCity_SpaceCenter_Pad_GuideLady_Text_0:
	.string "Are you not prepared? Would you like to\n"
	.string "return inside?$"

MossdeepCity_SpaceCenter_Pad_GuideLady_Text_1:
	.string "Okay, but please don't dawdle, you are\n"
	.string "due to leave imminently.$"
