#include "global.h"
#include "game.h"
#include "menu.h"

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

	displayMenu(game);

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