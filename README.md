# feature/location-battle-music

Adds a collection of simple functions to control custom music for the following types of music based on the current MAPSEC or region:

- trainer battles
- wild battles
- trainer victory
- wild victory
- surfing

Functions are defined in:

`location_music.h` and `location_music.c`.

Uses:

- feature/multi-region: Allows specifying regions for each Mapsec.
- feature/default-legendary-music: The wild battle music call is routed through the new legendary music list.