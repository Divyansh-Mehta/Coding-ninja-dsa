#include <iostream>
using namespace std;

int ternarySearch(int arr[], int n, int x)

{
    int l = 0, r = n - 1;
    while (r >= l)
    {

        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (arr[mid1] == x)
        {
            return mid1;
        }
        if (arr[mid2] == x)
        {
            return mid2;
        }

        if (x < arr[mid1])
        {

            r = mid1 - 1;
        }
        else if (x > arr[mid2])
        {

            l = mid2 + 1;
        }
        else
        {

            l = mid1 + 1;
            r = mid2 - 1;
        }
    }

    return -1;
}

int main()
{
    int p, key;

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    p = ternarySearch(arr, 10, 5);

    cout << "Index of " << 5 << " is " << p << endl;

    key = 50;

    p = ternarySearch(arr, 10, 50);

    cout << "Index of " << 50 << " is " << p;
}