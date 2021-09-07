/*
4444
333
22
1
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
        while (j <= n - i + 1)
        {
            cout << n - i + 1;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
