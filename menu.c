#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// main functions
#include "../headers/board.h"
#include "../headers/game.h"
#include "../headers/player.h"

// menu functions
#include "../headers/menu.h"

void mainMenu() {
    int choice = 0;
    while (choice != 5) {
        printf("Tik Tak Toe\n");
        printf("-----------\n");
        printf("1. Zapocni novu igru\n");
        printf("2. Load a saved game\n");
        printf("3. Save the current game\n");
        printf("4. View the game rules\n");
        printf("5. Exit the game\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Start a new game
                startGame(game);
                break;
            case 2:
                // Load a saved game
                loadMenu();
                break;
            case 3:
                // Save the current game
                saveMenu();
                break;
            case 4:
                pravila();
                break;
            case 5:
                // Exit the game
                printf("Dovidenja!\n");
                break;
            default:
                printf("Pogresan Unos \n");
                break;
        }
    }
}

void loadMenu() {
    
}
void pravila() {
    printf("Pravila igre:\n");
    printf("-----------\n");
    printf("Igra se igra na polju 3x3.\n");
    printf("Igrači naizmjence označavaju polje svojim simbolom (X ili O).\n");
    printf("Igrač koji uspije postaviti tri svoje oznake u vodoravni, okomiti ili dijagonalni red pobjeđuje u igri.\n");
    printf("Ako su sva polja označena i nijedan igrač nije pobijedio, igra je neriješena.\n");
}