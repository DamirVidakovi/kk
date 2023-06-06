#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

#define BOARD_SIZE 3
#define MAX_SAVED_GAMES 10

typedef struct {
	char symbol;
} Player;

typedef struct {
	char** board;
	Player player1;
	Player player2;
	Player* current_player;
} Game;


typedef struct {
	Game* game;
	char* filename;
	
} SavedGame;

static SavedGame saved_games[MAX_SAVED_GAMES];
static int num_saved_games = 0;

void startGame(Game* game, mode);
Game* create_game();
void destroy_game(Game* game);
void display_board(char** board);
bool is_valid_move(char** board, int row, int col);
bool check_win(char** board, char symbol);
void save_game(Game* game, const char* filename);
Game* load_game(const char* filename);
void list_saved_games();
void save_game_prompt(Game* game);
void load_game_prompt();

#endif