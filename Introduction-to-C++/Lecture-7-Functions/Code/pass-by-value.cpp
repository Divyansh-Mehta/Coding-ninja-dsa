#include <iostream>
using namespace std;

void increase(int x, int y) // formal parameters
{
    x++;
    y += 2;
    cout << x << ":" << y << endl;
}

int main(){
    int a = 10, b = 20;
    increase(a, b);
    cout << a << ":" << b;
    return 0;
}