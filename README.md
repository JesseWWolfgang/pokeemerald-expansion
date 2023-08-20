# base/main

A branch that contains all the bare-minimum additions plus many extra features
and merged branches to make development or gameplay easier and better.

This wont contain huge style changes such as the HGSS Pokedex or the DPPt Summary Screen
since they might not be ideal for all ROM Hacks.

Contains:
- base/bare-minimum
- feature/shiny-wild-special-handling
- feature/forbidden-shop-items
- merge/item-desc-header
- merge/namebox

**Keep in mind**: Always double check `data/script_cmd_table.inc` and `asm/macros/event.inc` to ensure the byte value of instructions are correct after merging other features into this branch. E.g. ensure `0xe5` does not overlap between `ScrCmd_setspeaker` and `ScrCmd_showitemdesc`.

# base/bare-minimum

The bare minimum code required to make effective and instant development with pokeemerald.

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

# pokeemerald Expansion

## What is the pokeemerald Expansion?

The Pokeemerald Expansion is a collection of feature branches that can be integrated into existing [pokeemerald](https://github.com/pret/pokeemerald) projects.

## What features are included?
- Upgraded battle engine.
    - Fairy Type.
    - Physical/Special/Status Category Split.
    - New moves and abilities up to SwSh.
    - Options to change behaviors and data by generation.
    - Mega Evolution and Primal Reversion
    - Z-Moves
- Pokémon Species from newer Generations (with the option to disable them if needed).
    - Updates Hoenn's Regional Dex to match ORAS'.
    - Updates National Dex incorporating all the new species.
    - Option to change base stats by generation.
    - New evolution methods.
    - Hidden Abilities data (How to make them available is up to the user).
- Items from newer Generations and updated item effects for battle and field use.

Certain mechanics, moves, abilities and species sprites are missing. For more information, see [the project's milestones](https://github.com/rh-hideout/pokeemerald-expansion/milestones).

### [Documentation on features can be found here](https://github.com/rh-hideout/pokeemerald-expansion/wiki)

## Who maintains the project?

The project was originally started by DizzyEgg alongside other contributors.

The project has now gotten larger and DizzyEgg is now maintaining the project as part of the ROM Hacking Hideout community. Some members of this community are taking on larger roles to help maintain the project.

### Please consider crediting the entire [list of contributors](https://github.com/rh-hideout/pokeemerald-expansion/wiki/Credits) in your project, as they have all worked hard to develop this project :)

## Can I contribute even if I'm not a member of ROM Hacking Hideout?

Yes! Contributions are welcome via Pull Requests and they will be reviewed by maintainers. Don't feel discouraged if we take a bit to review your PR, we'll get to it.

## What is ROM Hacking Hideout?

A Discord-based ROM hacking community that has many members who hack using the disassembly and decompilation projects for Pokémon. Quite a few contributors to the original feature branches by DizzyEgg were members of ROM Hacking Hideout. You can call it RHH for short!

[Click here to join the RHH Discord Server!](https://discord.gg/6CzjAG6GZk)
