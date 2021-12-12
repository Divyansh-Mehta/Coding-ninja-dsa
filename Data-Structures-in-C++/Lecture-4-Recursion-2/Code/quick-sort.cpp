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

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
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
