#include <sys/time.h>
#include <iostream>
using namespace std;

long getTimeinMicroSeconds(){
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

void mergeArray(int input[], int start, int end, int mid){
    int *p = new int [end - start + 1];
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end){
        if (input[i] <= input[j]){
            p[k] = input[i];
            i++;
            k++;
        }
        else{
            p[k] = input[j];
            j++;
            k++;
        }
    }
    while(i <= mid){
        p[k] = input[i];
        i++;
        k++;
    }
    while(j <= end){
        p[k] = input[j];
        j++;
        k++;
    }
    for (int l = 0; l < k; l++){
        input[start] = p[l];
        start++;
    }
    delete []p;
}



void mergeSortHelper(int input[], int start, int end){
    if (start >= end)
        return;
    
    int mid = (start + end) / 2;
    mergeSortHelper(input, start, mid);
    mergeSortHelper(input, mid + 1, end);
    
    mergeArray(input, start, end, mid);
}


void mergeSort(int input[], int size){
    mergeSortHelper(input, 0, size - 1);
  
}

int main(){
    for (int n = 10; n <= 1000000; n *= 10){
        int *arr = new int[n];
        long starttime, endtime;
        for (int i = 0; i < n; i++){
            arr[i] = n - i;
        }
        starttime = getTimeinMicroSeconds();
        mergeSort(arr, n);
        endtime = getTimeinMicroSeconds();
        cout << "Merge Sort n = " << n << " time = " << endtime - starttime << endl;
    }
    return 0;
}
