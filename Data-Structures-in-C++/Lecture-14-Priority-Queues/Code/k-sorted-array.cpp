#include <iostream>
#include <queue>
using namespace std;

void kSortedArray(int arr[], int n, int k){
    priority_queue<int> pq;
    for (int i = 0; i < k; i++){
        pq.push(arr[i]);
    }
    int j = 0;
    for (int i = k; i < n; i++){
        arr[j++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    while(!pq.empty()){
        arr[j++] = pq.top();
        pq.pop();
    }
}

int main(){
    int arr[] = {10, 12, 15, 9, 6};
    int k = 3;
    kSortedArray(arr, 5, 3);
    for (int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }

    return 0;
}