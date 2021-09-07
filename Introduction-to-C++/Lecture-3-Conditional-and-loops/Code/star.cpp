/*
   *
  *** 
 ***** 
*******
*/
#include <iostream>
using namespace std;

int main()
{

    int n, i = 1;
    cin >> n;
    while (i <= n)
    {
        int space = 1, star = 1;
        while (space <= n - i)
        {
            cout << " ";
            space = space + 1;
        }
        while (star <= 2 * i - 1)
        {
            cout << "*";
            star = star + 1;
        }
        cout << endl;
        i = i + 1;
    }
    return 0;
}
