/*
1  2  3  4  5
16          6
15          7
14          8
13 12 11 10 9
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int i = 1, c1 = 4 * n - 4, c2 = n + 1;
    while (i <= n){
        if(i == 1){
            int j = 1;
            while (j <= n){
                cout << j;
                if (j <= 9) cout << "  ";
                else cout << " ";
                j++;
            }
            cout << endl;
        }
        else if (i != 1 && i!= n){
            cout << c1;
            if (c1 <= 9) cout << "  ";
            else cout << " ";
            c1--;
            int j = 1;
            while (j <= n - 2){
                cout << "   ";
                j++;
            }
            cout << c2;
            if (c2 <= 9) cout << "  ";
            else cout << " ";
            c2++;
            cout << endl;
        }
        else{
            int j = 1;
            while (j <= n){
                cout << c1;
                if (c1 <= 9) cout << "  ";
                else cout << " ";
                c1--;
                j++;
            }
        }
        i++;
           }
           return 0;
 
}

