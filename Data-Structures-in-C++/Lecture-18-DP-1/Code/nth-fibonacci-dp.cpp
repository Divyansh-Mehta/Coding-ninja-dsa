#include <iostream>
using namespace std;

int fibo(int n){
    int *dp = new int [n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main(){
    cout << fibo(21);

    return 0;
}