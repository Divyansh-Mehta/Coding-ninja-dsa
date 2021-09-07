#include <iostream>
using namespace std;

int main()
{

    int x, n, count = 1, result = 1;
    cin >> x >> n;

    while (count <= n)
    {
        result = result * x;
        count = count + 1;
    }
    cout << result;
    return 0;
}
