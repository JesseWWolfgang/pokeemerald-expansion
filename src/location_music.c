#include "location_music.h"
#include "constants/songs.h"

u16 GetLocationMusicTrainerBattle(u8 mapSec)
{
    switch (mapSec)
    {
        case MAPSEC_LIBERTY_GARDEN:
        case MAPSEC_CASTELIA_CITY:
        case MAPSEC_CAFE_SONATA:
        case MAPSEC_UNOVA_ROUTE_17:
        case MAPSEC_P2_LABORATORY:
            return MUS_UNOVA_TRAINER;
        default:
            return MUS_VS_TRAINER;
    }
}

u16 GetLocationMusicWildBattle(u8 mapSec)
{
    switch (mapSec)
    {
        case MAPSEC_LIBERTY_GARDEN:
        case MAPSEC_CASTELIA_CITY:
        case MAPSEC_CAFE_SONATA:
        case MAPSEC_UNOVA_ROUTE_17:
        case MAPSEC_P2_LABORATORY:
            return MUS_UNOVA_WILD;
        default:
            return MUS_VS_WILD;
    }
}

u16 GetLocationMusicTrainerVictory(u8 mapSec)
{
    switch (mapSec)
    {
        case MAPSEC_LIBERTY_GARDEN:
        case MAPSEC_CASTELIA_CITY:
        case MAPSEC_CAFE_SONATA:
        case MAPSEC_UNOVA_ROUTE_17:
        case MAPSEC_P2_LABORATORY:
            return MUS_UNOVA_TRAINER_VICTORY;
        default:
            return MUS_VICTORY_TRAINER;
    }
}

u16 GetLocationMusicWildVictory(u8 mapSec)
{
    switch (mapSec)
    {
        case MAPSEC_LIBERTY_GARDEN:
        case MAPSEC_CASTELIA_CITY:
        case MAPSEC_CAFE_SONATA:
        case MAPSEC_UNOVA_ROUTE_17:
        case MAPSEC_P2_LABORATORY:
            return MUS_UNOVA_WILD_VICTORY;
        default:
            return MUS_VICTORY_WILD;
    }
}