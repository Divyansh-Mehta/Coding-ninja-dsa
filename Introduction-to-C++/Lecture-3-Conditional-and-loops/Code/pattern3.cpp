/*
      1
    2 3
  4 5 6
7 8 9 10
*/
#include <iostream>
using namespace std;

int main()
{
    int n, i = 1, val = 1;
    cin >> n;
    while (i <= n)
    {
        int j = 1;
        int space = 1;
        while (space <= n - i)
        { 
            cout<<"  ";
            space = space + 1;
        }
        while (j <= i)
        {
            cout<< val << " ";
            val = val + 1;
            j = j + 1;
        }
        cout << endl;
        i = i + 1;
    }
    return 0;
}