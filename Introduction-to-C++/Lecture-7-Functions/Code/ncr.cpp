#include <iostream>
using namespace std;

int factorial(int n){
    int i = 1, fact = 1;
    while (i <= n){
        fact *= i;
        i++;
    }
    return fact;
}

int main(){
    int n, r;
    cin >> n >> r;
    cout << factorial(n) / (factorial(r) * factorial (n - r));
    return 0;
}