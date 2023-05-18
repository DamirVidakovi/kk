#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/game.h"

Game *createGame(Board *board, Player *player1, Player *player2)
{
    
    Game *game = (Game *)malloc(sizeof(Game));
    
    game->board = board;
    game->player1 = player1;
    game->player2 = player2;
    return game;
}

void startGame(Game *game)
{
    printf("Starting game...\n");

    // print the board
    printBoard(game->board->board);

    // randomly choose who goes first
    int turn = rand() % 2;
    printf("%s je prvi na potezu!\n", turn == 0 ? game->player1->name : game->player2->name);

    // play the game
    int gameOver = 0;
    while (!gameOver)
    {
        // get the current player
        Player *currentPlayer = turn == 0 ? game->player1 : game->player2;

        // get the current player's move
        int row, col;
        printf("%s, enter your move (row, col): ", currentPlayer->name);
        scanf("%d, %d", &row, &col);

        // update the board
        game->board->board[row][col] = currentPlayer->symbol;

        // print the board
        printBoard(game->board->board);

        // check if the game is over
        gameOver = isGameOver(game->board->board, game->player1->symbol, game->player2->symbol);

        // switch turns
        turn = turn == 0 ? 1 : 0;
    }

    // print the winner
    printf("Game over! %s wins!\n", turn == 0 ? game->player1->name : game->player2->name);
}

void freeGame(Game *game)
{

    //15. Sigurno brisanje memorije koja je dinamički zauzeta, anuliranje memorijskog prostora, provjera 
    //pokazivača kako se ne bi dogodila pogreška double free() i anuliranje svih pokazivača koji su bili
    //usmjereni na memorijski prostor koji se dinamički zauzeo.

    if (game != NULL)
    {
        freeBoard(game->board);
        game->board = NULL;
        freePlayer(game->player1);
        game->player1 = NULL;
        freePlayer(game->player2);
        game->player2 = NULL;
        free(game);
        game = NULL;
    }

}

