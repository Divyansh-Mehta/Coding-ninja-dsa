/*
Check Max-Heap
Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.

Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.

Output Format :
The first and only line of output contains true if it represents max-heap and false if it is not a max-heap.

Constraints:
1 <= N <= 10^5
1 <= Ai <= 10^5

Time Limit: 1 sec
Sample Input 1:
8
42 20 18 6 14 11 9 4
Sample Output 1:
true
*/

#include <iostream>
using namespace std;

/*Recursive Solution
bool helper(int arr[], int n, int child){
    if (child >= n){
        return true;
    }
    int leftChild = 2 * child + 1;
    int rightChild = 2 * child + 2;
	bool leftOutput = helper(arr, n, leftChild);
    bool rightOutput = helper(arr, n, rightChild);
    if (leftChild < n && leftOutput){
        if(arr[child] < arr[leftChild]){
            leftOutput = false;
        }
    }
    if (rightChild < n && rightOutput){
        if(arr[child] < arr[leftChild]){
            rightOutput = false;
        }
    }
    return rightOutput && leftOutput;
}

bool isMaxHeap(int arr[], int n)
{
    return helper(arr, n, 0);
}
*/

//Iterative solution
bool isMaxHeap(int arr[], int n)
{
    for (int i = 0; 2 * i + 1 < n; i++)
    {
        int leftChild = 2 * i + 1;
        int rightChild = leftChild + 1;

        if (arr[i] < arr[leftChild])
        {
            return false;
        }

        if (rightChild < n && arr[i] < arr[rightChild])
        {
            return false;
        }
    }

    return true;
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

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}