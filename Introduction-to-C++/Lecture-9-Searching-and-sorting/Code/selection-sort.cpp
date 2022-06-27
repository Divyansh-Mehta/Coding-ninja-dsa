#include <iostream>
using namespace std;


//Time: - O(n^2) Space: - O(1)
void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int min = arr[i], minIndex = i;
        // Finding minimum
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minIndex = j;
            }
        }
        // swaping
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main()
{
    int arr[] = {4, 2, 7, 1, 6, 6, 1};
    selectionSort(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}