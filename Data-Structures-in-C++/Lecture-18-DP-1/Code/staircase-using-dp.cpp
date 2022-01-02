/*
Code : Staircase using Dp
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.

Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.

Output format :
Print the total possible number of ways.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1:
4
Sample Output 1:
7

Sample Input 2:
10
Sample Output 2:
274
*/

#include <iostream>
using namespace std;

long staircase(int n)
{
    if (n <= 2)
    {
        return n;
    }

    long *dp = new long[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << staircase(n);
}