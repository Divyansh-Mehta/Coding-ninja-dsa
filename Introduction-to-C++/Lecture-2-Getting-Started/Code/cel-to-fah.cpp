#include<iostream>
using namespace std;
 
int main()
{
    int c;
    float fah;
    cin>>c;
    fah = (5.0 / 9) * (c - 32);
    //fah = (5 * (c - 32)) / 9;
    cout<<fah<<endl;
return 0;
}