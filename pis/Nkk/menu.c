
#include "global.h"

#include "game.h"
#include "menu.h"


void help() {

	printf("Pravila igre:\n");
	printf("-----------\n");
	printf("Igra se igra na polju 3x3.\n");
	printf("Igrači naizmjence označavaju polje svojim simbolom (X ili O).\n");
	printf("Igrač koji uspije postaviti tri svoje oznake u vodoravni, okomiti ili dijagonalni red pobjeđuje u igri.\n");
	printf("Ako su sva polja označena i nijedan igrač nije pobijedio, igra je neriješena.\n");

}
void loadSubMenu(Game* game) {
	printf("1. Show previus Games\n");

	printf("2. Delete Game\n");
	// remove save file
	printf("3. remove save file\n");
	printf("3. Back\n");
	printf("Enter choice: ");
	int choice;
	scanf("%d", &choice);
	switch (choice) {
	case 1:
		// load previus games


		break;
	case 2:
		// delete game
		break;
	case 3:
		// back
		displayMenu(game);
		break;
	default:
		printf("Invalid choice\n");
		break;
	}
}

void displayMenu(Game* game) {
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
		int mode = choseMode();
		startGame(game, mode);
		break;
	case 2:
		// load game
		loadSubMenu(game);
		break;
	case 3:
		// high scores
		break;
	case 4:
		// help
		help();
		displayMenu(game);
		
	case 5:
		// quit
		break;
	default:
		printf("Invalid choice\n");
		break;
	}

}

