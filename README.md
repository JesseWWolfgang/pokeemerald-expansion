# merge/dynmulti

Implements SBird's feature/dynmulti branch from:
https://github.com/SBird1337/pokeemerald/tree/feature/dynmulti

Thread with description can be found here:
https://www.pokecommunity.com/showthread.php?t=489984

Short description:
```
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