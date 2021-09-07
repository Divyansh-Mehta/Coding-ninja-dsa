/*
   1
  232
 34543
4567654
*/

#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= n - i)
        {
            cout << " ";
            j++;
        }
        j = i;
        while (j <= 2 * i - 1)
        {
            cout << j;
            j++;
        }
        j = j - 2;
        while (j >= i)
        {
            cout << j;
            j--;
        }
        cout << endl;
        i++;
    }
    return 0;
}
