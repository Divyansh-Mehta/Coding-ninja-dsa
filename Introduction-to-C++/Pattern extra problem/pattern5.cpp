/*
*000*000*
0*00*00*0
00*0*0*00
000***000
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int i = 1;
    while (i <= n){
        int j = 1;
        while (j <= n){
            if (j == i) cout << "*";
            else cout << "0";
            j++;
        }
        cout << "*";
        j = 1;
        while (j <= n){
            if (j == n - i + 1) cout << "*";
            else cout << "0";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}