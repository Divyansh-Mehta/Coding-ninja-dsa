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
using namespace std;

#include <string>
using namespace std;

int keypad(int num, string output[])
{
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }

    int smalloutput = keypad(num / 10, output);

    if (num % 10 == 2)
    {
        for (int i = 0; i < smalloutput; i++)
        {
            output[i + smalloutput] = output[i];
            output[i + smalloutput] += "b";
        }
        for (int i = 0; i < smalloutput; i++)
        {
            output[i + (2 * smalloutput)] = output[i];
            output[i + (2 * smalloutput)] += "c";
        }
        for (int i = 0; i < smalloutput; i++)
        {
            output[i] += "a";
        }
        return smalloutput * 3;
    }
    else if (num % 10 == 3)
    {
        for (int i = 0; i < smalloutput; i++)
        {
            output[i + smalloutput] = output[i];
            output[i + smalloutput] += "e";
        }
        for (int i = 0; i < smalloutput; i++)
        {
            output[i + (2 * smalloutput)] = output[i];
            output[i + (2 * smalloutput)] += "f";
        }
        for (int i = 0; i < smalloutput; i++)
        {
            output[i] += "d";
        }
        return smalloutput * 3;
    }
    else if (num % 10 == 4)
    {
        for (int i = 0; i < smalloutput; i++)
        {
            output[i + smalloutput] = output[i];
            output[i + smalloutput] += "h";
        }
        for (int i = 0; i < smalloutput; i++)
        {
            output[i + (2 * smalloutput)] = output[i];
            output[i + (2 * smalloutput)] += "i";
        }
        for (int i = 0; i < smalloutput; i++)
        {
            output[i] += "g";
        }
        return smalloutput * 3;
    }

    else if (num % 10 == 5)
    {
        for (int i = 0; i < smalloutput; i++)
        {
            output[i + smalloutput] = output[i];
            output[i + smalloutput] += "k";
        }
        for (int i = 0; i < smalloutput; i++)
        {
            output[i + (2 * smalloutput)] = output[i];
            output[i + (2 * smalloutput)] += "l";
        }
        for (int i = 0; i < smalloutput; i++)
        {
            output[i] += "j";
        }
        return smalloutput * 3;
    }

    else if (num % 10 == 6)
    {
        for (int i = 0; i < smalloutput; i++)
        {
            output[i + smalloutput] = output[i];
            output[i + smalloutput] += "n";
        }
        for (int i = 0; i < smalloutput; i++)
        {
            output[i + (2 * smalloutput)] = output[i];
            output[i + (2 * smalloutput)] += "o";
        }
        for (int i = 0; i < smalloutput; i++)
        {
            output[i] += "m";
        }
        return smalloutput * 3;
    }

    else if (num % 10 == 7)
    {
        for (int i = 0; i < smalloutput; i++)
        {
            output[i + smalloutput] = output[i];
            output[i + smalloutput] += "q";
        }
        for (int i = 0; i < smalloutput; i++)
        {
            output[i + (2 * smalloutput)] = output[i];
            output[i + (2 * smalloutput)] += "r";
        }

        for (int i = 0; i < smalloutput; i++)
        {
            output[i + (3 * smalloutput)] = output[i];
            output[i + (3 * smalloutput)] += "s";
        }
        for (int i = 0; i < smalloutput; i++)
        {
            output[i] += "p";
        }
        return smalloutput * 4;
    }

    else if (num % 10 == 8)
    {
        for (int i = 0; i < smalloutput; i++)
        {
            output[i + smalloutput] = output[i];
            output[i + smalloutput] += "u";
        }
        for (int i = 0; i < smalloutput; i++)
        {
            output[i + (2 * smalloutput)] = output[i];
            output[i + (2 * smalloutput)] += "v";
        }
        for (int i = 0; i < smalloutput; i++)
        {
            output[i] += "t";
        }
        return smalloutput * 3;
    }

    else if (num % 10 == 9)
    {
        for (int i = 0; i < smalloutput; i++)
        {
            output[i + smalloutput] = output[i];
            output[i + smalloutput] += "x";
        }
        for (int i = 0; i < smalloutput; i++)
        {
            output[i + (2 * smalloutput)] = output[i];
            output[i + (2 * smalloutput)] += "y";
        }

        for (int i = 0; i < smalloutput; i++)
        {
            output[i + (3 * smalloutput)] = output[i];
            output[i + (3 * smalloutput)] += "z";
        }
        for (int i = 0; i < smalloutput; i++)
        {
            output[i] += "w";
        }
        return smalloutput * 4;
    }
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
