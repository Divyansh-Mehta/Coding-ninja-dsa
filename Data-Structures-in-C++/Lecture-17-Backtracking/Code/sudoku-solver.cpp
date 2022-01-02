/*
Sudoku Solver
Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.

Input Format:
There are nine lines in input. Each of the nine lines contain nine space separated integers. These nine lines represent the sudoku board.

Output Format:
The first and only line of output contains boolean value, either true or false, as described in problem statement.

Constraints:
The cell values lie in the range: [0, 9]
Time Limit: 1 second 

Note:
Input are given in a way that backtracking solution will work in the provided time limit.

Sample Input 1:
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output 1:
true
*/

#include <bits/stdc++.h>
using namespace std;

#define N 9


bool isPossible(int grid[][N], int row, int col, int num){
    //Safe in row
    for (int i = 0; i < N; i++){
        if (grid[row][i] == num){
            return false;
        }
    }

    //Safe in column
    for (int i = 0; i < N; i++){
        if (grid[i][col] == num){
            return false;
        }
    }

    //Safe in block
    int rowFactor = row - (row % 3);
    int colFactor = col - (col % 3);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (grid[i + rowFactor][j + colFactor] == num){
                return false;
            }
        }
    }

    return true;
}

bool solveSudokuHelper(int grid[][N], int row, int col){
	if (row == N){
        return true;
    }
    
    if (col == N){
        return solveSudokuHelper(grid, row + 1, 0);
    }
    
    if (grid[row][col] != 0){
        return solveSudokuHelper(grid, row, col + 1);
    }
    
    for (int i = 1; i <= 9; i++){
        if (isPossible(grid, row, col, i)){
            grid[row][col] = i;
            if (solveSudokuHelper(grid, row, col + 1)){
                return true;
            }
        }
        grid[row][col] = 0;
    }
    return false;
}

bool solveSudoku(int grid[][N]){
    return solveSudokuHelper(grid, 0, 0);
}

int main(){
    int grid[N][N];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }

    if(solveSudoku(grid)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
    

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

#define N 9

bool findEmptyLocation(int grid[][N], int &row, int &col){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (grid[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool isPossible(int grid[][N], int row, int col, int num){
    //Safe in row
    for (int i = 0; i < N; i++){
        if (grid[row][i] == num){
            return false;
        }
    }

    //Safe in column
    for (int i = 0; i < N; i++){
        if (grid[i][col] == num){
            return false;
        }
    }

    //Safe in block
    int rowFactor = row - (row % 3);
    int colFactor = col - (col % 3);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (grid[i + rowFactor][j + colFactor] == num){
                false;
            }
        }
    }

    return true;
}

bool solveSudoku(int grid[][N]){
    int row, col;
    if(!findEmptyLocation(grid, row, col)){
        return true;
    }

    for (int i = 1; i <= 9; i++){
        if (isPossible(grid, row, col, i)){
            grid[row][col] = i;
            if(solveSudoku(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

int main(){
    int grid[N][N];
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }

    if(solveSudoku(grid)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }
    

    return 0;
}
*/
