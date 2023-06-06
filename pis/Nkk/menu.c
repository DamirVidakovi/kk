#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"

void display_menu() {
	// new game
// load game
// list saved games
	//help
	// high scores
// quit
	printf("1. New Game\n");
	printf("2. Load Game\n");
	printf("3. High Scores\n");
	printf("4. Help\n");
	printf("5. Quit\n");

	printf("Enter choice: ");
	int choice;
	scanf("%d", &choice);
	switch (choice) {
		case 1:
			// new game
			StartGame();
			break;
		case 2:
			// load game
			loadSubMenu();
			break;
		case 3:
			// high scores
			break;
		case 4:
			// help
			break;
		case 5:
			// quit
			break;
		default:
			printf("Invalid choice\n");
			break;
	}

}

void loadSubMenu() {
	printf("1. Show previus Games\n");

	printf("2. Delete Game\n");
	printf("3. Back\n");
	printf("Enter choice: ");
	int choice;
	scanf("%d", &choice);
	switch (choice) {
		case 1:
			// load game

			break;
		case 2:
			// delete game
			break;
		case 3:
			// back
			break;
		default:
			printf("Invalid choice\n");
			break;
	}
}

void help() {
	printf("\n");
}