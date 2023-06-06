#define _CRT_SECURE_NO_WARNINGS

#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Game* create_game() {
	if (BOARD_SIZE <= 0) {
		printf("Invalid board size\n");
		return NULL;
	}
	Game* game = (Game*)malloc(sizeof(Game));
	game->board = (char**)malloc(BOARD_SIZE * sizeof(char*));
	for (int i = 0; i < BOARD_SIZE; i++) {
		game->board[i] = (char*)malloc(BOARD_SIZE * sizeof(char));
		for (int j = 0; j < BOARD_SIZE; j++) {
			game->board[i][j] = ' ';
		}
	}
	game->player1.symbol = 'X';
	game->player2.symbol = 'O';
	game->current_player = &game->player1;
	return game;
}
int choseMode() {
	int mode;
	printf("Chose mode:\n");
	printf("1. Player vs Player\n");
	printf("2. Player vs Computer\n");
	printf("3. Computer vs Computer\n");
	scanf("%d", &mode);
	return mode;
}
// function to generate a random move for the computer player
void genCompMove(Game* game, int* row, int* col) {
    // seed the random number generator
    srand(time(NULL));
    // generate random row and column
    *row = rand() % BOARD_SIZE;
    *col = rand() % BOARD_SIZE;
    // check if move is valid
    while (!is_valid_move(game->board, *row, *col)) {
        // generate new random row and column
        *row = rand() % BOARD_SIZE;
        *col = rand() % BOARD_SIZE;
    }
}
void destroy_game(Game* game) {
	if (game == NULL) {
		perror("Error: game is NULL\n");
		return;
	}
}

void startGame(Game* game, int mode) {
		while (true) {
			// display board
			display_board(game->board);
			// get user input or generate computer move
			int row, col;
			if (game->current_player == &game->player1 || mode == 1) {
				printf("Player %c's turn\n", game->current_player->symbol);
				printf("Enter row (0-%d): ", BOARD_SIZE - 1);
				scanf("%d", &row);
				printf("Enter column (0-%d): ", BOARD_SIZE - 1);
				scanf("%d", &col);
			} else if (game->current_player == &game->player2 && mode == 2) {
				printf("Computer's turn\n");
				genCompMove(game, &row, &col);
				printf("Computer chose row %d, column %d\n", row, col);
			} else {
				printf("Computer 1's turn\n");
				genCompMove(game, &row, &col);
				printf("Computer 1 chose row %d, column %d\n", row, col);
			}
			// check if move is valid
			if (!is_valid_move(game->board, row, col)) {
				printf("Invalid move, try again\n");
				continue;
			}
			// update board
			game->board[row][col] = game->current_player->symbol;
			// check for win
			if (check_win(game->board, game->current_player->symbol)) {
				printf("Player %c wins!\n", game->current_player->symbol);
				break;
			}
			// switch players
			if (game->current_player == &game->player1) {
				game->current_player = &game->player2;
			}
			else if (game->current_player == &game->player2 && mode != 3) {
				game->current_player = &game->player1;
			} else {
				game->current_player = &game->player2;
			}
		}
		// display final board
		display_board(game->board);
		// prompt user to save game
		save_game_prompt(game);
		// prompt user to load game
		load_game_prompt();
		// free memory
		destroy_game(game);
	
	
	for (int i = 0; i < BOARD_SIZE; i++) {
		free(game->board[i]);
		game->board[i] = NULL;
	}
	free(game->board);
	game->board = NULL;
	free(game);
	game = NULL;
}

void display_board(char** board) {

    // protection W
    if (board == NULL)
    {
        perror("Board je NULL");
        exit(EXIT_FAILURE);
    }
    printf("   0   1   2\n");
    printf("0  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("  ---+---+---\n");
    printf("1  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("  ---+---+---\n");
    printf("2  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
	
}

bool is_valid_move(char** board, int row, int col) {
	if (board == NULL) {
		perror("Error: board is NULL\n");
		return false;
	}
	if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
		return false;
	}
	if (board[row][col] != ' ') {
		return false;
	}
	return true;
}

bool check_win(char** board, char symbol) {
	if (board == NULL) {
		perror("Error: board is NULL\n");
		return false;
	}
	// check rows
	for (int i = 0; i < BOARD_SIZE; i++) {
		bool win = true;
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] != symbol) {
				win = false;
				break;
			}
		}
		if (win) {
			return true;
		}
	}
	// check columns
	for (int j = 0; j < BOARD_SIZE; j++) {
		bool win = true;
		for (int i = 0; i < BOARD_SIZE; i++) {
			if (board[i][j] != symbol) {
				win = false;
				break;
			}
		}
		if (win) {
			return true;
		}
	}
	// check diagonals
	bool win = true;
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (board[i][i] != symbol) {
			win = false;
			break;
		}
	}
	if (win) {
		return true;
	}
	win = true;
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (board[i][BOARD_SIZE - i - 1] != symbol) {
			win = false;
			break;
		}
	}
	if (win) {
		return true;
	}
	return false;
}

