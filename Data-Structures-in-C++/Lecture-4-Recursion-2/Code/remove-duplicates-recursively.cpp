/*
Remove Duplicates Recursively

Given a string S, remove consecutive duplicates from it recursively.

Input Format :
String S

Output Format :
Output string

Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string

Sample Input 1 :
aabccba
Sample Output 1 :
abcba

Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz
*/

#include <iostream>
using namespace std;

// Time: - O(n^2) Space: - O(n)
void removeConsecutiveDuplicates(char *input)
{
    if (input[0] == '\0')
        return;

    removeConsecutiveDuplicates(input + 1);

    if (input[0] == input[1])
    {
        for (int i = 0; input[i] != '\0'; i++)
        {
            input[i] = input[i + 1];
        }
    }
}

void helper(char *input, int newIndex, int index)
{
    if (input[index] == '\0')
    {
        input[newIndex++] = input[index - 1];
        input[newIndex] = '\0';
        return;
    }

    if (input[index] == input[index - 1])
    {
        helper(input, newIndex, index + 1);
    }
    else
    {
        input[newIndex] = input[index - 1];
        helper(input, newIndex + 1, index + 1);
    }
}

//Time: - O(n) Space: - O(n)
void removeConsecutiveDuplicates(char *input)
{
    helper(input, 0, 1);
}

int main()
{
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}