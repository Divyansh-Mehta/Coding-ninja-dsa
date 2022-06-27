/*
Trim Spaces

Given an input string S that contains multiple words, you need to remove all the spaces present in the input string.
There can be multiple spaces present after any word.

Input Format :
 String S

Output Format :
Updated string

Constraints :
1 <= Length of string S <= 10^6

Sample Input :
abc def g hi
Sample Output :
abcdefghi
*/

#include <iostream>
#include <cstring>
using namespace std;


//Time: - O(n) Space: - O(1)
void trimSpaces(char input[])
{

    int k = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != ' ')
        {
            input[k++] = input[i];
        }
    }
    input[k] = '\0';
}


int main()
{
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}
