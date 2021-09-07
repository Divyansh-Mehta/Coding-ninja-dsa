#include<iostream>
using namespace std;
 
int main()
{
    int n, d = 2;
    bool divided = false;
    cin >> n;
    
    while(d < n)
    {
        if (n % d == 0)
        {
            cout << "Not prime";
            divided = true;
            break;
        }
        d = d + 1;
    }
    if (!divided)
    {
        cout << "Prime";
    }
return 0;
}