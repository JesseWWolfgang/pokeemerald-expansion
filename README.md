# feature/enhanced-movement

Adds extra features related to event object movement.

## Elevation Locking

Adds 2 script commands for locking the elevation of event objects to the desired elevation and resetting.

They can be used as such using 4 as the desired elevation to lock at:

```
lockelevation(GFX_ID_XYZ, 4)
resetelevation(GFX_ID_XYZ)
```

## Force Facing

Adds 4 movement commands that will change the facing direction of an object regardless of the `facingDirectionLocked` bit flag on
the event object that is set with the `lock_facing_direction` and `unlock_facing_direction` movement commands.

- `force_face_down`
- `force_face_up`
- `force_face_left`
- `force_face_right`

Additionally adds 2 movement types that use these forced facing movements:

- `MOVEMENT_TYPE_FORCE_ROTATE_COUNTERCLOCKWISE`
- `MOVEMENT_TYPE_FORCE_ROTATE_CLOCKWISE`

## Fast Diagonal Walk

Adds fast variants for each of the diagonal movement types.

## Movement based on player facing direction

Adds a script macro to apply a given movement to an event object based on the facing direction of the player.

```
applymovementplayerfacing(GFX_ID_XYZ, north, south, east, west)
```

Can also be used like this when the names of movements are quite large:

```
applymovementplayerfacing(GFX_ID_XYZ, 
    north, 
    south, 
    east, 
    west)
```

## Face Object and Face Away Object

Adds movement types 

- `face_object`
- `face_away_object` 

and corresponding 

- `Common_Movement_FaceObject` 
- `Common_Movement_FaceAwayObject` 

These perform the same as `face_player` and `face_away_player` but instead of facing towards the player object, the 
moving object will face in the direction of the object stored in `VAR_TARGET_OBJECT_EVENT`.

This var is reset to 0xFF (empty) upon loading a map just the same as the temp vars, so it should be set before using these movements.

## Improved Facing Direction

Adds a config option `OW_USE_IMPROVED_FACING_DIRECTION` in `include/config/overworld.h` to improve the way 
that `GetDirectionToFace` behaves. (used by `face_player` and `face_object` etc)

This will choose the direction that faces along the axis that has the longer displacement, instead of instantly preferring left/right.

## Face Player Movement Type

Adds the `MOVEMENT_TYPE_FACE_PLAYER` movement type.
This will make the object always face the player.