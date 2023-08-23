# merge/dynmulti

Manually Implements SBird's feature/dynmulti branch from:
https://github.com/SBird1337/pokeemerald/tree/feature/dynmulti

Manually merged due to this being based on RHH Expansion.

Thread with description can be found here:
https://www.pokecommunity.com/showthread.php?t=489984

## Simple Example

```c
dynmultichoice(left, top, ignoreBPress, maxBeforeScroll, initialSelected, callbacks, "Option 1", "Option 2", "Option 3", ...)
```

with the following arguments:

- left: The x offset of the menu (in tiles / units of 8 pixels)
- top (the y offset of the menu, in tiles / units of 8 pixels)
- ignoreBPress: Whether the menu should stay open if the user presses the B Button
- maxBeforeScroll: The maximum amount of items shown before the menu scrolls
- initialSelected: Variable or static value that determines the initially selected item
- callbacks: The event callbacks of the menu. For a simple menu supply DYN_MULTICHOICE_CB_NONE
- ...: Any number of menu options can follow after these arguments

When the menu is closed by player interaction, it will return the selected option index in VAR_RESULT. If the user aborted the menu by pressing the B Button, it will return 127.

## Dynamic Example

```c
dynmultipush("First option", 0)
if (flag(FLAG_SYS_GAME_CLEAR)) {
   dynmultipush("Secret option", 1)
}
dynmultistack(left, top, ignoreBPress, maxBeforeScroll, shouldSort, initialSelected, callbacks)
```

dynmultistack behaves just like dynmultichoice with the addition of a shouldSort argument, that determines whether the list should be sorted according to the IDs you pass to dynmultipush. The latter also accepts variables as its second argument.


## Poryscript Example

```c
script DynChoiceTest {
	lock
    
    // Simple test
	msgbox(format("Testing simple multichoice:"), MSGBOX_NPC)
	dynmultichoice(15, 6, FALSE, 4, 0, DYN_MULTICHOICE_CB_SHOW_ITEM, "Mew", "Deoxys", "Celebi", "Victini", "Jirachi", "Arceus", "Cresselia")
	buffernumberstring(STR_VAR_1, VAR_RESULT)
	msgbox("You chose {STR_VAR_1} fool!", MSGBOX_NPC)

    // Dynamic test
	msgbox(format("Testing dynamic multichoice:"), MSGBOX_NPC)
	dynmultipush("Mew", 151)
	dynmultipush("Deoxys", 386)
	dynmultipush("Arceus", 493)
	dynmultistack(15, 6, FALSE, 4, FALSE, 386, DYN_MULTICHOICE_CB_NONE)
	buffernumberstring(STR_VAR_1, VAR_RESULT)
	msgbox("You chose {STR_VAR_1} fool!", MSGBOX_NPC)

	release
}
```

## More Complex Example

```c
script EventScript_MultichoiceTests {
    lock 
    faceplayer
    msgbox (LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_DEFAULT)

    // random items with visualization example

    random(ITEMS_COUNT)
    bufferitemname(STR_VAR_1, VAR_RESULT)
    dynmultipush("{STR_VAR_1}", VAR_RESULT)
    random(ITEMS_COUNT)
    bufferitemname(STR_VAR_2, VAR_RESULT)
    dynmultipush("{STR_VAR_2}", VAR_RESULT)
    random(ITEMS_COUNT)
    bufferitemname(STR_VAR_3, VAR_RESULT)
    dynmultipush("{STR_VAR_3}", VAR_RESULT)
    dynmultistack(0, 0, TRUE, 6, FALSE, VAR_0x800A, DYN_MULTICHOICE_CB_SHOW_ITEM)

    // inline example without scrolling

    dynmultichoice(0,0, TRUE, 6, 0, DYN_MULTICHOICE_CB_NONE, "Option 1", "Option 2", "Option 3")

    // inline example with scrolling

    dynmultichoice(0,0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, "Option 1", "Option 2", "Option 3", "Option 4")

    buffernumberstring(STR_VAR_1, VAR_RESULT)
    msgbox("{STR_VAR_1}", MSGBOX_DEFAULT)
    closemessage
    release
    end
}
```