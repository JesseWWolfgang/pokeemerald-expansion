# feature/lock-elevation

Adds 2 script commands for locking the elevation of event objects to the desired elevation and resetting.

They can be used as such using 4 as the desired elevation to lock at:

```
lockelevation GFX_ID_XYZ 4
resetelevation GFX_ID_XYZ
```

or in Poryscript:

```
lockelevation(GFX_ID_XYZ, 4)
resetelevation(GFX_ID_XYZ)
```
