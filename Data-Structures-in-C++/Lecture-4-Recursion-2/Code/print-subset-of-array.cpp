/*
Print Subsets of Array

Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

Note : The order of subsets are not important. Just print the subsets in different lines.

Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)

Constraints :
1 <= n <= 15

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
#include <vector>
using namespace std;

void helper(int input[], int size, int output[], int m)
{
    if (size == 0)
    {
        for (int i = 0; i < m; i++)
        {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }
    helper(input + 1, size - 1, output, m);
    output[m] = input[0];
    m++;
    helper(input + 1, size - 1, output, m);
}
void printSubsetsOfArray(int input[], int size)
{

    int output[15];
    helper(input, size, output, 0);
}

//Using vector
void helper(int *input, int size, vector<int> output){
    if (size == 0){
        for (auto num : output){
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    
    helper(input + 1, size - 1, output);
    output.push_back(input[0]);
    helper(input + 1, size - 1, output);
}

void printSubsetsOfArray(int input[], int size) {
    helper(input, size, vector<int>{});
    //helper(input, size, {}); it is also allowed
}

int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);
}
