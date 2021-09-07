#include <iostream>
using namespace std;

int main()
{

    int digit, n, sume = 0, sumo = 0;
    cin >> n;
    while (n > 0)
    {
        digit = n % 10;
        if (digit % 2 == 0)
        {
            sume = sume + digit;
        }
        else
        {
            sumo = sumo + digit;
        }
        n = n / 10;
    }
    cout << sume << " " << sumo;
    return 0;
}
