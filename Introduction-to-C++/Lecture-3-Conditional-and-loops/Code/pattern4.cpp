/*
1
2 3
3 4 5
4 5 6 7
*/
#include<iostream>
using namespace std;


int main(){

    int n, i = 1;
   cin >> n;
    while (i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            cout << j + i - 1 << " ";
            j = j + 1;
        }
        cout << endl;
        i = i + 1;
    }
    return 0;
  
}