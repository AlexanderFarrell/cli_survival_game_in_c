#include <stdio.h>
#include <stdlib.h>
#include "player.h"

void input(char * destination_string, int limit) {
    // Actually get the user input from the console, up to *limit* characters.
    fgets(destination_string, limit, stdin);

    // Get rid of the new line
    for (int i = 0; i < limit; i++)
    {
        if (destination_string[i] == '\n') {
            destination_string[i] = '\0';
        }
    }
    return;
}

void player_init(Player* player) {
    printf("Enter the players name: ");
    input(player->name, PLAYER_NAME_SIZE_LIMIT);
    player->health = PLAYER_HEALTH;
    player->hunger = PLAYER_HUNGER;
    player->thirst = PLAYER_THIRST;
}

void player_display(Player* player) {
    printf("%s's stats: \n", player->name);
    printf(" - 💖 Health: %d\n", player->health);
    printf(" - 🍕 Hunger: %d\n", player->hunger);
    printf(" - 🌊 Thirst: %d\n", player->thirst);
}

void player_visit_place(Player* player, Place* place) {
    printf("You visit the %s \n", place->name);
    printf("%s\n", place->message);

    for (int i = 0; i < place->modifier_count; i++)
    {

        switch (place->modifiers[i].kind)
        {
        case Hunger:
            player->hunger += place->modifiers[i].amount;
            break;
        case Thirst:
            player->thirst += place->modifiers[i].amount;
            break;
        case Health:
            player->health += place->modifiers[i].amount;
            break;
        
        default:
            printf("WARNING: Unsupported modifier, add another near line %d in %s\n", __LINE__, __FILE__);
            break;
        }
    }
}