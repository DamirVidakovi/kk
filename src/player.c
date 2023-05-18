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
    //15. Sigurno brisanje memorije koja je dinamički zauzeta, anuliranje memorijskog prostora, provjera 
    //pokazivača kako se ne bi dogodila pogreška double free() i anuliranje svih pokazivača koji su bili
    //usmjereni na memorijski prostor koji se dinamički zauzeo.
    if (player != NULL)
    {
        free(player->name);
        player->name = NULL;
        free(player);
        player = NULL;
    }

    free(player);
}
