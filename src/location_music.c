#include "location_music.h"
#include "include/sound.h"
#include "constants/songs.h"

u8 GetRegionForMapSec(u8 mapSec)
{
    return 0;
}

u16 ConvertFanfareMusToLocationFanfareMus(u16 mus, u8 mapSec)
{
    switch (mus)
    {
        case MUS_OBTAIN_ITEM:
            return GetLocationFanfareItemPickup(mapSec);
        default:
            return mus;
    }
}

// Region Specific
u16 GetRegionMusicTrainerBattle(u8 region)
{
    switch (region)
    {
        default:
            return MUS_VS_TRAINER;
    }
}

u16 GetRegionMusicWildBattle(u8 region)
{
    switch (region)
    {
        default:
            return MUS_VS_WILD;
    }
}

u16 GetRegionMusicTrainerVictory(u8 region)
{
    switch (region)
    {
        default:
            return MUS_VICTORY_TRAINER;
    }
}

u16 GetRegionMusicWildVictory(u8 region)
{
    switch (region)
    {
        default:
            return MUS_VICTORY_WILD;
    }
}

u16 GetRegionMusicSurf(u8 region)
{
    switch (region)
    {
        default:
            return MUS_SURF;
    }
}

u16 GetRegionFanfareItemPickup(u8 region)
{
    switch (region)
    {
        default:
            return FANFARE_OBTAIN_ITEM;
    }
}

// Location Specific 

u16 GetLocationMusicTrainerBattle(u8 mapSec)
{
    switch (mapSec)
    {
        default:
            return GetLocationMusicTrainerBattle(GetRegionForMapSec(mapSec));
    }
}

u16 GetLocationMusicWildBattle(u8 mapSec)
{
    switch (mapSec)
    {
        default:
            return GetRegionMusicWildBattle(GetRegionForMapSec(mapSec));
    }
}

u16 GetLocationMusicTrainerVictory(u8 mapSec)
{
    switch (mapSec)
    {
        default:
            return GetRegionMusicTrainerVictory(GetRegionForMapSec(mapSec));
    }
}

u16 GetLocationMusicWildVictory(u8 mapSec)
{
    switch (mapSec)
    {
        default:
            return GetRegionMusicWildVictory(GetRegionForMapSec(mapSec));
    }
}

u16 GetLocationMusicSurf(u8 mapSec)
{
    switch (mapSec)
    {
        default:
            return GetRegionMusicSurf(GetRegionForMapSec(mapSec));
    }
}

u16 GetLocationFanfareItemPickup(u8 mapSec)
{
    switch (mapSec)
    {
        default:
            return GetRegionFanfareItemPickup(GetRegionForMapSec(mapSec));
    }
}
