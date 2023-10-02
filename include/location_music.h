#ifndef GUARD_LOCATION_MUSIC_H
#define GUARD_LOCATION_MUSIC_H

#include "global.h"

u16 ConvertFanfareMusToLocationFanfareMus(u16 mus, u8 mapSec);

u16 GetRegionMusicTrainerBattle(u8 region);
u16 GetRegionMusicWildBattle(u8 region);
u16 GetRegionMusicTrainerVictory(u8 region);
u16 GetRegionMusicWildVictory(u8 region);
u16 GetRegionMusicSurf(u8 region);
u16 GetRegionFanfareItemPickup(u8 mapSec);

u16 GetLocationMusicTrainerBattle(u8 mapSec);
u16 GetLocationMusicWildBattle(u8 mapSec);
u16 GetLocationMusicTrainerVictory(u8 mapSec);
u16 GetLocationMusicWildVictory(u8 mapSec);
u16 GetLocationMusicSurf(u8 mapSec);
u16 GetLocationFanfareItemPickup(u8 mapSec);

#endif // GUARD_LOCATION_MUSIC_H