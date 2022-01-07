/*
Loot Houses
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.

Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.

The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.

Output format :
Print the the maximum money that can be looted.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110

Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90
Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.
*/

#include <iostream>
using namespace std;

/*
Brute Force
int helper(int *arr, int i, int n)
{
    if (i >= n)
    {
        return 0;
    }
    int inc = helper(arr, i + 2, n) + arr[i];
    int notInc = helper(arr, i + 1, n);
    return max(inc, notInc);
}
int maxMoneyLooted(int *arr, int n)
{
    return helper(arr, 0, n);
}
*/

/*
Memoization
int helper(int *arr, int i, int n, int *output)
{
    if (i >= n)
    {
        return 0;
    }
    if (output[i] != -1)
    {
        return output[i];
    }
    int inc = helper(arr, i + 2, n, output) + arr[i];
    int notInc = helper(arr, i + 1, n, output);
    output[i] = max(inc, notInc);
    return output[i];
}
int maxMoneyLooted(int *arr, int n)
{
    int *output = new int[n];
    for (int i = 0; i < n; i++)
    {
        output[i] = -1;
    }
    return helper(arr, 0, n, output);
}
*/

//DP
int maxMoneyLooted(int *arr, int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    int *dp = new int[n];
    dp[0] = arr[0];
    if (n > 1)
    {
        dp[1] = max(arr[0], arr[1]);
    }
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 2] + arr[i], dp[i - 1]);
    }
    int ans = dp[n - 1];
    delete[] dp;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << maxMoneyLooted(arr, n);

    delete[] arr;
}