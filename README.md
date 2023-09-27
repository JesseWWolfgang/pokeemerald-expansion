# base/main

A branch that contains all the bare-minimum additions plus many extra features
and merged branches to make development or gameplay easier and better.

This wont contain huge style changes such as the HGSS Pokedex or the DPPt Summary Screen
since they might not be ideal for all ROM Hacks.

Contains:
- base/bare-minimum
- feature/shiny-wild-special-handling
- feature/forbidden-shop-items
- feature/ipatix-mixer
- feature/available-mystery-gifts
- feature/general-improvements
- feature/trainers-throw-pokeball
- merge/item-desc-header
- merge/namebox
- merge/dynmulti

**Keep in mind**: Always double check `data/script_cmd_table.inc` and `asm/macros/event.inc` to ensure the byte value of instructions are correct after merging other features into this branch. E.g. ensure `0xe5` does not overlap between `ScrCmd_setspeaker` and `ScrCmd_showitemdesc`.

# base/bare-minimum

The bare minimum code required to make effective and instant development with Pokeemerald and the RHH Expansion.

Contains:
- Updated Makefile
- Porymap and Poryscript support
- Helper scripts for running Porymap and mGBA.
- VSCode files for
    - C/C++ configuration
    - Launch and Task files for debugging with mGBA
    - Bookmarks for useful code locations.
    - Extensions that are very useful for pokeemerald development.
    - Standard settings

# Helpful Links

|Page|URL|
|----|---|
pokeemerald Github                      | https://github.com/pret/pokeemerald
pokeemerald Wiki Tutorials              | https://github.com/pret/pokeemerald/wiki/Tutorials
pokeemerald-expansion Github            | https://github.com/rh-hideout/pokeemerald-expansion
pokeemerald-expansion Wiki              | https://github.com/rh-hideout/pokeemerald-expansion/wiki
`agbcc` Github                          | https://github.com/pret/agbcc
DevkitPro Pacman                        | https://devkitpro.org/wiki/devkitPro_pacman
Porymap Github                          | https://github.com/huderlem/porymap
Poryscript Github                       | https://github.com/huderlem/poryscript
Scripting Reference (non-poryscript)    | https://www.pokecommunity.com/showthread.php?t=416800
CyanSMP64's Music Expansion Github      | https://github.com/CyanSMP64/pokeemerald
How To Understand Music in Pokeemerald  | https://www.pokecommunity.com/showthread.php?t=444317
