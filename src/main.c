#define _CRT_SECURE_NO_WARNINGS
// izabrao sam camelCase za nazive varijabli i funkcija

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../headers/board.h"
#include "../headers/game.h"
#include "../headers/player.h"
// define const borad size


int main()
{

    srand((unsigned)time(NULL));
    // alociraj memoriju za plocu
    //Board* board = NULL;
    //printf("%p\n", (void*)board);

    char board[BOARD_SIZE][BOARD_SIZE];
    //board = calloc(BOARD_SIZE * BOARD_SIZE, sizeof(char));
    //printf("%p\n", (void*)board);
    //if (board == NULL) {
    //    perror("Failed to allocate memory for board");
    //    exit(EXIT_FAILURE);
    //}
    //printf("%p\n", (void*)board);
    //
    // inicijalizacija ploce
    initializeBoard(board, BOARD_SIZE);



	//Board* board = createBoard();

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