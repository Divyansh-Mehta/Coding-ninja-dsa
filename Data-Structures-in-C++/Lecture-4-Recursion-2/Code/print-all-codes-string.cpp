/*
Print all Codes - String

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.

Input format :
A numeric string S

Output Format :
All possible codes in different lines

Constraints :
1 <= Length of String S <= 10

Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
*/

#include <iostream>
using namespace std;

#include <string.h>
using namespace std;

void helper(string input, string output)
{
    if (input.empty())
    {
        cout << output << endl;
        return;
    }
    char firstchar = 'a' + int(input[0] - 48) - 1;
    helper(input.substr(1), output + firstchar);
    if (input[1] != '\0')
    {
        int no = (input[0] - 48) * 10 + (input[1] - 48);
        if (no <= 27)
        {
            char secondchar = 'a' + no - 1;
            helper(input.substr(2), output + secondchar);
        }
    }
}
void printAllPossibleCodes(string input)
{
    string output;
    helper(input, output);
}

int main()
{
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
