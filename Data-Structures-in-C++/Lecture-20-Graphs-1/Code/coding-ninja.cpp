/*
Coding Ninjas
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.

Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
Each of the following N lines contain M characters. Please note that characters are not space separated.

Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.

Constraints :
1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second

Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output 1:
1
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool DFS(vector<vector<char>> &board, int i, int j, int n, int m, bool **visited, string s)
{
    if (s.empty())
    {
        return true;
    }
    visited[i][j] = true;
    int move[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

    for (int k = 0; k < 8; k++)
    {
        int newI = i + move[k][0];
        int newJ = j + move[k][1];
        if (newI < n && newJ < m && newI >= 0 && newJ >= 0 && board[newI][newJ] == s[0] && !visited[newI][newJ])
        {
            if (DFS(board, newI, newJ, n, m, visited, s.substr(1)))
            {
                return true;
            }
        }
    }
    visited[i][j] = false;
    return false;
}

bool hasPath(vector<vector<char>> &board, int n, int m)
{
    bool **visited = new bool *[n];
    string s = "CODINGNINJA";
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'C')
            {
                if (DFS(board, i, j, n, m, visited, s.substr(1)))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}