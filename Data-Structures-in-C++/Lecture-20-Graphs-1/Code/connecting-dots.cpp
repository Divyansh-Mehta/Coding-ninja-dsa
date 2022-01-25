/*
Connecting Dots
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.

Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns of the board. 
Each of the following N lines contain M characters. Please note that characters are not space separated. Each character is an uppercase Latin letter.

Output Format :
Print true if there is a cycle in the board, else print false.

Constraints :
2 <= N <= 1000
2 <= M <= 1000
Time Limit: 1 second

Sample Input 1:
3 4
AAAA
ABCA
AAAA
Sample Output 1:
true
*/

#include <iostream>
#include <vector>
using namespace std;

bool helper(vector<vector<char>> &board, int x, int y, int preX, int preY, char color, bool **visited, int n, int m)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return false;
    }

    if (board[x][y] != color)
    {
        return false;
    }

    if (visited[x][y])
    {
        return true;
    }

    visited[x][y] = true;

    int path[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    for (int i = 0; i < 4; i++)
    {
        int nextX = x + path[i][0];
        int nextY = y + path[i][1];
        if (nextX == preX && nextY == preY)
        {
            continue;
        }
        if (helper(board, nextX, nextY, x, y, color, visited, n, m))
        {
            return true;
        }
    }

    return false;
}

bool hasCycle(vector<vector<char>> &board, int n, int m)
{
    bool **visited = new bool *[n];
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
            if (!visited[i][j])
            {
                if (helper(board, i, j, -1, -1, board[i][j], visited, n, m))
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

    cout << (hasCycle(board, n, m) ? "true" : "false");
}