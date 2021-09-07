/*
Minimum Length Word

Given a string S (that can contain multiple words), you need to find the word which has minimum length.
Note : If multiple words are of same length, then answer will be first minimum length word in the string.
Words are seperated by single space only.

Input Format :
String S

Output Format :
Minimum length word

Constraints :
1 <= Length of String S <= 10^5

Sample Input 1 :
this is test string
Sample Output 1 :
is

Sample Input 2 :
abc de ghihjk a uvw h j
Sample Output 2 :
a
*/

#include <iostream>
using namespace std;

void minLengthWord(char input[], char output[])
{

    int min = 10000000, j = 0, count = 0, i;
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
        {
            if (count < min)
            {
                min = count;
                j = i - min;
            }
            count = 0;
        }
        else
            count++;
    }
    if (count < min)
    {
        min = count;
        j = i - min;
    }
    int k = 0;
    while (k < min)
    {
        output[k] = input[j];
        k++;
        j++;
    }
    output[k] = '\0';
}

int main()
{
    char ch[10000], output[10000];
    cin.getline(ch, 10000);
    minLengthWord(ch, output);
    cout << output << endl;
}
