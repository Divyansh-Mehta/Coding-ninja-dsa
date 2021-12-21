#include <iostream>
#include <unordered_map>
#include<vector>
using namespace std;

vector<int> removeDuplicates(int *arr, int n){
    vector<int> ans;
    unordered_map<int, bool> seen;

    for (int i = 0; i < n; i++){
        if (seen.count(arr[i]) > 0){
            continue;
        }
        seen[arr[i]] = true;
        ans.push_back(arr[i]);
    }
    return ans;
}

int main(){
   int a[] = {1, 2, 3, 4, 3, 6, 7, 2, 10};
   vector<int> ans = removeDuplicates(a, 9);
   for (auto a : ans){
       cout << a << " ";
   } 
   return 0;
}