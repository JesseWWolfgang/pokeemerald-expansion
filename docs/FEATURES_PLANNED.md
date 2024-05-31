# Generic Usage VARs and FLAGs

Each of the special flags and vars would have their own special entries so as to not clog up the script ones.

## Vars for storing positions
- VAR_TEMP_POSX
- VAR_TEMP_POSY
- getplayerxyvar (same as getplayerxy but automatically loads these two vars)
- callifxy (calls a script if the values in these two vars match given params)

## Var for intentionally invoking a scene on next map load
- VAR_PLAY_SCENE_ON_MAP_LOAD

Value would indicate what scene to play (or a state to load).

# Actions and Movements

`makewayforplayer(canMoveN, canMoveS, canMoveE, canMoveW)`
Will move the object out of the way of the player, but not towards the player, or against any of the illegal movement direcitons.

# Speaking

`speak(name, obj)`
Can be used to set the name of the active speaker and make them walk-on-spot

# CopyFlag

`copyflag(from, to)`

# C Preprocessor on Pory files

# Play bgm if not already playing

`playbgmifnotalready(MUS_MT_CHIMNEY, TRUE)`
Same as `playbgm` but wont restart song if already playing.

# Preserve bgm on next map load.