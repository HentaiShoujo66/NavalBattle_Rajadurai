/****************************************
*   Title   :   [Naval Batlle]   *
*   Author  :   [Rajadurai - Thirusan]      *
*   Version :   [0.1]            *
****************************************/

#include <stdio.h>
#include <windows.h>

int line;
int column;
int MenuChoice;
char grid[10][10];
char coord_letter;


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
    for (line = 0; line < 9; line++) {
        for (column = 0; column < 9; ++column) {
            grid[line][column] = ' ';
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

void add_boats() {
    for (line = 2; line < 7; ++line) {                                               //porte-avions
        grid[line][9] = 'X';

    }

    for (line = 2; line < 6; ++line) {                                               //croiseur
        grid[line][7] = 'X';

    }

    for (column = 6; column < 9; ++column) {                                               //first contre-torpilleur
        grid[0][column] = 'X';

    }

    for (column = 6; column < 9; ++column) {                                               //second1 contre-torpilleur
        grid[8][column] = 'X';

    }

    for (line = 1; line < 3; ++line) {                                               //croiseur
        grid[line][0] = 'X';

    }
}

int Menu() {
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


int main() {
    Menu();
    add_boats();
    show_grid();
    return 0;
}
