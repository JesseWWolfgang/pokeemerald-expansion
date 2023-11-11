# merge/dynmulti

Implements SBird's dynamic multilist.

## Empty item callback

A modification has been made to allow the `DYN_MULTICHOICE_CB_SHOW_ITEM` callback to hide the
auxilliary item display window when the selected item is `ITEM_NONE` or 0 instead of showing the question mark icon.