#include "library.h"
#include <stdio.h>
#include <string.h>

int main() {

    char WName[50];
    char BName[50];
    char ans;

    /*Players entering their names and which colour they want to play as*/
    printf("%s", "Welcome to Othello\nPlayer 1: Please enter your name:");
    fgets(WName,10,stdin);
    printf("%s", "Which colour would you like to play as? (W for White, B for Black):");
    ans = getchar();
    if(ans == 'B' || ans == 'b')
    {
        strcpy(BName, WName);
        printf("%s is playing as Black\n", BName);
        printf("%s", "Player 2: Please enter your name: ");
        fgets(WName,50,stdin);
        printf("%s is playing as White\n", WName);
    }
    else
    {
        printf("%s is playing as White\n", WName);
        printf("%s", "Player 2: Please enter your name: ");
        fgets(BName,50,stdin);
        printf("%s is playing as Black\n", BName);
    }

    /*Initialising the board*/
    char board[8][8]={'0'};
    int WScore = 2;
    int BScore = 2;

    board[3][3]='W';
    board[4][3]='B';
    board[3][4]='B';
    board[4][4]='W';

    printBoard(board, WScore, BScore, WName, BName);

    return 0;
}
