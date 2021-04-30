#include "library.h"
#include <stdio.h>
#include <string.h>

enum othelloColour {BLACK = 'B', WHITE = 'W', EMPTY = ' '};

struct othelloPlayer{
    char name[50];
    enum othelloColour colour;
    int score;
};

struct othelloBoard{
    char board[8][8];
    enum othelloColour turn;
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
    struct othelloBoard current;

    for (size_t i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j){
            current.board[i][j]=EMPTY;
        }
    }
    current.board[3][3]=WHITE;
    current.board[4][3]=BLACK;
    current.board[3][4]=BLACK;
    current.board[4][4]=WHITE;

    current.turn=BLACK;

    player1.score=2;
    player2.score=2;

    int inputRow;
    char inputCol;
    int  *inputRowPtr;
    char  *inputColPtr;

    inputRowPtr=&inputRow;
    inputColPtr=&inputCol;

    int test=0;

    while (player1.score+player2.score!=64 && test == 0){

        printBoard(current.board, player1.name, player2.name, player1.score, player2.score, player1.colour);

        userInput(current.turn, current.board, inputRowPtr, inputColPtr);

        if (current.turn==BLACK){
            current.turn=WHITE;
        } else current.turn=BLACK;

        test++;
    }

    return 0;
}
