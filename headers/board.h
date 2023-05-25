#ifndef BOARD_H
#define BOARD_H

#include "../headers/player.h"

// define const int board size
#define BOARD_SIZE 3

typedef struct Board
{
    char **board;
    int size;
} Board;


char initializeBoard(char **board, int size);
void printBoard(char **board);
void freeBoard(Board *board);
int isGameOver(Board *board, Player *player1, Player *player2);


#endif // BOARD_H
