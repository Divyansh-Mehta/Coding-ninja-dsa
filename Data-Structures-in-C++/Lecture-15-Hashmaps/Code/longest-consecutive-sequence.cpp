/*
Longest Consecutive Sequence
Send Feedback
You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.
Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
Output format:
The first and only line of output contains starting and ending element of the longest consecutive sequence. If the length of longest consecutive sequence, then just print the starting element.
Constraints :
0 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 12 
Sample Input 2 :
7
3 7 2 1 9 8 41
Sample Output 2 :
7 9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but we should select [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array and therefore, the output will be 7 9, as we have to print starting and ending element of the longest consecutive sequence.
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 16
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    unordered_map<int, bool> ump;
    unordered_map<int, int> index;
    int start, end, maxCount = 0;

    for (int i = 0; i < n; i++)
    {
        ump[arr[i]] = true;
        if (index.count(arr[i]) == 0)
        {
            index[arr[i]] = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (ump[arr[i]])
        {
            int startT = arr[i], endT = arr[i], count = 1;
            while (ump[endT + 1])
            {
                count++;
                ump[++endT] = false;
            }
            while (ump[startT - 1])
            {
                count++;
                ump[--startT] = false;
            }
            if (count > maxCount)
            {
                start = startT;
                end = endT;
                maxCount = count;
            }
            else if (count == maxCount)
            {
                if (index[startT] < index[start])
                {
                    start = startT;
                    end = endT;
                    maxCount = count;
                }
            }
        }
    }

    vector<int> ans;
    ans.push_back(start);
    if (maxCount > 1)
    {
        ans.push_back(end);
    }
    return ans;
}

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
