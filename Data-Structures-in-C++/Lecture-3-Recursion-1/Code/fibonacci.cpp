#include <iostream>
using namespace std;

// Time: - O(2^n) Space: - O(2^n)
int fib(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    cout << fib(9);
    return 0;
}