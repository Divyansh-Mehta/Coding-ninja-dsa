/*
1     1
 2   2
  3 3
   4
  3 3
 2   2
1     1
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i = 1;
    while (i <= n){
        int j = 1;
        while (j <= i - 1){
            cout << " ";
            j++;
        }
        if (i == n)
        {
            cout << n;
        }
        else{
            cout << i;
            int j = 1;
            while (j <= 2 * (n - i) - 1){
                cout << " ";
                j++;
            }
            cout << i;
        }
        cout << endl;
        i++;
    }
    i = n - 1;
    while (i >= 1){
        int j = 1;
        while (j <= i - 1){
            cout << " ";
            j++;
        }
        cout << i;
        j = 1;
        while (j <= 2 * (n - i) - 1){
            cout << " ";
            j++;
        }
        cout << i;
        cout << endl;
        i--;
    }
    return 0;
}