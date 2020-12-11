/****************************************
*   Title   :   [Naval Batlle]   *
*   Author  :   [Rajadurai - Thirusan]      *
*   Version :   [0.1]            *
****************************************/

#include <stdio.h>
#include <windows.h>
#include <ctype.h>
#include <stdbool.h>

int line;
int column;
int MenuChoice;
int playercolumn;
int playerline;
int line_input_number;
char column_input_letter;
char grid[10][10];
char coord_letter;
char playerGrid[10][10];
bool boat1_sunk = false;
bool boat2_sunk = false;
bool boat3_sunk = false;
bool boat4_sunk = false;
bool boat5_sunk = false;

void emptyBuffer() {
    int c = 0;
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

void show_help() {
    printf("HELP____________\n");
}


void grid_initialization() {
    for (line = 0; line < 9; line++) {                          //grid ini
        for (column = 0; column < 9; ++column) {
            grid[line][column] = ' ';
        }
    }


    for (line = 0; line < 9; line++) {                          //playersgrid ini
        for (column = 0; column < 9; ++column) {
            playerGrid[line][column] = ' ';
        }

    }


}


void show_grid() {
    printf("     ");
    for (coord_letter = 'A'; coord_letter <= 'J'; ++coord_letter) {
        printf("| %c ", coord_letter);
    }

    printf("||\n");
    for (int horizontal_separation = 0; horizontal_separation < 47; ++horizontal_separation) {
        printf("_");

    }

    printf("\n");
    int coord_number = 1;
    for (line = 0; line < 9; line++) {
        printf("|| %d ", coord_number);
        coord_number++;
        for (column = 0; column < 10; ++column) { printf("| %c ", grid[line][column]); }
        printf("||\n");
        for (int horizontal_separation = 0; horizontal_separation < 47; ++horizontal_separation) {
            printf("_");

        }
        printf("\n");
    }


    printf("||10 ");
    for (column = 0; column < 10; ++column) { printf("| %c ", grid[9][column]); }
    printf("||\n");
    for (int horizontal_separation = 0; horizontal_separation < 47; ++horizontal_separation) {
        printf("_");

    }
    printf("\n\n\n");
}

void show_player_grid() {
    printf("     ");
    for (coord_letter = 'A'; coord_letter <= 'J'; ++coord_letter) {
        printf("| %c ", coord_letter);
    }

    printf("||\n");
    for (int horizontal_separation = 0; horizontal_separation < 47; ++horizontal_separation) {
        printf("_");

    }

    printf("\n");
    int coord_number = 1;
    for (line = 0; line < 9; line++) {
        printf("|| %d ", coord_number);
        coord_number++;
        for (column = 0; column < 10; ++column) { printf("| %c ", playerGrid[line][column]); }
        printf("||\n");
        for (int horizontal_separation = 0; horizontal_separation < 47; ++horizontal_separation) {
            printf("_");

        }
        printf("\n");
    }


    printf("||10 ");
    for (column = 0; column < 10; ++column) { printf("| %c ", grid[9][column]); }
    printf("||\n");
    for (int horizontal_separation = 0; horizontal_separation < 47; ++horizontal_separation) {
        printf("_");

    }
    printf("\n\n\n");
}

void add_boats() {
    for (line = 2; line < 7; ++line) {                                               //porte-avions (boat1)
        grid[line][9] = 'X';

    }

    for (line = 2; line < 6; ++line) {                                               //croiseur (boat2)
        grid[line][7] = 'X';

    }

    for (column = 6;
         column < 9; ++column) {                                               //first contre-torpilleur (boat3)
        grid[0][column] = 'X';

    }

    for (column = 6;
         column < 9; ++column) {                                               //second1 contre-torpilleur (boat4)
        grid[8][column] = 'X';

    }

    for (line = 1; line < 3; ++line) {                                               //croiseur (boat5)
        grid[line][0] = 'X';

    }
}

void Menu() {
    printf("Bienvenue dans la bataille navale !\n\n"
           "Entrez 1 pour jouer\n"
           "Entrez 2 pour voir l'aide du jeu\n");
    scanf("%d", &MenuChoice);
    if (MenuChoice != 1 && MenuChoice != 2) {
        while (MenuChoice != 1 && MenuChoice != 2) {
            emptyBuffer();
            printf("Veuillez-entrez un choix correct !\n");
            scanf("%d", &MenuChoice);
        }
    }
    switch (MenuChoice) {
        case 1 :
            grid_initialization();
            show_grid();
            break;
        case 2 :
            show_help();
            break;
        default:
            break;

    }


}


void PlayerInput() {
    printf("Veuillez choisir une colonne ( de A à J)\n");
    scanf(" %c", &column_input_letter);
    column_input_letter = tolower(column_input_letter);
    while ((column_input_letter - 'a') < 0 || (column_input_letter - 'a' > 9)) {
        printf("Veuillez choisir une colonne correcte allant de A à J \n");
        scanf(" %c", &column_input_letter);
    }
    printf("Colonne choisie : %c\n", toupper(column_input_letter));


    printf("Veuillez choisir une ligne ( de 1 à 10)\n");
    scanf(" %d", &line_input_number);
    while (line_input_number < 0 || line_input_number > 10) {
        printf("Veuillez choisir une line correcte allant de 1 à 10 \n");
        scanf(" %d", &line_input_number);
    }
    printf("Ligne choisie : %d\n", line_input_number);


    playercolumn = column_input_letter - 'a';
    playerline = line_input_number - 1;
    if (grid[playerline][playercolumn] == 'X') {
        playerGrid[playerline][playercolumn] = 'X';
    } else {
        playerGrid[playerline][playercolumn] = 'O';
    }

    show_player_grid();

}

void verification() {



    boat1_sunkparts = 0                      //reset the sunkparts parts before boat1's check
    int boat1_part_check;
    for (boat1_part_check = 1;
    boat1_part_check < 2; boat_part_check++)       //counts sunk parts to check if boat1 is sunk
    {
        if (playerGrid[boat_part_check][0] == X) {
            boat1_sunkparts = boat1_sunkparts + 1
        }
    }
    if (boat5_sunkparts == 2) { boat5_sunk = true; }

    boat5_sunkparts = 0                      //reset the sunkparts parts before boat5's check
    int boat5_part_check;
    for (boat5_part_check = 1;
         boat5_part_check < 2; boat5_part_check++)       //counts sunk parts to check if boat5 is sunk
    {
        if (playerGrid[boat_part_check][0] == X) {
            boat5_sunkparts = boat5_sunkparts + 1
        }
    }
    if (boat5_sunkparts == 2) { boat5_sunk = true; }


}



int main() {
    Menu();
    add_boats();
    show_grid();
    PlayerInput();
    verification();
    PlayerInput();
    verification();
    return 0;
}
