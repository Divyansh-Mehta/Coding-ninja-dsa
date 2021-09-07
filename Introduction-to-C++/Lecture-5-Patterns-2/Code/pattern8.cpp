/* n = 5
  *
 ***
*****
 *** 
  *  
*/

#include<iostream>
using namespace std;


int main() {
    
    /*  Read input as specified in the question.
     * Print output as specified in the question.
     */
    int n;
    cin >> n;
    int i = 1;
    int up = (n + 1) / 2, down = (n - 1) / 2;
    while (i <= up){
        int j = 1;
        while (j <= up - i){
            cout << " ";
            j++;
        }
        j = 1;
        while (j <= 2 * i - 1){
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }
    i = down;
    while (i >= 1){
        int j = 1;
        while (j <= down - i + 1){
            cout << " ";
            j++;
        }
        j = 1;
        while(j <= 2 * i - 1){
            cout << "*";
            j++;
        }
        cout << endl;
        i--;
    }
    return 0;
}
