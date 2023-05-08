// tic tac toe simulator for the command line

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../headers/board.h"
#include "../headers/game.h"
#include "../headers/player.h"

int main()
{

    srand((unsigned)time(NULL));

    // create the board
    Board *board = createBoard();

    // create the players
    Player *player1 = createPlayer("Player 1", 'X');
    Player *player2 = createPlayer("Player 2", 'O');

    // create the game
    Game *game = createGame(board, player1, player2);

    // start the game
    startGame(game);

    // free the memory
    freeBoard(board);
    freePlayer(player1);
    freePlayer(player2);
    freeGame(game);

    return 0;
}