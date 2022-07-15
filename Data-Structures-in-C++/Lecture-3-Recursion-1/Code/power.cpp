/*
Power

Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.
Do this recursively.

Input format :
Two integers x and n (separated by space)

Output Format :
x^n (i.e. x raise to the power n)

Constraints :
1 <= x <= 30
0 <= n <= 30

Sample Input 1 :
 3 4
Sample Output 1 :
81

Sample Input 2 :
 2 5
Sample Output 2 :
32
*/

#include <iostream>
using namespace std;

// Time: - O(n) Space: - O(n)
int power(int x, int n)
{

    if (n == 0)
        return 1;

    return x * power(x, n - 1);
}


//Time: - O(logn) Space: - O(logn)
int power(int x, int n) {
	if (n == 0) return 1;
    
    int fac = 1;
    if (n % 2 != 0){
        fac = x;
    }
    return fac * power(x * x, n / 2);
}


int main()
{
    int x, n;
    cin >> x >> n;

    cout << power(x, n) << endl;
}
