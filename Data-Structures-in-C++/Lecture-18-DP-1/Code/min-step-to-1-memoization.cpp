#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int helper(int n, int *ans){
    if (n == 1){
        return 0;
    }
    
    if (ans[n] != -1){
        return ans[n];
    }

    int a = helper(n - 1, ans);
    int b = INT_MAX;
    if (n % 2 == 0){
        b = helper(n / 2, ans);
    }
    int c = INT_MAX;
    if (n % 3 == 0){
        c = helper(n / 3, ans);
    }

    ans[n] = min(a, min(b, c)) + 1;
    return ans[n];
}

int countMinStepTo1(int n){
    int *ans = new int[n + 1];

    for (int i = 0; i < n + 1; i++){
        ans[i] = -1;
    }

    return helper(n, ans);
}

int main(){
    cout << countMinStepTo1(10);
}