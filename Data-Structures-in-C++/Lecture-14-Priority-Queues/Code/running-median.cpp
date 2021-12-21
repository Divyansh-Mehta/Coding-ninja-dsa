/*
Running Median
You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.

Input Format :
The first line of input contains an integer 'N', denoting the number of integers in the stream.

The second line of input contains 'N' integers separated by a single space.

Output Format :
Print the running median for every integer added to the running list in one line (space-separated).

Input Constraints
0 <= N <= 10 ^ 5
1 <= ARR[i] <= 10 ^ 5

Time Limit: 1 sec

Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6 4 2 2 3 4
Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4

Sample Input 2 :
5
5 4 3 2 1
Sample Output 2 :
5 4 4 3 3
*/

#include <iostream>
#include <queue>
using namespace std;

void findMedian(int *arr, int n)
{
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            max.push(arr[i]);
        }
        else
        {
            if (max.top() < arr[i])
            {
                min.push(arr[i]);
            }
            else
            {
                max.push(arr[i]);
            }
        }

        if ((int)(max.size() - min.size()) > 1)
        {
            int x = max.top();
            max.pop();
            min.push(x);
        }
        else if ((int)(min.size() - max.size()) > 1)
        {
            int x = min.top();
            min.pop();
            max.push(x);
        }

        if (max.size() == min.size())
        {
            cout << (min.top() + max.top()) / 2 << " ";
        }

        else if (max.size() > min.size())
        {
            cout << max.top() << " ";
        }
        else
        {
            cout << min.top() << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    findMedian(arr, n);

    delete[] arr;
}
