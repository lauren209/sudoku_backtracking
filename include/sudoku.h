
#include <stdio.h>
#define UNASSIGNED 0
#define N 9

/**
* setting up the findopen method
*/
bool findOpen(int board[N][N], int &row, int &col);

/**
* setting up the safe method
*/
bool safe(int board[N][N], int row, int col, int num);

/**
* checks to see if the board is solved
* @param board
* @return boolean if the game is done
*/
bool solve(int board[N][N])
{
    int row, col;

    if (!findOpen(board, row, col))
       return true;
    for (int num = 1; num <= 9; num++)
    {
        if (safe(board, row, col, num))
        {
            board[row][col] = num;
            if (solve(board))
                return true;
            board[row][col] = UNASSIGNED;
        }
    }
    return false;
}

/**
* finds the open spot
* @param board, row, col
* @return boolean if there is a spot open
*/
bool findOpen(int board[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (board[row][col] == UNASSIGNED)
                return true;
    return false;
}

/**
* checks to see if the row is done
* @param board, row, num
* @return boolean if you can play
*/
bool useRow(int board[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (board[row][col] == num)
            return true;
    return false;
}

/**
* checks if the col is done
* @param board, col, num
* @return boolean if you can play
*/
bool useCol(int board[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (board[row][col] == num)
            return true;
    return false;
}

/**
* checks the box if its done
* @param board, startrow, startcol, num
* @return boolean if you can play
*/
bool box(int board[N][N], int startRow, int startCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (board[row+startRow][col+startCol] == num)
                return true;
    return false;
}

/**
* determines if its safe to play
* @param board, row, num
* @return boolean if you can play
*/
bool safe(int board[N][N], int row, int col, int num)
{
    /* Check if 'num' is not already placed in current row,
       current column and current 3x3 box */
    return !useRow(board, row, num) &&
           !useCol(board, col, num) &&
           !box(board, row - row%3 , col - col%3, num);
}

/**
*Prints the board
* @param board
*/
void printboard(int board[N][N])
{
    for (int row = 0; row < N; row++)
    {
       for (int col = 0; col < N; col++)
             printf("%2d", board[row][col]);
        printf("\n");
    }
}
