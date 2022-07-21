/*
Return Keypad Code

Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.

Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.

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
#include<vector>
using namespace std;

string helper(int n)
{
    string code[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    return code[n];
}
//Time: - O(n) Space: - O(n)
int keypad(int num, string output[])
{

    if (num == 0 || num == 1)
    {
        output[0] = "";
        return 1;
    }

    int smalloutput = keypad(num / 10, output);
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

    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = 0; j < smalloutput; j++)
        {
            if (i == 0)
            {
                output[j] += code[i];
            }
            else
            {
                output[j + (smalloutput * (size - i))] = output[j];
                output[j + (smalloutput * (size - i))] += code[i];
            }
        }
    }

    return smalloutput * size;
}

////Time: - O(n) Space: - O(n)
int keypad(int num, string output[]){
    if (num == 0){
        output[0] = "";
        return 1;
    }
    vector<string> kypd{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int size = keypad(num / 10, output);
    int key = num % 10;
    for (int i = 1; i < kypd[key - 2].size(); i++){
        for (int j = 0; j < size; j++){
            output[size * i + j] = output[j] + kypd[key - 2][i];
        }
    }
    for (int i = 0; i < size; i++){
        output[i] = output[i] + kypd[key - 2][0];
    }
    
    return size * kypd[key - 2].size();
}

int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
