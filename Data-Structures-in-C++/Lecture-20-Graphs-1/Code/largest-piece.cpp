/*
Largest Piece
It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?

Input Format :
The first line of input contains an integer, that denotes the value of N. 
Each of the following N lines contain N space separated integers.

Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.

Constraints :
1 <= N <= 1000
Time Limit: 1 sec

Sample Input 1:
2
1 1
0 1
Sample Output 1:
3
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int helper(vector<vector<int>> &cake, int i, int j, bool **visited, int n)
{
    if (visited[i][j])
    {
        return 0;
    }
    visited[i][j] = true;

    int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int sum = 1;
    for (int k = 0; k < 4; k++)
    {
        int nextI = i + move[k][0];
        int nextJ = j + move[k][1];
        if (nextI >= 0 && nextJ >= 0 && nextI < n && nextJ < n && cake[nextI][nextJ] == 1)
        {
            sum += helper(cake, nextI, nextJ, visited, n);
        }
    }
    return sum;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && cake[i][j] == 1)
            {
                count = max(count, helper(cake, i, j, visited, n));
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}