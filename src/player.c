#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../headers/player.h"

Player *createPlayer(char *name, char symbol)
{
    Player *player = (Player *)malloc(sizeof(Player));
    player->name = name;
    player->symbol = symbol;
    return player;
}

void freePlayer(Player *player)
{
    free(player);
}
