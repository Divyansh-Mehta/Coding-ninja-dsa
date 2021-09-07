#include <iostream>
using namespace std;

int main()
{
    char name[100];
    cin >> name;
    cout << name << endl;
    name[5] = 'd';
    cout << name << endl;
    for (int i = 0; i <= 5; i++){
        cout << name[i];
    }

    return 0;
}