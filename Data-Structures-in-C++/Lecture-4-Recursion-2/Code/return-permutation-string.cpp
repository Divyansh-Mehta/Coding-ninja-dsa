/*
Return Permutations - String

Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.

Input Format :
String S

Output Format :
All permutations (in different lines)

Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba
*/

#include <iostream>
#include <string>
using namespace std;

int returnPermutations(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }
    int k;
    for (int i = 0; input[i] != '\0'; i++)
    {
        char c = input[i];
        string output1[1000];
        string s = input.substr(0, i) + input.substr(i + 1);
        k = returnPermutations(s, output1);
        for (int j = 0; j < k; j++)
        {
            output[j + (k * i)] = c + output1[j];
        }
    }
    int len = input.length();
    return len * k;
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
