#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int subs(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }

    string smallString = input.substr(1);
    int smallOutput = subs(smallString, output);

    for (int i = 0; i < smallOutput; i++)
    {
        output[i + smallOutput] = input[0] + output[i];
    }
    return 2 * smallOutput;
}

int main()
{
    string s;
    cin >> s;
    int n = pow(2, s.size());
    string *output = new string[n];
    int size = subs(s, output);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}