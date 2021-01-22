/****************************************
*   Title   :   [Battleship]   *
*   Author  :   [Rajadurai - Thirusan]      *
*   Version :   [1.0]            *
****************************************/

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

const int GRIDLENGTH = 10;
const int GRIDHEIGHT = 10;
const int SEPARATORSIZE =47;



int line;
int column;
int playercolumn;
int playerline;
int line_input_number;
int sunk_boats = 0;
int score = 0;
int GameLoop= 1;
char playerName[15]="Unknown_Player";
char gridToBeRead[1000];
char column_input_letter;
char grid[10][10];
char coord_letter;
char playerGrid[10][10];
char PlayerDisplayedGrid[10][10];
bool boat1_msg = false;
bool boat2_msg = false;
bool boat3_msg = false;
bool boat4_msg = false;
bool boat5_msg = false;
bool game_over = false;
bool playerLeaving=false;

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
    printf("\n\n\nAIDE__________________________\n"
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
    for (line = 0; line < GRIDHEIGHT; line++) {                          //grid ini
        for (column = 0; column < GRIDLENGTH; ++column) {
            grid[line][column] = ' ';
        }
    }


    for (line = 0; line < GRIDHEIGHT; line++) {                          //playersgrid ini
        for (column = 0; column < GRIDLENGTH; ++column) {
            playerGrid[line][column] = ' ';
        }

    }

    for (line = 0; line < GRIDHEIGHT; line++) {                          //player's displayed grid ini
        for (column = 0; column < GRIDLENGTH; ++column) {
            PlayerDisplayedGrid[line][column] = ' ';
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
    for (int horizontal_separation = 0; horizontal_separation < SEPARATORSIZE; ++horizontal_separation) {
        printf("_");

    }

    printf("\n");
    int coord_number = 1;
    for (line = 0; line < 9; line++) {
        printf("|| %d ", coord_number);
        coord_number++;
        for (column = 0; column < GRIDLENGTH; ++column) { printf("| %c ", PlayerDisplayedGrid[line][column]); }
        printf("||\n");
        for (int horizontal_separation = 0; horizontal_separation < SEPARATORSIZE; ++horizontal_separation) {
            printf("_");

        }
        printf("\n");
    }


    printf("||10 ");
    for (column = 0; column < GRIDLENGTH; ++column) { printf("| %c ", PlayerDisplayedGrid[GRIDHEIGHT-1][column]); }
    printf("||\n");
    for (int horizontal_separation = 0; horizontal_separation < SEPARATORSIZE; ++horizontal_separation) {
        printf("_");

    }
    printf("\n\n\n");
}

/** \brief MapLoad - This function loads a random grid from a file
 *
 *
 */
 void MapLoad(){
     srand(time(0));
     int random_number=rand()%3+1; //random number for the map selection

    // Declare the file pointer
    FILE *filePointer ;
    // Open the existing file test.c using fopen()
    // in read mode using "r" attribute
    switch (random_number) {
        case 1 : filePointer = fopen("../grids/grid1.txt", "r") ;
            break;
        case 2 : filePointer = fopen("../grids/grid2.txt", "r") ;
            break;
        case 3 : filePointer = fopen("../grids/grid3.txt", "r") ;
            break;
        default: printf("Erreur durant la séléction de la carte.\n");
                 exit(0);
    }


    // Check if this filePointer is null
    // which maybe if the file does not exist
    if ( filePointer == NULL )
    {
        printf( "Le chargement de la carte a échoué...\n" ) ;
    }
    else {
        // Read the dataToBeRead from the file
        // using fgets() method
        fgets(gridToBeRead, 1000, filePointer);

        fclose(filePointer);
    }
 }

/** \brief add_boats - This function adds boats to the computer's grid
 *
 *
 */
void add_boats() {
    int i=0;
    for (int line = 0; line < GRIDHEIGHT; ++line) {
        for (int column = 0; column < GRIDLENGTH; ++column) {
            grid[line][column]=gridToBeRead[i];
            i=i+1;

        }

    }
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
    if (column_input_letter!='s') {
        while ((column_input_letter - 'a') < 0 || (column_input_letter - 'a' > 9)) {
            emptyBuffer();
            printf("Veuillez choisir une colonne correcte allant de A à J \n");
            scanf(" %c", &column_input_letter);
            column_input_letter = tolower(column_input_letter);
        }
        printf("Colonne choisie : %c\n\n", toupper(column_input_letter));
    }
    else if (column_input_letter=='s'){printf("Retour au menu principal...\n");
        playerLeaving = true;}


    if (playerLeaving == false) {
        emptyBuffer();
        line_input_number = 0;
        printf("Veuillez choisir une ligne ( de 1 à 10)\n");
        scanf(" %d", &line_input_number);
        while (line_input_number < 1 || line_input_number > 10) {
            emptyBuffer();
            printf("Veuillez choisir une ligne correcte allant de 1 à 10\n");
            scanf(" %d", &line_input_number);
        }
        printf("Ligne choisie : %d\n\n", line_input_number);
    }
}

/** \brief CumputeInput - This function compute the players input and displays the result
 *
 *
 */
void CumputeInput(){
    playercolumn = column_input_letter - 'a';                   //conversion of the letter to a number
    playerline = line_input_number -1;                         //conversion from the user's column to the grid's column number
    if (PlayerDisplayedGrid[playerline][playercolumn] != ' ') { printf("Vous avez déjà joué cette case !\n"); }
    else if (grid[playerline][playercolumn] > '0' && grid[playerline][playercolumn] <
                                                     '6') {         //compare user input's location with the hidden grid's value to check the result
        playerGrid[playerline][playercolumn] = grid[playerline][playercolumn];
        PlayerDisplayedGrid[playerline][playercolumn] = 'X';
        Hit();
        printf("Vous avez touché un bateau!\n\n");
        score = score + 1;

    } else if (grid[playerline][playercolumn] == '0') {
        Miss();
        printf("\nVous avez raté!\n\n");
        score = score + 1;
        PlayerDisplayedGrid[playerline][playercolumn] = 'O';
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
    for (line = 0; line < GRIDHEIGHT; line++) {                         //counts sunk parts to check if boat1 is sunk
        for (column = 0; column < GRIDLENGTH; ++column) {
            if(playerGrid[line][column] == '1') {
                boat1_sunkparts = boat1_sunkparts + 1;
            }
        }
    }
    if (boat1_sunkparts == 5) {
        if (boat1_msg == false)                       //a condition, so it only displays sunk one time
        {
            Boom();
            printf("Porte-avions coulé!\n");
            boat1_msg = true;
        }
        sunk_boats = sunk_boats + 1;
    }


    int boat2_sunkparts = 0;                     //reset the sunkparts parts before boat2's check
    for (line = 0; line < GRIDHEIGHT; line++) {                         //counts sunk parts to check if boat2 is sunk
        for (column = 0; column < GRIDLENGTH; ++column) {
            if(playerGrid[line][column] == '2') {
                boat2_sunkparts = boat2_sunkparts + 1;
            }
        }
    }

    if (boat2_sunkparts == 4) {
        sunk_boats = sunk_boats + 1;
        if (boat2_msg == false) {
            Boom();
            printf("Croiseur coulé \n");
            boat2_msg = true;
        }
    }

    int boat3_sunkparts = 0;                     //reset the sunkparts parts before boat3's check
    for (line = 0; line < GRIDHEIGHT; line++) {                         //counts sunk parts to check if boat3 is sunk
        for (column = 0; column < GRIDLENGTH; ++column) {
            if(playerGrid[line][column] == '3') {
                boat3_sunkparts = boat3_sunkparts + 1;
            }
        }
    }
    if (boat3_sunkparts == 3) {
        sunk_boats = sunk_boats + 1;
        if (boat3_msg == false) {
            Boom();
            printf("Contre-torpilleur 1 coulé \n");
            boat3_msg = true;
        }
    }

    int boat4_sunkparts = 0;                     //reset the sunkparts parts before boat4's check
    for (line = 0; line < GRIDHEIGHT; line++) {                         //counts sunk parts to check if boat4 is sunk
        for (column = 0; column < GRIDLENGTH; ++column) {
            if(playerGrid[line][column] == '4') {
                boat4_sunkparts = boat4_sunkparts + 1;
            }
        }
    }
    if (boat4_sunkparts == 3) {
        sunk_boats = sunk_boats + 1;
        if (boat4_msg == false) {
            Boom();
            printf("Contre-torpilleur 2 coulé\n");
            boat4_msg = true;
        }
    }


    int boat5_sunkparts = 0;                     //reset the sunkparts parts before boat5's check
    for (line = 0; line < GRIDHEIGHT; line++) {                         //counts sunk parts to check if boat5 is sunk
        for (column = 0; column < GRIDLENGTH; ++column) {
            if(playerGrid[line][column] == '5') {
                boat5_sunkparts = boat5_sunkparts + 1;
            }
        }
    }
    if (boat5_sunkparts == 2) {
        sunk_boats = sunk_boats + 1;
        if (boat5_msg == false) {
            Boom();
            printf("Torpilleur coulé ! \n");
            boat5_msg = true;
        }

    }

    if (sunk_boats == 5) { game_over = true; }       //checks the game over with a count

}

/** \brief RegisterScore - This function registers the score
 *
 *
 */
void RegisterScore(){
    // Declare the file pointer
    FILE *filePointer ;

    // Open the existing file GfgTest.c using fopen()
    // in write mode using "w" attribute
    filePointer = fopen("../scores.txt", "a") ;

    // Check if this filePointer is null
    // which maybe if the file does not exist
    if ( filePointer == NULL )
    {
        printf( "Les scores n'ont pas pu être chargés." ) ;
    }
    else
    {

        fprintf(filePointer,"%s                                     %d\n",playerName,score);


        // Closing the file using fclose()
        fclose(filePointer) ;

        printf("Votre score a été enregistré\n\n");
    }
}

/** \brief ShowScore - This function shows the score
 *
 *
 */
void ShowScore(){
    // Declare the file pointer
    FILE *filePointer ;

    // Declare the variable for the data to be read from file
    char scoreToBeRead[1000];

    // Open the existing file GfgTest.c using fopen()
    // in read mode using "r" attribute
    filePointer = fopen("../scores.txt", "r") ;

    // Check if this filePointer is null
    // which maybe if the file does not exist
    if ( filePointer == NULL )
    {
        printf( "Les scores n'ont pas pu être ouverts\n\n" ) ;
    }
    else
    {
        // Read the scoreToBeRead from the file
        // using fgets() method
        while( fgets ( scoreToBeRead, 1000, filePointer ) != NULL )
        {

            // Print the dataToBeRead
            printf( "%s" , scoreToBeRead ) ;
        }

        // Closing the file using fclose()
        fclose(filePointer) ;
        int scoreStop;
        printf("\n\nEntrez 0 pour retourner au menu principal.\n");
        scanf(" %d", &scoreStop);
        while (scoreStop != 0) {
            emptyBuffer();
            printf("Erreur, veuillez entrer 0 pour retrouner au menu principal\n");
            scanf(" %d", &scoreStop);
        }

    }

}

/** \brief Play - This function plays and ends the game
 *
 *
 */
void Play() {
    playerLeaving=false;
    score= 0;
    grid_initialization();
    MapLoad();
    add_boats();
    show_player_grid();

    while (game_over == false) {
        PlayerInput();
        if(playerLeaving==false) {
            CumputeInput();
            verification();
        }
        else{
            sunk_boats = 0;
            boat1_msg=false;
            boat2_msg=false;
            boat3_msg=false;
            boat4_msg=false;
            boat5_msg=false;
            break;
        }
    }
    if(playerLeaving==false) {
        Bravo();
        printf("Vous avez gagné !\n");
        printf("Votre score est de %d.\n\n", score);
        RegisterScore();
        playerLeaving=true;
        sunk_boats = 0;
        boat1_msg=false;
        boat2_msg=false;
        boat3_msg=false;
        boat4_msg=false;
        boat5_msg=false;
    }
    GameLoop=1;
}

/** \brief PlayerName - This function lets the player change his name
 *
 *
 */
 void PlayerNameSetting(){
     printf("Veuillez entrez un pseudo: (seul les 15 premiers charactères seront pris ! )\n");
     scanf("%s", &playerName);
     printf("Le pseudo du joueur est désormais: %s \n", playerName);


 }



/** \brief Menu - This function treats the main menu
 *
 *
 */
void Menu() {
    int MenuChoice;
    do {
        printf("\n\n\nBienvenue dans la bataille navale !\n\n"
               "Entrez 1 pour jouer\n"
               "Entrez 2 pour voir l'aide du jeu\n"
               "Entrez 3 pour changer votre pseudo\n"
               "Entrez 4 pour voir les scores précédents\n"
               "Entrez 5 pour quitter le jeu\n");
        scanf("%d", &MenuChoice);
        if (MenuChoice != 1 && MenuChoice != 2 && MenuChoice != 3 && MenuChoice != 4 && MenuChoice != 5) {            //Using and != to avoid a big endless loop bug
            while (MenuChoice != 1 && MenuChoice != 2 && MenuChoice != 3 && MenuChoice != 4 && MenuChoice != 5) {
                emptyBuffer();
                printf("Veuillez-entrez un choix correct !\n\n\n");
                scanf("%d", &MenuChoice);
            }
        }
        switch (MenuChoice) {
            case 1 : Play();
                break;
            case 2 :
                show_help();
                break;
            case 3:
                PlayerNameSetting();
                break;
            case 4:
                ShowScore();
                break;
            case 5 :
                exit(0);
            default:
                break;

        }
    } while (MenuChoice != 1);


}

/** \brief main - This function is the program's entry point
 * \return int - Returns a 0 if everything worked right
 *
 */
int main() {
    SetConsoleOutputCP(CP_UTF8);
    setbuf(stdout,NULL);
    Bateau();
    while(GameLoop== 1){// the game loop var let's us avoid a bug where the Menu loops itself before the game is finished
        GameLoop= 0;
        Menu();
}


    return 0;
}
