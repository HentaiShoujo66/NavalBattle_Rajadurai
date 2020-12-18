/****************************************
*   Title   :   [Battleship]   *
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

/** \brief Miss - This function displays a designed "MISS"
 *
 *
 */
void Miss() {
    printf("\n"
           "███╗░░░███╗██╗░██████╗░██████╗\n"
           "████╗░████║██║██╔════╝██╔════╝\n"
           "██╔████╔██║██║╚█████╗░╚█████╗░\n"
           "██║╚██╔╝██║██║░╚═══██╗░╚═══██╗\n"
           "██║░╚═╝░██║██║██████╔╝██████╔╝\n"
           "╚═╝░░░░░╚═╝╚═╝╚═════╝░╚═════╝░\n");
}

/** \brief Hit - This function displays a designed "HIT"
 *
 *
 */
void Hit() {
    printf("\n"
           "██╗░░██╗██╗████████╗\n"
           "██║░░██║██║╚══██╔══╝\n"
           "███████║██║░░░██║░░░\n"
           "██╔══██║██║░░░██║░░░\n"
           "██║░░██║██║░░░██║░░░\n"
           "╚═╝░░╚═╝╚═╝░░░╚═╝░░░\n");
}

/** \brief Bravo - This function displays a designed "BRAVO"
 *
 *
 */
void Bravo() {
    printf("\n"
           "██████╗░██████╗░░█████╗░██╗░░░██╗░█████╗░\n"
           "██╔══██╗██╔══██╗██╔══██╗██║░░░██║██╔══██╗\n"
           "██████╦╝██████╔╝███████║╚██╗░██╔╝██║░░██║\n"
           "██╔══██╗██╔══██╗██╔══██║░╚████╔╝░██║░░██║\n"
           "██████╦╝██║░░██║██║░░██║░░╚██╔╝░░╚█████╔╝\n"
           "╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░░╚════╝░\n");
}

/** \brief Boom - This function displays a designed "BOOM"
 *
 *
 */
void Boom() {
    printf("\n"
           "██████╗░░█████╗░░█████╗░███╗░░░███╗\n"
           "██╔══██╗██╔══██╗██╔══██╗████╗░████║\n"
           "██████╦╝██║░░██║██║░░██║██╔████╔██║\n"
           "██╔══██╗██║░░██║██║░░██║██║╚██╔╝██║\n"
           "██████╦╝╚█████╔╝╚█████╔╝██║░╚═╝░██║\n"
           "╚═════╝░░╚════╝░░╚════╝░╚═╝░░░░░╚═╝\n");
}
/** \brief Bateau - This function displays a boat
 *
 *
 */
void Bateau() {
    printf("____________________¶¶¶\n"
           "_____________________¶\n"
           "_____________________¶¶¶¶¶¶¶¶¶¶¶¶¶\n"
           "_____________________¶¶¶___¶__¶_¶¶¶¶\n"
           "_____________________¶¶¶___¶¶¶¶___¶¶\n"
           "_____________________¶¶¶__¶¶¶¶¶___¶¶\n"
           "_____________________¶¶¶__¶¶¶¶¶___¶\n"
           "_____________________¶¶¶¶¶¶__¶¶___¶\n"
           "_____________________¶_________¶¶¶¶\n"
           "_____________¶¶¶¶¶¶¶¶¶¶¶¶¶\n"
           "_____________¶¶___________¶¶\n"
           "______________¶____________¶\n"
           "______________¶_____________¶\n"
           "_______________¶____________¶\n"
           "_______________¶____________¶_¶¶\n"
           "_______________¶__¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶\n"
           "_____¶¶¶¶¶¶¶¶¶¶¶¶¶¶______________¶\n"
           "_____¶____________¶¶_____________¶¶____¶\n"
           "_____¶¶____________¶_____¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶\n"
           "______¶______¶¶¶¶¶¶¶¶¶¶¶¶¶¶______________¶\n"
           "______¶¶_____¶¶___________¶______________¶¶\n"
           "_______¶______¶____________¶______________¶\n"
           "_______¶______¶¶___________¶_____________¶¶\n"
           "_______¶_______¶___________¶_____________¶¶\n"
           "______¶¶_______¶___________¶¶____________¶\n"
           "______¶¶¶¶¶¶¶¶¶¶¶__________¶¶___________¶¶\n"
           "___________¶_¶_¶¶________¶¶¶_____¶¶¶¶¶¶¶¶_____¶¶¶\n"
           "___________¶_¶_¶¶¶¶¶¶¶¶¶¶¶_¶¶¶¶¶¶¶_______¶¶¶¶¶__¶¶\n"
           "¶¶¶¶¶¶_____¶_¶______¶¶_¶_______¶_¶¶¶¶¶¶¶¶¶___¶¶¶¶¶\n"
           "¶¶___¶¶¶¶¶¶¶¶¶______¶¶_¶____¶¶¶¶¶¶¶________¶¶\n"
           "__¶¶________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶____¶¶______¶\n"
           "____¶____________________________¶¶_¶____¶\n"
           "_____¶_____¶¶¶_____¶¶_____¶¶¶_____¶¶¶___¶¶\n"
           "______¶___¶¶_¶¶___¶¶_¶____¶_¶¶__________¶\n"
           "______¶¶____¶¶_____¶¶¶_____¶¶__________¶¶\n"
           "_______¶¶_____________________________¶¶\n"
           "________¶¶___________________________¶¶\n"
           "_________¶¶________________________¶¶¶\n"
           "___________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶\n\n");
}

