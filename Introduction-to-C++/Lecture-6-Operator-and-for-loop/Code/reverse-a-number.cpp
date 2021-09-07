/*
Reverse of a number

Write a program to generate the reverse of a given number N. Print the corresponding reverse number.
Note : If a number has trailing zeros, then its reverse will not include them. For e.g., reverse of 10400 will be 401 instead of 00401.


Input format :
Integer N

Output format :
Corresponding reverse number

Constraints:
0 <= N < 10^8

Sample Input 1 :
1234
Sample Output 1 :
4321

Sample Input 2 :
1980
Sample Output 2 :
891
*/

#include <iostream>
using namespace std;

int main()
{
    int n, new_no = 0;
    cin >> n;
    while (n > 0)
    {
        new_no = new_no * 10 + n % 10;
        n /= 10;
    }
    cout << new_no;
    return 0;
}
