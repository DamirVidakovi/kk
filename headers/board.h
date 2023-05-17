#ifndef BOARD_H
#define BOARD_H

#include "../headers/player.h"

typedef struct Board
{
    char **board;
    int size;
} Board;


Board *createBoard();
void printBoard(char **board);
void freeBoard(Board *board);
int isGameOver(Board *board, Player *player1, Player *player2);


#endif // BOARD_H