/** \brief show_help - This function displays the player's help for the battleship
 *
 *
 */
void show_help() {
    int HelpStop;
    printf("AIDE__________________________\n"
           "Règles de la bataille navale :\n"
           "La bataille navale oppose deux joueurs qui s'affrontent. Chacun a une flotte composée de 5 bateaux, qui sont,\nen général, les suivants : 1 porte-avion (5 cases), 1 croiseur (4 cases), 1 contre-torpilleur (3 cases),\n1 sous-marin (3 cases), 1 torpilleur (2 cases).Les bateaux ne doivent pas être collés entre eux. Au début du jeu,\nchaque joueur place ses bateaux sur sa grille.\nCelle-ci est toujours numérotée de 1 à 10 verticalement et de A à J horizontalement. Un à un, les joueurs vont \"tirer\"\nsur une case de l'adversaire : par exemple, B.3 ou encore H.8. Le but est donc de couler les bateaux adverses."
           "\nDans cette version de la bataille navale, vous jouerez contre l'ordinateur,\nvous n'aurez qu'à entrer les coordonnées comme demandé et à les valider tour par tour.\n"
           "Le score est compté par nombre de coups effectués.\n\n");
    printf("Entrez 0 pour retourner au menu principal.\n");
    scanf(" %d", &HelpStop);
    while (HelpStop != 0) {
        emptyBuffer();
        printf("Erreur, veuillez entrer 0 pour retrouner au menu principal\n");
        scanf(" %d", &HelpStop);
    }
}

/** \brief grid_initialization - This function initializes the player's and the computer's grid
 *
 *
 */
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

/** \brief show_player_grid - This function displays the player's grid
 *
 *
 */
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

/** \brief add_boats - This function adds boats to the computer's grid
 *
 *
 */
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

/** \brief Menu - This function treats the main menu
 *
 *
 */
void Menu() {
    do {
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
                show_player_grid();
                break;
            case 2 :
                show_help();
                break;
            default:
                break;

        }
    } while (MenuChoice != 1);


}

/** \brief PlayerInput - This function takes the players input and registers it for a round
 *
 *
 */
void PlayerInput() {

    column_input_letter = ' ';       //resets the inputs so it doesn't take the same as the previous round
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
    line_input_number = 0;
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
        Hit();
        printf("Vous avez touché un bateau!\n\n");
        score = score + 1;
        grid[playerline][playercolumn] = 'T';

    } else {
        if (grid[playerline][playercolumn] == 'T') { printf("Vous avez déjà joué cette case !\n"); }

        if (grid[playerline][playercolumn] == ' ') {
            Miss();
            printf("\nVous avez raté!\n\n");
            score = score + 1;
            playerGrid[playerline][playercolumn] = 'O';
        }
    }

    show_player_grid();

}

/** \brief Verification - This function does all the checking for the sunk boats and alerts about it
 *
 *
 */
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
            Boom();
            printf("Porte-avions coulé!\n");
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
            Boom();
            printf("Croiseur coulé \n");
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
            Boom();
            printf("Contre-torpilleur 1 coulé \n");
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
            Boom();
            printf("Contre-torpilleur 2 coulé\n");
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
            Boom();
            printf("Torpilleur coulé ! \n");
            boat5_msg = true;
        }

    }

    if (sunk_boats == 5) { game_over = true; }       //checks the game over with a count

}

/** \brief Play - This function plays and ends the game
 *
 *
 */
void Play() {
    while (game_over == false) {
        PlayerInput();
        verification();
    }
    Bravo();
    printf("Vous avez gagné !\n");
    printf("Votre score est de %d.\n", score);


}

/** \brief main - This function is the program's entry point
 * \return int - Returns a 0 if everything worked right
 *
 */
int main() {

    SetConsoleOutputCP(CP_UTF8);
    Bateau();
    Menu();
    add_boats();
    Play();

    return 0;
}
