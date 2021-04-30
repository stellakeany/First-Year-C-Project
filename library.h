//
// Created by STELLA on 26/04/2021.
//

#ifndef ASSIGNMENT_2_LIBRARY_H
#define ASSIGNMENT_2_LIBRARY_H

void printBoard(char board[][8], char p1name[50], char p2name[50], int p1score, int p2score, char p1colour);

void userInput(char turn, char board[8][8], int *row, char *column);

int validMove(char turn, char board[8][8], int row, char column);

#endif //ASSIGNMENT_2_LIBRARY_H
