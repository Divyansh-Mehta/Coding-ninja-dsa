/*
Find Unique

You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.
 Note:
Unique element is always present in the array/list according to the given condition.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Output Format :
For each test case, print the unique element present in the array.

Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^3

Time Limit: 1 sec

Sample Input 1:
1
7
2 3 1 6 3 6 2
Sample Output 1:
1

Sample Input 2:
2
5
2 4 7 2 7
9
1 3 1 3 6 6 7 10 7
Sample Output 2:
4
10
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Approach - 1 O(n^2)
int findUnique(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		bool found = false;
		for (int j = 0; j < size; j++)
		{
			if (arr[i] == arr[j] && i != j)
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			return arr[i];
		}
	}
}

// Approach - 2 // O(nlogn)
int findUnique2(int *arr, int size)
{
	sort(arr, arr + size);
	for (int i = 0; i < size; i += 2)
	{
		if (arr[i] != arr[i + 1])
		{
			return arr[i];
		}
	}
	return arr[size - 1];
}

// Approach - 3 //O(n)
int findUnique3(int *arr, int size)
{
    int xOr = 0;
    for (int i = 0; i < size; i++){
        xOr ^= arr[i];
    }
    return xOr;
}

int main()
{

	int t;
	cin >> t;

	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		cout << findUnique(input, size) << endl;
	}

	return 0;
}

/* Summary
unsorted :- best time :- O(n) using xor
sorted :- best time :- O(logn) using binary Search
*/