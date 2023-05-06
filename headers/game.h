#ifndef GAME_H
#define GAME_H

#include "../headers/player.h"
#include "../headers/board.h"

typedef struct Game
{
    Player *player1;
    Player *player2;
    Board *board;
} Game;

Game *createGame(Board *board, Player *player1, Player *player2);

void startGame(Game *game);

void freeGame(Game *game);


#endif // GAME_H