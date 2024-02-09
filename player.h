#ifndef PLAYER_H
#define PLAYER_H

#include "place.h"

#define PLAYER_NAME_SIZE_LIMIT 30
#define PLAYER_HEALTH 100
#define PLAYER_HUNGER 100
#define PLAYER_THIRST 100

// Holds the player's name and stats.
typedef struct Player Player;
struct Player {
    char name[PLAYER_NAME_SIZE_LIMIT+1];
    int hunger;
    int thirst;
    int health;
};

// Sets up a new player
void player_init(Player* player);

// Displays the player and the player's stats to the console.
void player_display(Player* player);

// Have a player visit a place, applying each modifier.
void player_visit_place(Player* player, Place* place);

#endif