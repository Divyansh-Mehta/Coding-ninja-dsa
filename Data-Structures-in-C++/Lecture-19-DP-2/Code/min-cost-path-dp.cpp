#include <bits/stdc++.h>
using namespace std;

int minCostPath(int **input, int m, int n)
{
    int **output = new int*[m];
    for (int i = 0; i < n; i++){
        output[i] = new int[n];
    }
    output[m - 1][n - 1] = input[m - 1][n - 1];

    for (int j = n - 2; j >= 0; j--){
        output[m - 1][j] = output[m - 1][j + 1] + input[m - 1][j];
    }

    for (int j = m - 2; j>= 0; j--){
        output[j][n - 1] = output[j + 1][n - 1] + input[j][n - 1];
    }

    for (int i = m - 2; i >= 0; i--){
        for (int j = n - 2; j >=0; j--){
            output[i][j] = min(output[i][j + 1], min(output[i + 1][j], output[i + 1][j + 1])) + input[i][j];
        }
    }

    int ans = output[0][0];
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