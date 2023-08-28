LibertyGarden_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LibertyGarden_1F_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

LibertyGarden_1F_MapScripts_MAP_SCRIPT_ON_LOAD:
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 11
	goto_if_le LibertyGarden_1F_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

LibertyGarden_1F_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	setweather WEATHER_SHADE
	return

