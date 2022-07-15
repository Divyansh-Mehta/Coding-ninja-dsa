/*
String to Integer

Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.

Input format :
Numeric string S (string, Eg. "1234")

Output format :
Corresponding integer N (int, Eg. 1234)

Constraints :
0 <= |S| <= 9
where |S| represents length of string S.

Sample Input 1 :
00001231
Sample Output 1 :
1231

Sample Input 2 :
12567
Sample Output 2 :
12567
*/

#include <iostream>
#include <cmath>
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

// Time: - O(n ^ 2) Space: - O(n)
int stringToNumber(char input[])
{
    if (input[0] == '\0')
    {
        return 0;
    }
    int ans = stringToNumber(input + 1);

    return ans + (input[0] - '0') * pow(10, length(input) - 1);
}

int helper(char input[], int size)
{
    if (size == 0)
    {
        return 0;
    }

    int ans = helper(input, size - 1);

    return ans * 10 + input[size - 1] - '0';
}

// Time: - O(n) Space: - O(n)
int stringToNumber(char input[])
{
    int size = length(input);
    return helper(input, size);
}

int main()
{
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
