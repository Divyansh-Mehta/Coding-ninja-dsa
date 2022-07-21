/*
Print Subset Sum to K

Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.

Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K

Sample Input:
9
5 12 3 17 1 18 15 3 17
6
Sample Output:
3 3
5 1
*/

#include <iostream>
#include <vector>
using namespace std;

void helper(int input[], int size, int output[], int k, int m)
{
    if (size == 0)
    {
        if (k == 0)
        {
            for (int i = 0; i < m; i++)
            {
                cout << output[i] << " ";
            }
            cout << endl;
            return;
        }
        else
            return;
    }

    helper(input + 1, size - 1, output, k, m);
    output[m] = input[0];
    m++;
    helper(input + 1, size - 1, output, k - input[0], m);
}

void printSubsetSumToK(int input[], int size, int k)
{
    int output[100];
    helper(input, size, output, k, 0);
}

// Using vector
void helper(int input[], int size, vector<int> output, int k)
{
    if (size == 0)
    {
        if (k == 0)
        {
            for (auto num : output)
            {
                cout << num << " ";
            }
            cout << endl;
            return;
        }
        return;
    }

    helper(input + 1, size - 1, output, k);
    output.push_back(input[0]);
    helper(input + 1, size - 1, output, k - input[0]);
}

void printSubsetSumToK(int input[], int size, int k)
{
    helper(input, size, vector<int>{}, k);
}

int main()
{
    int input[1000], length, k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    cin >> k;
    printSubsetSumToK(input, length, k);
}
