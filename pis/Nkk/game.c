#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"


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

void StartGame(Game* game) {
	while (true) {
		display_board(game->board);
		int row, col;
		printf("Player %c's turn\n", game->current_player->symbol);
		printf("Enter row (0-%d): ", BOARD_SIZE - 1);
		scanf("%d", &row);
		printf("Enter column (0-%d): ", BOARD_SIZE - 1);
		scanf("%d", &col);
		if (!is_valid_move(game->board, row, col)) {
			printf("Invalid move, try again\n");
			continue;
		}
		game->board[row][col] = game->current_player->symbol;
		if (check_win(game->board, game->current_player->symbol)) {
			printf("Player %c wins!\n", game->current_player->symbol);
			break;
		}
		if (game->current_player == &game->player1) {
			game->current_player = &game->player2;
		}
		else {
			game->current_player = &game->player1;
		}
	}
	display_board(game->board);
	save_game_prompt(game);
	destroy_game(game);
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

// void add_to_linked_list(LinkedList* list, Game* game) {
// 	if (list == NULL) {
// 		perror("Error: list is NULL\n");
// 		return;
// 	}
// 	if (game == NULL) {
// 		perror("Error: game is NULL\n");
// 		return;
// 	}
// 	Node* new_node = (Node*)malloc(sizeof(Node));
// 	new_node->game = game;
// 	new_node->next = NULL;
// 	if (list->head == NULL) {
// 		list->head = new_node;
// 		list->tail = new_node;
// 	}
// 	else {
// 		list->tail->next = new_node;
// 		list->tail = new_node;
// 	}
// }

// void remove_from_linked_list(LinkedList* list, Game* game) {
// 	if (list == NULL) {
// 		perror("Error: list is NULL\n");
// 		return;
// 	}
// 	if (game == NULL) {
// 		perror("Error: game is NULL\n");
// 		return;
// 	}
// 	Node* prev = NULL;
// 	Node* curr = list->head;
// 	while (curr != NULL) {
// 		if (curr->game == game) {
// 			if (prev == NULL) {
// 				list->head = curr->next;
// 			}
// 			else {
// 				prev->next = curr->next;
// 			}
// 			if (curr == list->tail) {
// 				list->tail = prev;
// 			}
// 			free(curr);
// 			return;
// 		}
// 		prev = curr;
// 		curr = curr->next;
// 	}
// }

// void traverse_linked_list(LinkedList* list, void (*callback)(Game*)) {
// 	if (list == NULL) {
// 		perror("Error: list is NULL\n");
// 		return;
// 	}
// 	if (callback == NULL) {
// 		perror("Error: callback is NULL\n");
// 		return;
// 	}
// 	Node* curr = list->head;
// 	while (curr != NULL) {
// 		callback(curr->game);
// 		curr = curr->next;
// 	}
// }

