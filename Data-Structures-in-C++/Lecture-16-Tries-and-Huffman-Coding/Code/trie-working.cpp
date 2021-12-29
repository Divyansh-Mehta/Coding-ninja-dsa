#include<iostream>
#include "Trie.h"
using namespace std;

int main(){
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");

    cout << t.search("and") << endl;
    t.removeWord("and");
    cout << t.search("and") << endl;

    return 0;
}
