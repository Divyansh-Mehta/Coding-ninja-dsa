/*
Check Palindrome (recursive)

Check whether a given String S is a palindrome using recursion. Return true or false.

Input Format :
String S

Output Format :
'true' or 'false'

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
racecar
Sample Output 1:
true

Sample Input 2 :
ninja
Sample Output 2:
false
*/

#include <iostream>
using namespace std;

int length(char input[])
{
    int len = 0;
    while (input[len] != '\0')
    {
        len++;
    }
    return len;
}

bool check(char input[], int start, int end)
{
    if (start >= end)
        return true;

    if (input[start] != input[end])
        return false;
    return check(input, start + 1, end - 1);
}

// Time: - O(n) Space: - O(n)
bool checkPalindrome(char input[])
{
    int start = 0;
    int end = length(input) - 1;
    return check(input, start, end);
}

int main()
{
    char input[50];
    cin >> input;

    if (checkPalindrome(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
