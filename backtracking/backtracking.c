#include <stdio.h>
#include <stdbool.h>

bool board[8][8];
int n = 8;

bool checkForQueen(int row, int col) {

    if (row == 0)
        return false;

    //check above
    for (int i = row, j = col; i >= 0; --i) {
        if (board[i][j] == true)
            return true;
    }

    //check above and to the left
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == true)
            return true;
    }

    //check above and to the right
    for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
        if (board[i][j] == true)
            return true;
    }

    //no queen was found
    return false;
}

bool placeQueen(int row) {

    for (int j = 0; j < n; j++) {
        //iterate through rows of col
        if (checkForQueen(row, j) == false) {
            //place queen
            board[row][j] = true;
            if (row != n-1) {
                if (placeQueen(row+1) == false) {
                    //queen was not placed
                    board[row][j] = false;
                    continue;
                } else {
                    //queen was placed
                    return true;
                }
            } else {
                //solution is found
                return true;
            }
        }
    }

    //no available position in row, backtrack
    return false;
}

void printBoard() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == n-1) {
                printf("%d \n", board[i][j]);
            } else {
                printf("%d ", board[i][j]);
            }
        }
    }
}

int main(void) {
    placeQueen(0);
    printBoard();
    return 0;
}
