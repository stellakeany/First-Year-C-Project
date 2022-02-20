# OTHELLO
 Program that manages a game of Othello for two players.

----------MAIN.C----------
I made a struct for each player containing:
  - Their name
  - The colour they're playing as
  - Their score
  
I also made a struct for the current...
  - Board
  - Player turn
  
These structs helped with organisation and the overall neatness of the code.
  
In the main function  the players are asked for their names (using fgets) and the colour they want to play as and these are added to each player struct. 
The board is then initialised and each player gets 2 points.
Black always goes first.

Pointers are allocated to certain values such as the players' points and the inputted row and column numbers since these need to be edditted within functions multiple at a time
while also needing to be used inside of main.c. 

There is then a while loop which is exited once every position on the board is filled. This is the actual gameplay loop.
1. The current score and board are printed using printBoard.
2. userIput is called to take the user's input:
   - if userinput returns 1 (i.e. a valid move was entered), then flipPieces is called to flip the appropriate pieces.
   - if userInput returns 0 (i.e. there are no valid moves for this player this round), the call to flipPieces is skipped since there are no pieces to be flipped.
3. The turn is switched.

When the gameplay loop is exited the game ends.

The winner is decided by checking which player has the most points.


----------LIBRARY.H----------
Library.h is imported to main.c and contains 5 functions:
- printBoard
- userInput
- playerPass
- validMove
- flipPieces

----------LIBRARY.C----------

void printBoard(char board[][8], char p1name[50], char p2name[50], int p1score, int p2score, char p1colour)
- Prints the current score and what the board currently looks like in the following format:

  Score: player1 (Black) 2 : 2 player2 (White)
     --- --- --- --- --- --- --- ---
 1  |   |   |   |   |   |   |   |   |
     --- --- --- --- --- --- --- ---
 2  |   |   |   |   |   |   |   |   |
     --- --- --- --- --- --- --- ---
 3  |   |   |   |   |   |   |   |   |
     --- --- --- --- --- --- --- ---
 4  |   |   |   | W | B |   |   |   |
     --- --- --- --- --- --- --- ---
 5  |   |   |   | B | W |   |   |   |
     --- --- --- --- --- --- --- ---
 6  |   |   |   |   |   |   |   |   |
     --- --- --- --- --- --- --- ---
 7  |   |   |   |   |   |   |   |   |
     --- --- --- --- --- --- --- ---
 8  |   |   |   |   |   |   |   |   |
     --- --- --- --- --- --- --- ---
      a   b   c   d   e   f   g   h

int userInput(char turn, char board[8][8], int *row, int *column)
- This function is called at the beginning of each player's turn. It carries out a number of tasks:
   1. Calls playerPass to check if there are any possible moves for that player this round. If not, the function returns 0
   2. Asks the player to input a row number and column letter for their move and converts these values into appropriate 2D array indexing format.
     (This prompt is repeated until the user inputs values in the correct format)
   3. Checks that the user's input is valid by:
      a. Checking if the space entered is not empty (i.e. invalid)
      b. Calls validMove
   4. If the space entered is valid, then the user's input will be assigned to *row and *column so that they can be used in other functions.
      The function then returns 1.
   5. If the input is not valid then the function calls itself so that the user can try again.
   
 int playerPass(char turn, char board[8][8])
 - This function checks if there are any possible moves for that player this round.
 - This is achieved by calling validMove repeatedly for each space on the board until a valid move is found.
 - If a move is found, the function returns 1.
 - If the for loop completes and there are no possible moves, the function returns 0.
 
 int validMove(char turn, char board[8][8], int row, int column)
 - This function checks if the placement entered is a valid move.
 - A move is valid if it meets all of the following conditions:
     1. The piece is placed beside an opponent's piece (either directly beside or on the horizontal)
     2. There is an unbroken line of opponent's pieces between the new piece and another piece belonging to the player
 - The function tests for condition 1 first before testing condition 2.
 - The direction of the line depends on the placement of the piece in relation to the opponent's piece (i.e. directly above, to the right etc.) and so these are all tested for separately.
 - If both of these conditions are met, the placement type is recorded in a global array (1 move can meet the conditions for multiple placement types) in library.c so that it can used by flipPieces.
    Example:
        --- --- --- --- --- --- --- ---
    1  |   |   |   |   |   |   |   |   |
        --- --- --- --- --- --- --- ---
    2  |   |   |   |   |   |   |   |   |
        --- --- --- --- --- --- --- ---
    3  |   |   |   |   |   |   |   |   |
        --- --- --- --- --- --- --- ---
    4  |   |   | B | B | B |   |   |   |
        --- --- --- --- --- --- --- ---
    5  |   |   | W | W | W |   |   |   |
        --- --- --- --- --- --- --- ---
    6  |   |   |   |   |   |   |   |   |
        --- --- --- --- --- --- --- ---
    7  |   |   |   |   |   |   |   |   |
        --- --- --- --- --- --- --- ---
    8  |   |   |   |   |   |   |   |   |
        --- --- --- --- --- --- --- ---
         a   b   c   d   e   f   g   h

     If black was to place their piece at 6c they would be below 5c (Case 4: Down) and below and to the left of 5d (Case 8: Left-Down Horizontal).
     Then cases = {4, 8,...} and caseCounter = 2.
     I chose to use global values instead of pointers like I used for the rows and columns because they don't need to be called outside of library.c
 - If the move meets the conditions for 1 or more placement types (i.e. the move is valid), the function returns 1
 - If the move meets none of the conditions (i.e. the move is invalid), the function returns 0
 
 void flipPieces(char turn, char board[8][8], int row, int column, int *blackScore, int *whiteScore)
 This function uses information gathered by validMove and stored in the global array in library.c to 'flip' to:
   1. Place the player's piece on the board
   2. 'Flip' the line of opponent's pieces between the player's new piece and another piece belonging to the player
   3. Tally the players' scores
   The pieces on the board are flipped using the same indexing as validMove
