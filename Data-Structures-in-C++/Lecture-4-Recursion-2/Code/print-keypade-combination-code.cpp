/*
Print Keypad Combinations Code

Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.

Input Format :
Integer n

Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string helper(int n)
{
    string code[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return code[n];
}

void printKeypad(int num, string output = "")
{

    if (num == 0)
    {
        cout << output << endl;
        return;
    }
    int no = num % 10;
    int size;
    string code = helper(no - 2);
    if (no == 2 || no == 3 || no == 4 || no == 5 || no == 6 || no == 8)
    {
        size = 3;
    }
    else
    {
        size = 4;
    }
    for (int i = 0; i < size; i++)
    {
        printKeypad(num / 10, code[i] + output);
    }
}

// Better Code
void helper(int num, string output)
{
    if (num == 0)
    {
        cout << output << endl;
        return;
    }
    vector<string> kypd{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int key = num % 10;
    for (int i = 0; i < kypd[key - 2].size(); i++)
    {
        helper(num / 10, kypd[key - 2][i] + output);
    }
}

void printKeypad(int num)
{
    helper(num, "");
}

int main()
{
    int num;
    cin >> num;

    // printKeypad(num);

    return 0;
}
