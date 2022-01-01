/*
Crossword Problem
Coding Ninjas has provided you a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV

Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA

Note: We have provided such test cases that there is only one solution for the given input.

Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 

Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  

Constraints
The number of words in the word list lie in the range of: [1,6]
The length of words in the word list lie in the range: [1, 10]
Time Limit: 1 second

Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
*/

#include <bits/stdc++.h>
using namespace std;

bool isValidVertical(char crossWord[][10], int row, int col, string word)
{
    int j = row;
    for (int i = 0; i < word.size(); i++)
    {
        if (j > 9)
        {
            return false;
        }
        if (crossWord[j][col] == '-' || crossWord[j][col] == word[i])
        {
            j++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool isValidHorizontal(char crossWord[][10], int row, int col, string word)
{
    int j = col;
    for (int i = 0; i < word.size(); i++)
    {
        if (j > 9)
        {
            return false;
        }
        if (crossWord[row][j] == '-' || crossWord[row][j] == word[i])
        {
            j++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void setVertical(char crossWord[][10], int row, int col, string word, vector<bool> &marking)
{
    int j = row;
    for (int i = 0; i < word.size(); i++)
    {
        if (crossWord[j][col] == '-')
        {
            crossWord[j][col] = word[i];
            marking.push_back(true);
        }
        else
        {
            marking.push_back(false);
        }
        j++;
    }
}

void setHorizontal(char crossWord[][10], int row, int col, string word, vector<bool> &marking)
{
    int j = col;
    for (int i = 0; i < word.size(); i++)
    {
        if (crossWord[row][j] == '-')
        {
            crossWord[row][j] = word[i];
            marking.push_back(true);
        }
        else
        {
            marking.push_back(false);
        }
        j++;
    }
}

void reSetVertical(char crossWord[][10], int row, int col, vector<bool> &marking)
{
    int j = row;
    for (int i = 0; i < marking.size(); i++)
    {
        if (marking[i])
        {
            crossWord[j][col] = '-';
        }
        j++;
    }
}

void reSetHorizontal(char crossWord[][10], int row, int col, vector<bool> &marking)
{
    int j = col;
    for (int i = 0; i < marking.size(); i++)
    {
        if (marking[i])
        {
            crossWord[row][j] = '-';
        }
        j++;
    }
}

bool crossWordSolve(char crossWord[][10], vector<string> &words, int index)
{
    if (index == words.size())
    {
        //CrossWord completed
        //Print and return
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << crossWord[i][j];
            }
            cout << endl;
        }
        return true;
    }

    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < 10; c++)
        {
            if (crossWord[r][c] == '-' || crossWord[r][c] == words[index][0])
            {
                if (isValidVertical(crossWord, r, c, words[index]))
                {
                    vector<bool> marking;
                    setVertical(crossWord, r, c, words[index], marking);
                    if (crossWordSolve(crossWord, words, index + 1))
                    {
                        return true;
                    }
                    reSetVertical(crossWord, r, c, marking);
                }

                if (isValidHorizontal(crossWord, r, c, words[index]))
                {
                    vector<bool> marking;
                    setHorizontal(crossWord, r, c, words[index], marking);
                    if (crossWordSolve(crossWord, words, index + 1))
                    {
                        return true;
                    }
                    reSetHorizontal(crossWord, r, c, marking);
                }
            }
        }
    }
    return false;
}

int main()
{
    char crossWord[10][10];

    for (int i = 0; i < 10; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 10; j++)
        {
            crossWord[i][j] = s[j];
        }
    }

    string s;
    cin >> s;
    vector<string> words;

    for (int i = 0; i < s.size(); i++)
    {
        int j = i;
        while (s[j] != ';' && j < s.size())
        {
            j++;
        }
        words.push_back(s.substr(i, j - i));
        i = j;
    }

    crossWordSolve(crossWord, words, 0);

    return 0;
}