#ifndef PLACE_H
#define PLACE_H

// Represents a kind of stat, such as hunger, thirst, health, etc.
// Enums become numbers when compiled, so they're an efficient way
// of storing values.
typedef enum StatKind StatKind;
enum StatKind {
    Hunger = 1,
    Thirst = 2,
    Health = 3
};

// We could theoretically have done this instead:
// int Hunger = 1;
// int Thirst = 2;
// int Health = 3;

// Holds a kind of stat, and how much it should increase or decrease
typedef struct Modifier Modifier;
struct Modifier {
    StatKind kind;
    int amount;
};

// A place the player can visit. May lower or raise stats depending on
// the modifiers it has.
typedef struct Place Place;
struct Place {
    char * name;
    char * message;
    Modifier modifiers[3];
    unsigned char modifier_count;
};

#endif
