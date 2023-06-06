#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	// load saved games
	FILE* index_file = fopen("saved_games_index.bin", "rb");
	if (index_file != NULL) {
		fread(&num_saved_games, sizeof(int), 1, index_file);
		for (int i = 0; i < num_saved_games; i++) {
			char filename[256];
			fread(filename, sizeof(char), 256, index_file);
			Game* game = load_game(filename);
			if (game != NULL) {
				saved_games[i].game = game;
				saved_games[i].filename = (char*)malloc(256 * sizeof(char));
				strcpy(saved_games[i].filename, filename);
			}
		}
		fclose(index_file);
	}
	// create game
	Game* game = create_game();
	// game loop
	while (true) {
		// display board
		display_board(game->board);
		// get user input
		int row, col;
		printf("Player %c's turn\n", game->current_player->symbol);
		printf("Enter row (0-%d): ", BOARD_SIZE - 1);
		scanf("%d", &row);
		printf("Enter column (0-%d): ", BOARD_SIZE - 1);
		scanf("%d", &col);
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
		else {
			game->current_player = &game->player1;
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
	for (int i = 0; i < num_saved_games; i++) {
		free(saved_games[i].filename);
		saved_games[i].filename = NULL;
		destroy_game(saved_games[i].game);
		saved_games[i].game = NULL;
	}
	// save index of saved games
	index_file = fopen("saved_games_index.bin", "wb");
	if (index_file != NULL) {
		fwrite(&num_saved_games, sizeof(int), 1, index_file);
		for (int i = 0; i < num_saved_games; i++) {
			fwrite(saved_games[i].filename, sizeof(char), 256, index_file);
		}
		fclose(index_file);
	}

	return 0;
}