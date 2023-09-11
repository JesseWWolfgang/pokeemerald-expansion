#include "location_music.h"
#include "constants/songs.h"

u16 GetLocationMusicTrainerBattle(u8 mapSec)
{
    switch (mapSec)
    {
        default:
            return MUS_VS_TRAINER;
    }
}

u16 GetLocationMusicWildBattle(u8 mapSec)
{
    switch (mapSec)
    {
        default:
            return MUS_VS_WILD;
    }
}

u16 GetLocationMusicTrainerVictory(u8 mapSec)
{
    switch (mapSec)
    {
        default:
            return MUS_VICTORY_TRAINER;
    }
}

u16 GetLocationMusicWildVictory(u8 mapSec)
{
    switch (mapSec)
    {
        default:
            return MUS_VICTORY_WILD;
    }
}