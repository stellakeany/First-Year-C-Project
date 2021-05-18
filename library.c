//
// Created by STELLA on 26/04/2021.
//

#include "library.h"
#include <stdio.h>

int cases[8] = {0};
int caseCounter;

void printBoard(char board[][8], char p1name[50], char p2name[50], int p1score, int p2score, char p1colour){

    /*Printing the score*/
    if(p1colour == 'W'){
        printf("\n\nScore: %s (White) %d : %d %s (Black)\n", p1name, p1score, p2score, p2name);
    }
    else{
        printf("\n\nScore: %s (Black) %d : %d %s (White)\n", p1name, p1score, p2score, p2name);
    }

    /*Printing the board*/
    for (size_t i = 0; i < 8; i++){
        printf("     --- --- --- --- --- --- --- ---\n");
        printf(" %d  ", i+1);
        for (size_t j = 0; j < 8; j++){
            printf("|");
            printf(" %c ", board[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("     --- --- --- --- --- --- --- ---\n");
    printf("      a   b   c   d   e   f   g   h \n");
}

int userInput(char turn, char board[8][8], int *row, int *column){

    int row_input=0;
    char col_input='0';

    if(!playerPass(turn, board)){
        printf("%s", "There are no valid movers this turn. The player must pass");
        return 0;
    }

    printf("%s", "Please enter the row number of the disc you want to place.");
    while(!(row_input >= 1 && row_input<= 8)){
        printf("%s", "\nThe row numbers are 1, 2, 3, 4, 5, 6, 7 and 8:");
        scanf("%d", &row_input);
        int tmp;
        while ((tmp = getchar()) != '\n' && tmp != EOF){}
    }

    printf("%s", "Please enter the column letter of the disc you want to place.");
    while(!(col_input >= 'a' && col_input<= 'h') && !(col_input >= 'A' && col_input <= 'H')){
        printf("%s", "\nThe column letters are a, b, c, d, e, f, g and h:");
        scanf("%c", &col_input);
        int tmp;
        while ((tmp = getchar()) != '\n' && tmp != EOF){}
    }

    int row_tmp = row_input-1;
    int col_tmp = col_input-'a';

    if (board[row_tmp][col_tmp] != ' '){
        printf("Not a valid move! %d%c is already occupied\n", row_input, col_input);
        userInput(turn, board, row, column);
    }
    else if (validMove(turn, board, row_tmp, col_tmp)){
        *row=row_tmp;
        *column=col_tmp;
        return 1;
    }
    else{
        printf("Not a valid move!\n");
        userInput(turn, board, row, column);
    }

    return 0;
}

int playerPass(char turn, char board[8][8]){

    for (size_t i = 0; i < 8; i++) {
        for (size_t j = 0; j < 8; j++){
            if (validMove(turn, board, i, j)){
                return 1;
            }
        }
    }

    return 0;
}

int validMove(char turn, char board[8][8], int row, int column) {

    char opponent;
    if (turn == 'B') {
        opponent = 'W';
    } else opponent = 'B';

    for (int i = 0; i < caseCounter; i++) {
        cases[i]=0;
    }
    caseCounter = 0;

    /*'Left' means current player wants to place piece to the left of opponent's piece*/

    /*Case 1: Left*/
    if (board[row][column + 1] == opponent) {
        for (size_t i = 2; (column + i) < 8; i++) {
            if (board[row][column + i] == turn) {

                cases[caseCounter] = 1;
                caseCounter++;
                break;
            }
            if (board[row][column + i] == ' ') {
                break;
            }
        }
    }

    /*Case 2: Right*/
    if (board[row][column - 1] == opponent) {
        for (size_t i = 2; (column - i) >= 0; i++) {
            if (board[row][column - i] == turn) {

                cases[caseCounter] = 2;
                caseCounter++;
                break;
            }
            if (board[row][column - i] == ' ') {
               break;
            }
        }
    }

    /*Case 3: Up*/
    if (board[row + 1][column] == opponent) {
        for (size_t i = 2; (row + i) < 8; i++) {
            if (board[row + i][column] == turn) {

                cases[caseCounter] = 3;
                caseCounter++;
                break;
            }
            if (board[row - i][column] == ' ') {
                break;
            }
        }
    }

    /*Case 4: Down*/
    if (board[row - 1][column] == opponent) {
        for (size_t i = 2; (row - i) >= 0; i++) {
            if (board[row - i][column] == turn) {

                cases[caseCounter] = 4;
                caseCounter++;
                break;
            }
            if (board[row - i][column] == ' ') {
                break;
            }
        }
    }

    /*Case 5: Right-Up Horizontal*/
    if(board[row + 1][column-1] == opponent){
        for (size_t i = 2; (row + i) < 8 && (column - i) >= 0; i++) {
            if (board[row + i][column - i] == turn){

                cases[caseCounter] = 5;
                caseCounter++;
                break;
            }
            if (board[row + i][column - i] == ' '){
                break;
            }
        }
    }

    /*Case 6: Left-Up Horizontal*/
    if(board[row + 1][column + 1] == opponent){
        for (size_t i = 2; (row + i) < 8 && (column + i) < 8; i++) {
            if (board[row + i][column + i] == turn){

                cases[caseCounter] = 6;
                caseCounter++;
                break;
            }
            if (board[row + i][column + i] == ' '){
                break;
            }
        }
    }

    /*Case 7: Right-Down Horizontal*/
    if(board[row - 1][column - 1] == opponent){
        for (size_t i = 2; (row - i) >= 0 && (column - i) >= 0; i++) {
            if (board[row - i][column - i] == turn){

                cases[caseCounter] = 7;
                caseCounter++;
                break;
            }
            if (board[row - i][column - i] == ' '){
                break;
            }
        }
    }

    /*Case 8: Left-Down Horizontal*/
    if(board[row - 1][column + 1] == opponent){
        for (size_t i = 2; (row - i) >= 0 && (column + i) < 8; i++) {
            if (board[row - i][column + i] == turn){

                cases[caseCounter] = 8;
                caseCounter++;
                break;
            }
            if (board[row - i][column + i] == ' '){
                break;
            }
        }
    }

    if(caseCounter>0){
        return 1;
    } else return 0;
}

void flipPieces(char turn, char board[8][8], int row, int column, int *blackScore, int *whiteScore) {

    int i = 1;

    board[row][column] = turn;

    int j;

    for (j = 0; j <= caseCounter; j++) {

        switch (cases[j]) {

            case 1: /*Left*/

                /*Flipping opponent's pieces to the right of the piece just played*/
                printf("\nleft");
                while (board[row][column + i] != turn) {
                    board[row][column + i] = turn;
                    i++;
                }
                break;

            case 2: /*Right*/

                /*Flipping opponent's pieces to the left of the piece just played*/
                printf("\nright");
                while (board[row][column - i] != turn) {
                    board[row][column - i] = turn;
                    i++;
                }
                break;

            case 3: /*Up*/

                /*Flipping opponent's pieces below the piece just played*/
                printf("\nup");
                while (board[row + i][column] != turn) {
                    board[row + i][column] = turn;
                    i++;
                }
                break;

            case 4: /*Down*/

                /*Flipping opponent's pieces above the piece just played*/
                printf("\ndown");
                while (board[row - i][column] != turn) {
                    board[row - i][column] = turn;
                    i++;
                }
                break;

            case 5: /*Right-Up Horizontal*/

                /*Flipping opponent's pieces in a left-downward direction to the piece just played*/
                printf("\nright-up");
                while(board[row + i][column - i] != turn){
                    board[row + i][column - i] = turn;
                    i++;
                }
                break;

            case 6: /*Left-Up Horizontal*/

                /*Flipping opponent's pieces in a right-downward direction to the piece just played*/
                printf("\nleft-up");
                while(board[row + i][column + i] != turn){
                    board[row + i][column + i] = turn;
                    i++;
                }
                break;

            case 7: /*Right-Down Horizontal*/

                /*Flipping opponent's pieces in a left-upward direction to the piece just played*/
                printf("\nright-down");
                while(board[row - i][column - i] != turn){
                    board[row - i][column - i] = turn;
                    i++;
                }
                break;

            case 8: /*Left-Down Horizontal*/

                /*Flipping opponent's pieces in a right-upward direction to the piece just played*/
                printf("\nleft-down");
                while(board[row - i][column + i] != turn){
                    board[row - i][column + i] = turn;
                    i++;
                }
                break;
        }
    }

    printf("\n%d iterations", j);

    if(turn=='B'){
        *blackScore += i;
        *whiteScore -= (i-1);
    }
    else{
        *blackScore -= (i-1);
        *whiteScore += i;
    }
}
