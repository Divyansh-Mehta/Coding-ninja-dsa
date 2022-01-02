#include <iostream>
using namespace std;

int fibo_hepler(int n, int ans[]){
    if (n <= 1){
        return n;
    }

    //Check if Output already Exists
    if (ans[n] != -1){
        return ans[n];
    }

    //If it doesnt exists then calculate and save it and then return
    //Calculating
    int a = fibo_hepler(n - 1, ans);
    int b = fibo_hepler(n - 2, ans);
    //Saving
    ans[n] = a + b;
    //Returning the final Output
    return ans[n];
}

int fibo(int n){
    int *ans = new int [n + 1];

    for (int i = 0; i < n + 1; i++){
        ans[i] = -1;
    }

    return fibo_hepler(n, ans);
}

int main(){
    cout << fibo(21);

    return 0;
}