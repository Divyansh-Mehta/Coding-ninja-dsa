/*
Palindrome Pair
Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
The function should return either true or false. You don't have to print anything.

Input Format :
The first line of the test case contains an integer value denoting 'n'.

The following contains 'n' number of words each separated by a single space.

Output Format :
The first and only line of output contains true if the conditions described in the task are met and false otherwise.

Constraints:
0 <= n <= 10^5
Time Limit: 1 sec

Sample Input 1 :
4
abc def ghi cba
Sample Output 1 :
true
Explanation of Sample Input 1:
"abc" and "cba" forms a palindrome

Sample Input 2 :
2
abc def
Sample Output 2 :
false
Explanation of Sample Input 2:
Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.'
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
private:
    TrieNode *root;

    string reverseWord(string word)
    {
        string reverse = "";
        for (int i = word.size() - 1; i >= 0; i--)
        {
            reverse += word[i];
        }
        return reverse;
    }

    bool isPalindromePair(TrieNode *root, vector<string> words)
    {
        if (words.size() == 0)
        {
            return false;
        }

        for (int i = 0; i < words.size(); i++)
        {
            if (doesPairExistFor(root, words[i], 0))
            {
                return true;
            }
        }
        return false;
    }

    bool doesPairExistFor(TrieNode *root, string word, int startIndex)
    {
        if (word.size() == 0)
        {
            return true;
        }

        if (startIndex == word.length())
        {
            if (root->isTerminal)
            {
                return true;
            }
            string wrd = "";
            wrd += root->data;
            return checkRemainingBranchesInTries(root, wrd);
        }
        int charIndex = word[startIndex] - 'a';
        TrieNode *child = root->children[charIndex];

        if (child == NULL)
        {
            if (root->isTerminal)
            {
                return checkWordForPalindrome(word.substr(startIndex));
            }
            return false;
        }

        return doesPairExistFor(child, word, startIndex + 1);
    }

    bool checkRemainingBranchesInTries(TrieNode *root, string word)
    {
        if (root->isTerminal)
        {
            if (checkWordForPalindrome(word))
            {
                return true;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                char ch = i + 'a';
                if (checkRemainingBranchesInTries(root->children[i], word + ch))
                {
                    return true;
                }
            }
        }

        return true;
    }

    bool checkWordForPalindrome(string word)
    {
        int start = 0;
        int end = word.size() - 1;

        while (start < end)
        {
            if (word[start] != word[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        return add(child, word.substr(1));
    }

    void add(string word)
    {
        if (add(root, word))
        {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */

    bool isPalindromePair(vector<string> words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            add(reverseWord(words[i]));
        }

        return isPalindromePair(root, words);
    }
};

int main()
{
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}