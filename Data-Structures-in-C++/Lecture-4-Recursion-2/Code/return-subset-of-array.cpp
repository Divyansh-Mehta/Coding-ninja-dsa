/*
Return subset of an array

Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.

Input format :
Line 1 : Size of array

Line 2 : Array elements (separated by space)

Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12
20
20 12
15
15 12
15 20
15 20 12
*/

#include <iostream>
using namespace std;

/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain
    {{0}, 		// Length of this subset is 0
    {1, 2},		// Length of this subset is 1
    {1, 1},		// Length of this subset is also 1
    {2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int subset(int input[], int n, int output[][20])
{
    if (n == 0)
    {
        output[0][0] = {0};
        return 1;
    }

    int c = subset(input, n - 1, output);

    for (int i = 0; i < c; i++)
    {
        int size = output[i][0];
        for (int j = 0; j <= size; j++)
        {
            output[i + c][j] = output[i][j];
        }
        output[i + c][size + 1] = input[n - 1];
        output[i + c][0]++;
    }
    return c * 2;
}

int subset(int input[], int n, int output[][20])
{
    if (n == 0)
    {
        output[0][0] = 0;
        return 1;
    }

    int size = subset(input + 1, n - 1, output);

    for (int i = 0; i < size; i++)
    {
        output[size + i][0] = output[i][0] + 1;
        output[size + i][1] = input[0];
        for (int j = 2; j < output[size + i][0] + 1; j++)
        {
            output[size + i][j] = output[i][j - 1];
        }
    }
    return 2 * size;
}

int main()
{
    int input[20], length, output[35000][20];
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];

    int size = subset(input, length, output);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}
