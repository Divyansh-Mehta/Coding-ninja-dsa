/*
Rat In A Maze Problem
You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat starts from the top left cell and has to reach to the bottom right cell of the maze. The rat can move in all the four directions: up, down, left and right.
In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.
You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix.

Input Format
The first line of input contains an integer, that denotes the value of N.
Each of the following N lines denote rows of the binary matrix and contains either 0 or 1. Each row of the binary matrix contains N elements. 

Output Format :
Every possible solution has to be printed on a separate line. Each of the possible solution will have N*N elements, printed row wise and separated by space. The cells that are part of the path should be 1 and remaining all cells should be 0. Please refer to sample test cases for more clarity.   

Constraints
1 <= N <= 18
0 <= Number of cells with value 1 <= 15
Time Limit: 1 second

Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 
Explanation :
Only 1 path is possible. The path is shown in the image below.

Sample Input 2 :
3
1 0 1
1 1 1
1 1 1
Sample Output 2 :
1 0 0 1 1 1 1 1 1 
1 0 0 1 0 0 1 1 1 
1 0 0 1 1 0 0 1 1 
1 0 0 1 1 1 0 0 1 
Explanation:
As described in the Sample Output 2, four paths are possible.
*/

#include <bits/stdc++.h>
using namespace std;
#define N 18
int sol[N][N];

void printAllPossibleSolution(int maze[][N], int n, int row, int col)
{
    if (row == n - 1 && col == n - 1)
    {
        //A possible Path found
        //Print path and return
        sol[row][col] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << sol[i][j] << " ";
            }
        }
        cout << endl;
        sol[row][col] = 0;  //Even if we remove this our solution will work correct
        return;
    }

    //Check if valid position
    if (row < 0 || col < 0 || row == n || col == n || maze[row][col] == 0 || sol[row][col] == 1)
    {
        return;
    }

    //Making position as 1 in sol
    sol[row][col] = 1;

    //Moving D, U, R, L
    printAllPossibleSolution(maze, n, row, col + 1);
    printAllPossibleSolution(maze, n, row, col - 1);
    printAllPossibleSolution(maze, n, row + 1, col);
    printAllPossibleSolution(maze, n, row - 1, col);

    //Backtrack
    sol[row][col] = 0;
}

void rateInAMaze(int maze[][N], int n)
{
    memset(sol, 0, N * N * sizeof(int));
    printAllPossibleSolution(maze, n, 0, 0);
}

int main()
{
    int n;
    cin >> n;
    int maze[N][N];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    rateInAMaze(maze, n);
    return 0;
}
