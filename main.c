#include <stdio.h>
#include <stdlib.h>
#include "place.h"
#include "player.h"
#include "time.h"

// All of the places you can visit in the game
const int places_count = 5;
const Place places[] = {
    {
        .name = "Forest",
        .message = "You eat berries in the forest"
                   ", and then are attacked by bees.",
        .modifier_count = 2,
        .modifiers = {
            {Hunger, 10},
            {Health, -5}
        }
    },
    {
        .name = "Desert",
        .message = "You find little water in the desert"
                   ", and then are attacked by tumbleweeds",
        .modifier_count = 2,
        .modifiers = {
            {Health, -5},
            {Thirst, -15}
        }
    },
    {
        .name = "Valley",
        .message = "You find water and berries"
                   "and dance with the unicorns",
        .modifier_count = 3,
        .modifiers = {
            {Health, 5},
            {Thirst, 10},
            {Hunger, 4}
        }
    },
    {
        .name = "Mars",
        .message = "There really are Martians",
        .modifier_count = 3,
        .modifiers = {
            {Health, 30},
            {Thirst, -20},
            {Hunger, -20}
        }
    },
    {
        .name = "Mountain",
        .message = "You're freezing ❄",
        .modifier_count = 2,
        .modifiers = {
            {Health, -20},
            {Hunger, -10}
        }
    }
};

// Returns a random integer between 0 and max
int get_random_int(int max) {
    return rand() % max;
}

int main() {
    // Seed the random by the current time.
    srand(time(NULL));

    // Create a new player
    Player player;
    player_init(&player);

    // 1 is true, 0 is false
    char is_playing = 1;

    int turn = 0;

    // Game loop
    while (is_playing) {
        printf("\nDay %d\n", turn);
        player_display(&player);

        // Pick a random place
        int a_index = get_random_int(places_count);
        Place a = places[a_index];

        int b_index = get_random_int(places_count);
        Place b = places[b_index];

        turn++;

        // While the player is choosing a valid option
        // (i.e. keep asking until they choose a valid option)
        while (1) {
            printf("Please choose an area: \n");
            printf(" - 1. %s \n", a.name);
            printf(" - 2. %s \n", b.name);
            printf("Enter a number: ");
            int choice;
            scanf("%d", &choice);

            if (choice == 1) {
                player_visit_place(&player, &a);
                break;
            } else if (choice == 2) {
                player_visit_place(&player, &b);
                break;
            } else {
                printf("Please enter either 1 or 2\n");
            }
        }

        if (player.health <= 0) {
            printf("You ran out of food\n");
            break;
        }

        if (player.thirst <= 0) {
            printf("You ran out of water\n");
            break;
        }

        if (player.health <= 0) {
            printf("You ran out of health\n");
            break;
        }
    }

    printf("You lasted %d days\n", turn);
}