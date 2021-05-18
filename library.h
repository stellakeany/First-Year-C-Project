//
// Created by STELLA on 26/04/2021.
//

#ifndef ASSIGNMENT_2_LIBRARY_H
#define ASSIGNMENT_2_LIBRARY_H

void printBoard(char board[][8], char p1name[50], char p2name[50], int p1score, int p2score, char p1colour);

int userInput(char turn, char board[8][8], int *row, int *column);

int playerPass(char turn, char board[8][8]);

int validMove(char turn, char board[8][8], int row, int column);

void flipPieces(char turn, char board[8][8], int row, int column, int *blackScore, int *whiteScore);

#endif //ASSIGNMENT_2_LIBRARY_H
