//
// Created by STELLA on 26/04/2021.
//

#include "library.h"
#include <stdio.h>

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

void userInput(char turn, char board[8][8], int *row, char *column){

    int row_tmp=0;
    char col_tmp='0';
    int valid=0;

    printf("It is currently %c's turn\n", turn);

    while (valid==0){

        printf("%s", "Please enter the row number of the disc you want to place.");
        while(!(row_tmp >= 1 && row_tmp<= 8)){
            printf("%s", "\nThe row numbers are 1, 2, 3, 4, 5, 6, 7 and 8:");
            scanf("%d", &row_tmp);
        }

        printf("%s", "Please enter the column letter of the disc you want to place.");
        while(!(col_tmp >= 'a' && col_tmp<= 'h') && !(col_tmp >= 'A' && col_tmp <= 'H')){
            printf("%s", "\nThe column letters are a, b, c, d, e, f, g and h:");
            scanf("%c", &col_tmp);
            int tmp;
            while ((tmp = getchar()) != '\n' && tmp != EOF){}
        }

        if (board[row_tmp][col_tmp] != ' '){
            printf("Not a valid move! %d%c is already occupied\n", row_tmp, col_tmp);
        }
        else if (validMove(turn, board, row_tmp, col_tmp) == 1 ){
            valid=1;
            *row=row_tmp;
            *column=col_tmp;
        }
        else (printf("Not a valid move!\n"));
    }
}

int validMove(char turn, char board[8][8], int row, char column){
    
}