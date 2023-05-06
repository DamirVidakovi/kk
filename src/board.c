#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/board.h"

void createBoard()
{
    printf("Creating board...\n");

    // allocate memory for the board
    char **board = (char **)malloc(3 * sizeof(char *));
    for (int i = 0; i < 3; i++)
    {
        board[i] = (char *)malloc(3 * sizeof(char));
    }

    // initialize the board
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '-';
        }
    }

 
}

void printBoard(char **board)
{
  
    // print the board
    printf("  0 1 2\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < 3; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void freeBoard(Board *board)
{
    // free the memory
    for (int i = 0; i < 3; i++)
    {
        free(board->board[i]);
    }
    free(board->board);
    free(board);
}

void isGameOver(Board *board, Player *player1, Player *player2)
{
    // check if the game is over
    int gameOver = 0;
    for (int i = 0; i < 3; i++)
    {
        // check rows
        if (board->board[i][0] == board->board[i][1] && board->board[i][1] == board->board[i][2] && board->board[i][0] != '-')
        {
            gameOver = 1;
        }

        // check columns
        if (board->board[0][i] == board->board[1][i] && board->board[1][i] == board->board[2][i] && board->board[0][i] != '-')
        {
            gameOver = 1;
        }
    }

    // check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[1][1] == board->board[2][2] && board->board[0][0] != '-')
    {
        gameOver = 1;
    }
    if (board->board[0][2] == board->board[1][1] && board->board[1][1] == board->board[2][0] && board->board[0][2] != '-')
    {
        gameOver = 1;
    }

    // check if the game is a tie
    int tie = 1;
    if (!gameOver)
    {
        for (int i = 0; i < 3; i++)
        {
            // check rows
            if (board->board[i][0] == '-' || board->board[i][1] == '-' || board->board[i][2] == '-')
            {
                tie = 0;
            }
        }
    }

    // print the winner
    if (gameOver)
    {
        printf("Game over! %s wins!\n", turn == 0 ? player1->name : player2->name);
    }
    else if (tie)
    {
        printf("Game over! It's a tie!\n");
    }
}
