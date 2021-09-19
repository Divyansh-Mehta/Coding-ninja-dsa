#include <sys/time.h>
#include <iostream>
using namespace std;

long getTimeinMicroSeconds(){
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int input[], int start, int end){
    int smaller = 0;
    for (int i = start + 1; i <= end; i++){
        if (input[start] >= input[i]){
            smaller++;
        }
    }
    swap(input[start], input[start + smaller]);
    int i = start; 
    int j = end;
    while(i < start + smaller && j > start + smaller){
        while (input[i] <= input[start + smaller]) i++;
        while (input[j] > input[start + smaller]) j--;
        if (i < start + smaller && j  > start + smaller){
        swap(input[i], input[j]);
        i++;
        j--;
        }
    }
    return start + smaller;
}

void quickSortHelper(int input[], int start, int end){
    if (start >= end)
        return;
    
    int c = partition(input, start, end);
    
    quickSortHelper(input, start, c - 1);
    quickSortHelper(input, c + 1, end);
}
void quickSort(int input[], int size) {

    quickSortHelper(input, 0, size - 1);
    

}

int main(){
    for (int n = 10; n <= 1000000; n *= 10){
        int *arr = new int[n];
        long starttime, endtime;
        for (int i = 0; i < n; i++){
            arr[i] = n - i;
        }
        starttime = getTimeinMicroSeconds();
        quickSort(arr, n);
        endtime = getTimeinMicroSeconds();
        cout << "Merge Sort n = " << n << " time = " << endtime - starttime << endl;
    }
    return 0;
}
