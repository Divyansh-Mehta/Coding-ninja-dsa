/*
Pair Star

Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".

Input format :
String S

Output format :
Modified string

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
hello
Sample Output 1:
hel*lo

Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a
*/

#include <iostream>
using namespace std;
int length(char input[])
{
    int len = 0;
    while (true)
    {
        if (input[len] == '\0')
            return len;

        len++;
    }
}
void pairStar(char input[])
{
    if (length(input) == 1)
        return;

    pairStar(input + 1);
    if (input[0] == input[1])
    {
        for (int i = length(input); i >= 1; i--)
        {
            input[i + 1] = input[i];
        }
        input[1] = '*';
    }
}

int main()
{
    char input[100];
    cin.getline(input, 100);
    pairStar(input);
    cout << input << endl;
}
