/*
Geometric Sum

Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
using recursion.

Input format :
Integer k

Output format :
Geometric sum (upto 5 decimal places)

Constraints :
0 <= k <= 1000

Sample Input 1 :
3
Sample Output 1 :
1.87500

Sample Input 2 :
4
Sample Output 2 :
1.93750
*/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

//Time: - O(k) Space: - O(k)
double geometricSum(int k)
{
    if (k == 0)
        return 1;

    double smalloutput = geometricSum(k - 1);

    return smalloutput + 1 / (pow(2, k));
}

int main()
{
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;
}
