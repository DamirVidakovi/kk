#ifndef PLAYER_H
#define PLAYER_H


#include <string.h>

 //3.Primjena typedef sa strukturama i unijama, po potrebi s enum tipovima podataka tamo gdje treba.

typedef struct Player
{
    char *name;
    char symbol;
} Player;

Player *createPlayer(char *name, char symbol);
void freePlayer(Player *player);
#endif // PLAYER_H