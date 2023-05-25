// save previous games and load them back from the bin file

#include "../headers/save.h"


void saveGame(Board *board, Player *player1, Player *player2)
{
    // open file
    FILE *file = fopen("game.bin", "wb");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // write board size
    fwrite(&board->size, sizeof(int), 1, file);

    // write board
    for (int i = 0; i < board->size; i++)
    {
        fwrite(board->board[i], sizeof(char), board->size, file);
    }

    // write player1
    fwrite(player1->name, sizeof(char), strlen(player1->name) + 1, file);
    fwrite(&player1->symbol, sizeof(char), 1, file);

    // write player2
    fwrite(player2->name, sizeof(char), strlen(player2->name) + 1, file);
    fwrite(&player2->symbol, sizeof(char), 1, file);

    // close file
    fclose(file);
}

void loadGame(FILE *file, Board *board, Player *player1, Player *player2)
{
    
    // open file
    FILE *file = fopen("game.bin", "rb");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // read board size
    fread(&board->size, sizeof(int), 1, file);

    // allocate memory for board
    board->board = (char **)malloc(board->size * sizeof(char *));
    if (board->board == NULL)
    {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < board->size; i++)
    {
        board->board[i] = (char *)malloc(board->size * sizeof(char));
        if (board->board[i] == NULL)
        {
            perror("Error allocating memory");
            exit(EXIT_FAILURE);
        }
    }

    // read board
    for (int i = 0; i < board->size; i++)
    {
        fread(board->board[i], sizeof(char), board->size, file);
    }

    // read player1
    player1->name = (char *)malloc(20 * sizeof(char));
    if (player1->name == NULL)
    {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    fread(player1->name, sizeof(char), 20, file);
    fread(&player1->symbol, sizeof(char), 1, file);

    // read player2
    player2->name = (char *)malloc(20 * sizeof(char));
    if (player2->name == NULL)
    {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    fread(player2->name, sizeof(char), 20, file);
    fread(&player2->symbol, sizeof(char), 1, file);

    // close file
    fclose(file);
}

void saveScore(Player *player1, Player *player2)
{
    // open file
    FILE *file = fopen("score.bin", "wb");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // write player1
    fwrite(player1->name, sizeof(char), strlen(player1->name) + 1, file);
    fwrite(&player1->score, sizeof(int), 1, file);

    // write player2
    fwrite(player2->name, sizeof(char), strlen(player2->name) + 1, file);
    fwrite(&player2->score, sizeof(int), 1, file);

    // close file
    fclose(file);
}

void loadScore(Player *player1, Player *player2)
{
    // open file
    FILE *file = fopen("score.bin", "rb");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // read player1
    player1->name = (char *)malloc(20 * sizeof(char));
    if (player1->name == NULL)
    {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    fread(player1->name, sizeof(char), 20, file);
    fread(&player1->score, sizeof(int), 1, file);

    // read player2
    player2->name = (char *)malloc(20 * sizeof(char));
    if (player2->name == NULL)
    {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    fread(player2->name, sizeof(char), 20, file);
    fread(&player2->score, sizeof(int), 1, file);

    // close file
    fclose(file);
}

