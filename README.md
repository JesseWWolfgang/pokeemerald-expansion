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
