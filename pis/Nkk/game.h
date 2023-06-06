#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

#define BOARD_SIZE 3
#define MAX_SAVED_GAMES 5

//define a struct for a linked list node
typedef struct node {
	void* data;
	struct node* next;
} Node;

//define a struct for a linked list
typedef struct {
	Node* head;
	Node* tail;
} LinkedList;

// define num_saved_games and saved_games
int num_saved_games;
struct {
	char* filename;
	
} saved_games[MAX_SAVED_GAMES];

typedef struct {
	char* name;
	char symbol;
} Player;

typedef struct {
	char** board;
	Player player1;
	Player player2;
	Player* current_player;
} Game;

Game* create_game();
void StartGame();
void destroy_game(Game* game);
void display_board(char** board);
bool is_valid_move(char** board, int row, int col);
bool check_win(char** board, char symbol);
void save_game(Game* game, const char* filename);
Game* load_game(const char* filename);
void list_saved_games();
void save_game_prompt(Game* game);
void load_game_prompt();
void add_to_linked_list(void* data, void (*free_func)(void*));
void remove_from_linked_list(void* data, void (*free_func)(void*));
void traverse_linked_list(void (*callback)(void*));

#endif
