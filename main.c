#include "library.h"
#include <stdio.h>
#include <string.h>

enum othelloColour {BLACK = 'B', WHITE = 'W', EMPTY = ' '};

struct othelloPlayer{
    char name[50];
    enum othelloColour colour;
    int score;
};

int main() {

    char ans='a';
    struct othelloPlayer player1, player2;

    /*Players entering their names and which colour they want to play as*/
    printf("%s", "Welcome to Othello\nPlayer 1: Please enter your name:");
    while(fgets(player1.name, sizeof(player1.name),stdin)==NULL){
        perror("Error reading name. Please try again:\n");
    }
    player1.name[strcspn(player1.name, "\n")] = 0;

    printf("%s", "Which colour would you like to play as?\n");
    while (ans != 'B' && ans != 'b' && ans != 'W' && ans != 'w'){
        printf("%s", "Please enter either W for White or B for Black\n");
        scanf("%c", &ans);
        int tmp;
        while ((tmp = getchar()) != '\n' && tmp != EOF){}
    }

    if(ans == 'B' || ans == 'b'){
        player1.colour=BLACK;
        player2.colour=WHITE;
    }
    else{
        player1.colour=WHITE;
        player2.colour=BLACK;
    }

    printf("%s", "Player 2: Please enter your name: ");
    while(fgets(player2.name,sizeof(player2.name),stdin)==NULL){
        perror("Error reading name. Please try again:\n");
    }
    player2.name[strcspn(player2.name, "\n")] = 0;

    printf("%s is playing as %c\n", player1.name, player1.colour);
    printf("%s is playing as %c\n", player2.name, player2.colour);

    /*Initialising the board*/
    char board[8][8]={EMPTY};
    player1.score = 2;
    player2.score = 2;

    board[3][3]=WHITE;
    board[4][3]=BLACK;
    board[3][4]=BLACK;
    board[4][4]=WHITE;

    while (player1.score+player2.score!=64){

        printBoard(board, player1.name, player2.name, player1.score, player2.score, player1.colour);


    }

    return 0;
}
