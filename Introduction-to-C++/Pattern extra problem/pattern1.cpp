/*
55555
45555
34555
23455
12345
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
        int j = n - i + 1;
        while (j <= n)
        {
            cout << j;
            j++;
        }
        j = 1;
        while (j <= n - i)
        {
            cout << n;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}