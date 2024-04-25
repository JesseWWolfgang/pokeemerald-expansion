# feature/general-improvements

This branch contains a number of smaller fixes that dont warrant their own branch.

## Features

| Feature | Link/Description |
|---|------|
| Keep the Camera from Making Waves     | https://github.com/pret/pokeemerald/wiki/Keep-the-Camera-from-Making-Waves
| Better Reflection System              | https://github.com/pret/pokeemerald/wiki/Reflections
| Automatically make the keyboard switch to lowercase after the first character | https://github.com/pret/pokeemerald/wiki/Automatically-make-the-keyboard-switch-to-lowercase-after-the-first-character/
| Move Pokemon as first PC option       | https://www.pokecommunity.com/showpost.php?p=10065761
| Swap party slots with select          | https://www.pokecommunity.com/showpost.php?p=10420662
| Show species switching for in party menu | https://github.com/pret/pokeemerald/wiki/Show-Species-That-You're-Switching-For-in-the-Party-Menu
| Berries no longer disappear           | https://www.pokecommunity.com/showpost.php?p=10142996&postcount=63
| Disable union room check              | https://github.com/pret/pokeemerald/wiki/Disabling-Union-Room-check-when-entering-Pok%C3%A9mon-Centers
| Change direction while moving         | https://www.pokecommunity.com/showpost.php?p=10402610
| Flag to override map music            | Flag is FLAG_MAP_MUSIC_OVERRIDE and var is VAR_MAP_MUSIC_OVERRIDE.
| `getweather`                          | Adds a script command `getweather` which stores the current weather in VAR_RESULT.
| Extend trainer slide in message time  | Adds a small delay after a trainer slide in message.
| Enable HGSS Pokedex                   | Enables the HGSS style Pokedex by default.
| `ScrCmd_callfunc`                     | Script function to call a C function with a number of arguments. https://discord.com/channels/419213663107416084/419214240277200898/1168386523163525160  - credit: merrp
| Bugfix messageautoscroll persist      | Bugfix to prevent messageautoscroll from persisting after its use.
| `getmondataforpartymon`               | Script for obtaining MON_DATA of a party pokemon.
| `setmondataforpartymon`               | Script for setting MON_DATA of a party pokemon.
| `choosebagitem`                       | Script for opening the player's bag and choosing an item with customisable parameters.
| `showmonfieldmove` and `showpartymonfieldmove`    | Script for showing the 'use field move' animation (such as when using Cut or Rock Smash).
| `bufferstatname` and `buffernaturename`           | Script for buffering names of stats or natures to string vars.
| `setpartymonstat`, `setpartymonnature` and `clearpartymonEVs` | Scripts for settings the IVs, EVs and nature of a party mon.
| `recalculatepartymonstats`            | Script to recalculate party mon stats on the fly out of battle.
| `increment` and `decrement`           | Script to increment and decrement vars.
| VAR_TEMP_ITERATOR                     | Temp var that can be used as an iterator in combination with increment or decrement in script while loops.
| FLAG_ANY_MOVE_TEACHABLE               | Flag that can be set to allow all Pokemon to learn any move via tutor, TM, etc.
| Disable Boxmon Decryption and Substruct Randomisation | P_BOX_MON_ENCRYPTION and P_BOX_MON_SUBSTRUCT_RANDOMIZATION config options disable these respectively. FALSE by default.
| VAR_TEMP_LOADED                       | Var that can be used as the condition for executing on-load script events using MAP_SCRIPT_ON_FRAME_TABLE.
| `messageveryslowprint`                | Script for printing a message very slowly and ominously. Works the same way as `messageautoscroll`.

## Changes

- 1.7.3
    - Removed the Common FindItem script as it was merged into upstream expansion.
    
- 8671da4
    - Removed Bulk Premier Balls as it was merged into upstream expansion.

- 6c2c66b
    - Surfing Dismount Ground Effects was merged into upstream expansion.