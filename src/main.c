#define _CRT_SECURE_NO_WARNINGS
// izabrao sam camelCase za nazive varijabli i funkcija

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

    // kreiraneje ploce

	Board* board = createBoard();

    // Kreiranje igraca
    Player *player1 = createPlayer("Player 1", 'X');
    Player *player2 = createPlayer("Player 2", 'O');

    // Kreiranje igre
    Game *game = createGame(board, player1, player2);

    // Pokretanje igre
    startGame(game);

  
    freeBoard(board);
    freePlayer(player1);
    freePlayer(player2);
    freeGame(game);

    return 0;
}