/*
Return all codes - String

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.

Input format :
A numeric string

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

int getCodes(string input, string output[10000])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }
    string output1[500];
    string output2[500];
    char firstchar = 'a' + int(input[0] - 48) - 1;
    char secondchar = '\0';
    int size1 = getCodes(input.substr(1), output1);
    int size2 = 0;
    if (input[1] != '\0')
    {
        int no = (input[0] - 48) * 10 + (input[1] - 48);
        if (no <= 26)
        {
            secondchar = 'a' + no - 1;
            size2 = getCodes(input.substr(2), output2);
        }
    }
    for (int i = 0; i < size1; i++)
    {
        output[i] = firstchar + output1[i];
    }
    for (int i = 0; i < size2; i++)
    {
        output[i + size1] = secondchar + output2[i];
    }
    return size1 + size2;
}

int main()
{
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for (int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
