#include <iostream>
using namespace std;

int main()
{
    int i;
    cout << &i << endl;
    int *p = &i;
    cout << p;
    return 0;
}