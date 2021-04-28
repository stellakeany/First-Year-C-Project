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
