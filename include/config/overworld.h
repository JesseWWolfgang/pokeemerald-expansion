#ifndef GUARD_CONFIG_OVERWORLD_H
#define GUARD_CONFIG_OVERWORLD_H

// Movement config
#define OW_RUNNING_INDOORS          GEN_LATEST  // In Gen4+, players are allowed to run indoors.

// Other settings
#define OW_POISON_DAMAGE            GEN_3 // In Gen4, Pokémon no longer faint from Poison in the overworld. In Gen5+, they no longer take damage at all.

// Overworld flags
// To use the following features in scripting, replace the 0s with the flag ID you're assigning it to.
// Eg: Replace with FLAG_UNUSED_0x264 so you can use that flag to toggle the feature.
#define OW_FLAG_NO_ENCOUNTER        FLAG_NO_ENCOUNTER  // If this flag is set, wild encounters will be disabled.
#define OW_FLAG_NO_TRAINER_SEE      FLAG_NO_TRAINER_SEE  // If this flag is set, trainers will not battle the player unless they're talked to.
#define OW_FLAG_NO_COLLISION        FLAG_NO_COLLISION  // If this flag is set, the player will be able to walk over tiles with collision. Mainly intended for debugging purposes.

// Whether the hidden door leading to the mystery gift area in the Lilycove museum can be unlocked
// from the start of the game. If FALSE, it can only be unlocked after beating the game.
#define OW_LILYCOVE_MYSTERYGIFT_ACCESSIBLE_FROM_START   TRUE

#endif // GUARD_CONFIG_OVERWORLD_H
