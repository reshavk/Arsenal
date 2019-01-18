/*
Given an incomplete Sudoku configuration in terms of a 9x9  2-D square matrix (mat[][]) 
the task is to print a solution of the Sudoku. For simplicity you may assume that there will be only 
one unique solution.
*/
#include<bits/stdc++.h>
using namespace std;

//Backtracking Solution :
int grid[9][9];

bool findEmpty(int &row, int &col) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(grid[i][j] == 0) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool inrow(int row, int col, int num) {
    for(int col = 0; col < 9; col++) {
        if(grid[row][col] == num)
            return true;
    }
    return false;
}

bool incol(int row, int col, int num) {
    for(int row=0; row < 9; row++) {
        if(grid[row][col] == num)
            return true;
    }
    return false;
}

bool inbox(int rowS, int colS, int num) {
    for(int i=rowS; i<rowS+3; i++) {
        for(int j=colS; j<colS+3; j++) {
            if(grid[i][j] == num)
                return true;
        }
    }
    return false;
}

void solveSudoku() {
    int row, col;
    if(!findEmpty(row, col)) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                cout << grid[i][j] << " ";
            }
        }
        cout << "\n";
        return;
    }

    for(int num=1; num<=9; num++) {
        if(!inrow(row, col, num) && !incol(row, col, num) && !inbox(row - row%3, col - col%3, num)) {
            grid[row][col] = num;
            solveSudoku();
            grid[row][col] = 0;
        }
    }

}
