#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/board.h"

Board *createBoard() {
    printf("Creating board...\n");

    // allocate memory for board
    char **board = (char **)malloc(3 * sizeof(char *));
    for (int i = 0; i < 3; i++) {
        board[i] = (char *)malloc(3 * sizeof(char));
    }

    // initialize board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }

    // allocate memory for Board struct
    Board *b = (Board *)malloc(sizeof(Board));
    b->board = board;

    return b;
}

void printBoard(char **board)
{
    // protection 
    if (board == NULL)
    {
        perror("Board je NULL");
        exit(EXIT_FAILURE);
    }
    printf("   1   2   3\n");
    printf("1  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("  ---+---+---\n");
    printf("2  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("  ---+---+---\n");
    printf("3  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);



}

void freeBoard(Board *board)
{
    //15. Sigurno brisanje memorije koja je dinamički zauzeta, anuliranje memorijskog prostora, provjera 
    //pokazivača kako se ne bi dogodila pogreška double free() i anuliranje svih pokazivača koji su bili
    //usmjereni na memorijski prostor koji se dinamički zauzeo.
    if (board != NULL)
    {
        free(board);
        board = NULL;
    }

    
    for (int i = 0; i < 3; i++)
    {
        free(board->board[i]);
    }

    free(board->board);
    free(board);
}
int isGameOver(Board *board, Player *player1, Player *player2) {

    // parametar protection
    if (board == NULL || player1 == NULL || player2 == NULL)
    {
        perror("Board ili player je NULL");
        exit(EXIT_FAILURE);
    }
    // check if the game is over
    int gameOver = 0;
    int turn = 0;
    int moves = 0;
    for (int i = 0; i < 3; i++) {
        // check rows
        if (board->board[i][0] == board->board[i][1] && board->board[i][1] == board->board[i][2] && board->board[i][0] != '-') {
            gameOver = 1;
        }

        // check columns
        if (board->board[0][i] == board->board[1][i] && board->board[1][i] == board->board[2][i] && board->board[0][i] != '-') {
            gameOver = 1;
        }
    }

    // check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[1][1] == board->board[2][2] && board->board[0][0] != '-') {
        gameOver = 1;
    }
    if (board->board[0][2] == board->board[1][1] && board->board[1][1] == board->board[2][0] && board->board[0][2] != '-') {
        gameOver = 1;
    }

    // count the number of moves
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board->board[i][j] != '-') {
                moves++;
            }
        }
    }

    // update the turn based on the number of moves
    if (moves % 2 == 0) {
        turn = 0;
    } else {
        turn = 1;
    }

    // print the winner
    if (gameOver) {
        printf("Game over! %s wins!\n", turn == 0 ? player1->name : player2->name);
    } else if (moves == 9) {
        printf("Game over! It's a tie!\n");
    }
}