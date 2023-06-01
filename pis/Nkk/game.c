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

void destroy_game(Game* game) {
	if (game == NULL) {
		perror("Error: game is NULL\n");
		return;
	}
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

void save_game(Game* game, const char* filename) {
	if (game == NULL) {
		perror("Error: game is NULL\n");
		return;
	}
	FILE* file = fopen(filename, "wb");
	if (file == NULL) {
		printf("Error: could not open file %s for writing\n", filename);
		return;
	}
	fwrite(game, sizeof(Game), 1, file);
	fclose(file);
	printf("Game saved to %s\n", filename);
}

Game* load_game(const char* filename) {
	FILE* file = fopen(filename, "rb");
	if (file == NULL) {
		printf("Error: could not open file %s for reading\n", filename);
		return NULL;
	}
	Game* game = (Game*)malloc(sizeof(Game));
	fread(game, sizeof(Game), 1, file);
	fclose(file);
	printf("Game loaded from %s\n", filename);
	return game;
}

void list_saved_games() {
	printf("Saved games:\n");
	for (int i = 0; i < num_saved_games; i++) {
		printf("%d. %s\n", i + 1, saved_games[i].filename);
	}
}

void save_game_prompt(Game* game) {
	if (game == NULL) {
		perror("Error: game is NULL\n");
		return;
	}

	// check if we have space for another saved game
	if (num_saved_games == MAX_SAVED_GAMES) {
		perror("Error: no space for another saved game\n");
		return;
	}
	char filename[256];
	printf("Enter filename to save game: ");
	scanf("%s", filename);
	save_game(game, filename);
}

void load_game_prompt() {
	list_saved_games();
	int choice;
	printf("Enter number of game to load: ");
	scanf("%d", &choice);
	if (choice < 1 || choice > num_saved_games) {
		printf("Invalid choice\n");
		return;
	}
	Game* game = load_game(saved_games[choice - 1].filename);
	if (game != NULL) {
		destroy_game(game);
	}
}