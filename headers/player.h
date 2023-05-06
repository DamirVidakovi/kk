#ifndef PLAYER_H
#define PLAYER_H


#include <string.h>
typedef struct Player
{
    char *name;
    char symbol;
} Player;

Player *createPlayer(char *name, char symbol);
void freePlayer(Player *player);

#endif // PLAYER_H