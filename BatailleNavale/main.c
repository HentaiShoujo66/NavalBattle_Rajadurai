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
int sunk_boats = 0;
int new_sunk_boat = 0;
int score = 0;
char column_input_letter;
char grid[10][10];
char coord_letter;
char playerGrid[10][10];
bool boat1_sunk = false;
bool boat2_sunk = false;
bool boat3_sunk = false;
bool boat4_sunk = false;
bool boat5_sunk = false;
bool boat1_msg = false;
bool boat2_msg = false;
bool boat3_msg = false;
bool boat4_msg = false;
bool boat5_msg = false;
bool game_over = false;

void emptyBuffer() {
    int c = 0;
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

void show_help() {
    int HelpStop;
    printf("HELP____________\n");
    printf("Entrez 0 pour retourner au menu principal.\n");
    scanf(" %d", &HelpStop);
    while (HelpStop != 0) {
        emptyBuffer();
        printf("Erreur, veuillez entrer 0 pour retrouner au menu principal\n");
        scanf(" %d", &HelpStop);
    }
}


void grid_initialization() {
    for (line = 0; line < 10; line++) {                          //grid ini
        for (column = 0; column < 10; ++column) {
            grid[line][column] = ' ';
        }
    }


    for (line = 0; line < 10; line++) {                          //playersgrid ini
        for (column = 0; column < 10; ++column) {
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
    for (column = 0; column < 10; ++column) { printf("| %c ", playerGrid[9][column]); }
    printf("||\n");
    for (int horizontal_separation = 0; horizontal_separation < 47; ++horizontal_separation) {
        printf("_");

    }
    printf("\n\n\n");
}

void add_boats() {
    for (line = 2; line < 7; ++line) {                                               //Carrier (boat1)
        grid[line][9] = 'X';

    }

    for (line = 2; line < 6; ++line) {                                               //Battleship (boat2)
        grid[line][7] = 'X';

    }

    for (column = 6;
         column < 9; ++column) {                                               //Cruiser (boat3)
        grid[0][column] = 'X';

    }

    for (column = 6;
         column < 9; ++column) {                                               //Submarine (boat4)
        grid[8][column] = 'X';

    }

    for (line = 1; line < 3; ++line) {                                               //Destroyer (boat5)
        grid[line][0] = 'X';

    }
}

void Menu() {
    do{printf("Bienvenue dans la bataille navale !\n\n"
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

    }}while (MenuChoice!=1);


}


void PlayerInput() {

    column_input_letter= 'l';       //resets the inputs so it doesn't take the same as the previous round
    printf("Veuillez choisir une colonne ( de A à J)\n");
    scanf(" %c", &column_input_letter);
    column_input_letter = tolower(column_input_letter);
    while ((column_input_letter - 'a') < 0 || (column_input_letter - 'a' > 9)) {
        emptyBuffer();
        printf("Veuillez choisir une colonne correcte allant de A à J \n");
        scanf(" %c", &column_input_letter);
    }
    printf("Colonne choisie : %c\n\n", toupper(column_input_letter));

    emptyBuffer();
    line_input_number=0;
    printf("Veuillez choisir une ligne ( de 1 à 10)\n");
    scanf(" %d", &line_input_number);
    while (line_input_number < 1 || line_input_number > 10) {
        emptyBuffer();
        printf("Veuillez choisir une ligne correcte allant de 1 à 10 \n");
        scanf(" %d", &line_input_number);
    }
    printf("Ligne choisie : %d\n\n", line_input_number);


    playercolumn = column_input_letter - 'a';                   //conversion of the letter to a number
    playerline = line_input_number -
                 1;                         //conversion from the user's column to the grid's column number
    if (grid[playerline][playercolumn] ==
        'X') {                //compare user input's location with the hidden grid's value to check the result
        playerGrid[playerline][playercolumn] = 'X';
        printf("touché!\n");
        score = score + 1;
        grid[playerline][playercolumn] = 'T';


        if (new_sunk_boat < sunk_boats)        //verification if it's a new sunk boat
        {
            printf("Coulé!\n");
            new_sunk_boat = new_sunk_boat + 1;
        }
    } else {
        if (grid[playerline][playercolumn] == 'T') { printf("Vous avez déjà joué cette case !\n"); }

        if (grid[playerline][playercolumn] == ' ') {
            printf("loupé!\n");
            score = score + 1;
            playerGrid[playerline][playercolumn] = 'O';
        }
    }

    show_player_grid();

}

void verification() {

    sunk_boats = 0;
    int boat1_sunkparts = 0;                     //reset the sunkparts parts before boat1's check
    int boat1_part_check;
    for (boat1_part_check = 2;
         boat1_part_check < 7; boat1_part_check++)       //counts sunk parts to check if boat1 is sunk
    {
        if (playerGrid[boat1_part_check][9] == 'X') {
            boat1_sunkparts = boat1_sunkparts + 1;
        }
    }
    if (boat1_sunkparts == 5) {
        boat1_sunk = true;
        if (boat1_msg == false)                       //a condition, so it only displays sunk one time
        {
            printf("bato 1 koulé!\n");
            boat1_msg = true;
        }
        sunk_boats = sunk_boats + 1;
    }


    int boat2_sunkparts = 0;                     //reset the sunkparts parts before boat2's check
    int boat2_part_check;
    for (boat2_part_check = 2;
         boat2_part_check < 6; boat2_part_check++)       //counts sunk parts to check if boat2 is sunk
    {
        if (playerGrid[boat2_part_check][7] == 'X') {
            boat2_sunkparts = boat2_sunkparts + 1;
        }
    }
    if (boat2_sunkparts == 4) {
        boat2_sunk = true;
        sunk_boats = sunk_boats + 1;
        if (boat2_msg == false) {
            printf("bato 2 koulé \n");
            boat2_msg = true;
        }
    }

    int boat3_sunkparts = 0;                     //reset the sunkparts parts before boat3's check
    int boat3_part_check;
    for (boat3_part_check = 6;
         boat3_part_check < 9; boat3_part_check++)       //counts sunk parts to check if boat3 is sunk
    {
        if (playerGrid[0][boat3_part_check] == 'X') {
            boat3_sunkparts = boat3_sunkparts + 1;
        }
    }
    if (boat3_sunkparts == 3) {
        boat3_sunk = true;
        sunk_boats = sunk_boats + 1;
        if (boat3_msg == false) {
            printf("bato 3 koulé \n");
            boat3_msg = true;
        }
    }

    int boat4_sunkparts = 0;                     //reset the sunkparts parts before boat4's check
    int boat4_part_check;
    for (boat4_part_check = 6;
         boat4_part_check < 9; boat4_part_check++)       //counts sunk parts to check if boat4 is sunk
    {
        if (playerGrid[8][boat4_part_check] == 'X') {
            boat4_sunkparts = boat4_sunkparts + 1;
        }
    }
    if (boat4_sunkparts == 3) {
        boat4_sunk = true;
        sunk_boats = sunk_boats + 1;
        if (boat4_msg == false) {
            printf("bato 4 koulé \n");
            boat4_msg = true;
        }
    }


    int boat5_sunkparts = 0;                     //reset the sunkparts parts before boat5's check
    int boat5_part_check;
    for (boat5_part_check = 1;
         boat5_part_check < 3; boat5_part_check++)       //counts sunk parts to check if boat5 is sunk
    {
        if (playerGrid[boat5_part_check][0] == 'X') {
            boat5_sunkparts = boat5_sunkparts + 1;
        }
    }
    if (boat5_sunkparts == 2) {
        boat5_sunk = true;
        sunk_boats = sunk_boats + 1;
        if (boat5_msg == false) {
            printf("bato 5 koulé \n");
            boat5_msg = true;
        }

    }

    if (sunk_boats == 5) { game_over = true; }       //checks the game over with a count

}


void Play() {
    while (game_over == false) {
        PlayerInput();
        verification();
    }
    printf("GG!\n");
    printf("Votre score est de %d.\n", score);


}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    Menu();
    add_boats();
    Play();

    return 0;
}
