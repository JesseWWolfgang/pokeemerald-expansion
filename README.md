# merge/overworld-pokemon

Adds object graphics events for all Pokemon up to generation 7.
https://github.com/ghoulslash/pokeemerald/tree/overworld-expansion

Uses the overworld expansion for 16bit ids:
merge/overworld-expansion

## How to use

All Pokemon overworld sprites are disabled by default to avoid blowing the ROM size out the window.

For comparison:

*Without*
```
Memory region         Used Size  Region Size  %age Used
           EWRAM:      245762 B       256 KB     93.75%
           IWRAM:       30428 B        32 KB     92.86%
             ROM:    24109488 B        32 MB     71.85%
```

To enable specific species (or all of them), uncomment their respective lines in the following files.
First entry in each file is included for searching:

1. **src/data/object_events/object_event_graphics_info_pointers.h**
    ```c
    extern const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Pokemon_Species_001;
    ```
    ```c
    [OBJ_EVENT_GFX_POKEMON_001] = 	&gObjectEventGraphicsInfo_Pokemon_Species_001,
    ```

2. **src/data/object_events/object_event_graphics_info.h**
    ```c
    const struct ObjectEventGraphicsInfo gObjectEventGraphicsInfo_Pokemon_Species_001 = { 0xFFFF, OBJ_EVENT_PAL_TAG_POKEMON_001, OBJ_EVENT_PAL_TAG_NONE, 512, 32, 32, 0, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gObjectEventBaseOam_32x32, sOamTables_32x32, sAnimTable_PokemonSpecies, gObjectEventPicTable_Pokemon_Species_001, gDummySpriteAffineAnimTable};
    ```

3. **src/data/object_events/object_event_graphics.h**
    ```c
    const u32 gObjectEventPic_Pokemon_Species_001[] = INCBIN_U32("graphics/object_events/pics/pokemon/species/001.4bpp");
    const u16 gObjectEventPalette_Pokemon_Species_001[] = INCBIN_U16("graphics/object_events/pics/pokemon/species/001.gbapal");
    ```

4. **src/data/object_events/object_event_pic_tables.h**
    ```c
    const struct SpriteFrameImage gObjectEventPicTable_Pokemon_Species_001[] = {
        overworld_frame(gObjectEventPic_Pokemon_Species_001, 4, 4, 0),
        overworld_frame(gObjectEventPic_Pokemon_Species_001, 4, 4, 1),
        overworld_frame(gObjectEventPic_Pokemon_Species_001, 4, 4, 2),
        overworld_frame(gObjectEventPic_Pokemon_Species_001, 4, 4, 3),
        overworld_frame(gObjectEventPic_Pokemon_Species_001, 4, 4, 4),
        overworld_frame(gObjectEventPic_Pokemon_Species_001, 4, 4, 5),
        overworld_frame(gObjectEventPic_Pokemon_Species_001, 4, 4, 6),
        overworld_frame(gObjectEventPic_Pokemon_Species_001, 4, 4, 7),
        overworld_frame(gObjectEventPic_Pokemon_Species_001, 4, 4, 8),
    };
    ```

5. **src/event_object_movement.c**
    ```c
    {gObjectEventPalette_Pokemon_Species_001, OBJ_EVENT_PAL_TAG_POKEMON_001},
    ```

6. **spritesheet_rules.mk**
    ```mk
    $(OBJEVENTGFXDIR)/pokemon/species/001.4bpp: %.4bpp: %.png
        $(GFX) $< $@ -mwidth 4 -mheight 4
    ```

## Other notes

In **include/constants/event_objects.h** the define for the object event remains visible.
This means that Porymap will see it by default, but cannot access its graphics, and the game will not recognise it.
```c
#define OBJ_EVENT_GFX_POKEMON_001		(NUM_REGULAR_OBJ_EVENT_GFX + 0)
```

The same holds true for the palette tag entries in **src/event_object_movement.c**
```c
#define OBJ_EVENT_PAL_TAG_POKEMON_001 (OBJ_EVENT_PAL_TAG_POKEMON_START  + 1)
```

## Adding new entries

Just simply include a similar item for each of these files mentioned above. Listed below for reference:

- include/constants/event_objects.h
- src/data/object_events/object_event_graphics_info_pointers.h
- src/data/object_events/object_event_graphics_info.h
- src/data/object_events/object_event_graphics.h
- src/data/object_events/object_event_pic_tables.h
- src/event_object_movement.c
- spritesheet_rules.mk

You can always do a search for `_69` for example to find places that `OBJ_EVENT_GFX_POKEMON_069` or `gObjectEventPicTable_Pokemon_Species_069` are used etc.

Make sure to include the 4bpp indexed png graphics in **graphics/object_events/pics/pokemon/species**
