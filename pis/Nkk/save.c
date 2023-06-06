#include "global.h"
#include "game.h"

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