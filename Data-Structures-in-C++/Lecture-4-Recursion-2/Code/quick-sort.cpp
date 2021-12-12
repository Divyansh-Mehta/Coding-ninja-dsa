/*
Quick Sort Code

Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.

Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :
Array elements in increasing order (separated by space)

Constraints :
1 <= n <= 10^3

Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8

Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 
*/

#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int input[], int start, int end)
{
    int smaller = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (input[start] >= input[i])
        {
            smaller++;
        }
    }
    swap(input[start], input[start + smaller]);
    int i = start;
    int j = end;
    while (i < start + smaller && j > start + smaller)
    {
        while (input[i] <= input[start + smaller])
            i++;
        while (input[j] > input[start + smaller])
            j--;
        if (i < start + smaller && j > start + smaller)
        {
            swap(input[i], input[j]);
            i++;
            j--;
        }
    }
    return start + smaller;
}

void quickSortHelper(int input[], int start, int end)
{
    if (start >= end)
        return;

    int c = partition(input, start, end);

    quickSortHelper(input, start, c - 1);
    quickSortHelper(input, c + 1, end);
}
void quickSort(int input[], int size)
{
    quickSortHelper(input, 0, size - 1);
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    quickSort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}
