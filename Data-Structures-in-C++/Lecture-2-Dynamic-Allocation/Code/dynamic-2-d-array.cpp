#include <iostream>
using namespace std;

int main(){
    
    // Taking rows (m) and column (n)
    int n, m;
    cin >> m >> n;
    
    // Dynamically allocating 2-D array
    int **arr = new int *[m];
    for (int i = 0; i < m; i++){
        *(arr + i) = new int [n];  // we could also use arr[i] in place of *(arr + i)
    }

    // Initializing 2-D array from user
    // M-1
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> *(*(arr + i) + j);
        }
    }

    /* M-2
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    */

   // Printing 2-D array
   for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocating 2-D array
    for (int i = 0; i < m; i++){
        delete [] arr[i];
    }
    delete [] arr;

    return 0;
}