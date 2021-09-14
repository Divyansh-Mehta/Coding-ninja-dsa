/*
Merge Sort Code

Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.

Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :
Array elements in increasing order (separated by space)

Constraints :
1 <= n <= 10^3

Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8

Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
*/

#include <iostream>
using namespace std;

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

    delete [] p;
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


int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}