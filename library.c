//
// Created by STELLA on 26/04/2021.
//

#include "library.h"
#include <stdio.h>

void printBoard(char board[][8], int WScore, int BScore, char WName[50], char BName[50])
{
    printf("\n\nScore: %s (White) %d : %d %s (Black)\n", WName, BScore, WScore, BName);

    for (size_t i = 0; i < 8; i++)
    {
        printf("     --- --- --- --- --- --- --- ---\n");
        printf(" %d  ", i+1);
        for (size_t j = 0; j < 8; j++)
        {
            printf("|");
            if(board[i][j] == '0')
            {
                printf("   ");
            }
            else
            {
                printf(" %c ", board[i][j]);
            }
        }
        printf("|");
        printf("\n");
    }
    printf("     --- --- --- --- --- --- --- ---\n");
    printf("      a   b   c   d   e   f   g   h \n");

}
