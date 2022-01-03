#include <bits/stdc++.h>
using namespace std;

int helper(int **input, int m, int n, int row, int col, int **output){
    if (row >= m || col >= n){
        return INT_MAX;
    }

    if (row == m - 1 && col == n - 1){
        return input[row][col];
    }

    if (output[row][col] != -1){
        return output[row][col];
    }

    int x = helper(input, m, n, row + 1, col, output);
    int y = helper(input, m, n, row, col + 1, output);
    int z = helper(input, m, n, row + 1, col + 1, output);

    output[row][col] = input[row][col] + min(x, min(y, z));

    return output[row][col];    
}

int minCostPath(int **input, int m, int n)
{
    int **output = new int*[m];
    for (int i = 0; i < n; i++){
        output[i] = new int[n];
        for (int j = 0; j < n; j++){
            output[i][j] = -1;
        }
    }
    int ans = helper(input, m, n, 0, 0, output);

    for (int i = 0; i < m; i++){
        delete []output[i];
    }
    delete []output;
    return ans;
}

int main()
{
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}