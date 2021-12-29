#include <iostream>
#include <string>
#include "ourmap.h"
using namespace std;

int main(){
    ourmap<int> map;
    for (int i = 0; i < 10; i++){
        char c = '0' + i;
        string key = "abc";
        key += c;
        int val = i + 1;
        map.insert(key, val);
        cout << map.loadFactor() << endl;
    }

    for (int i = 0; i < 10; i++){
        char c = '0' + i;
        string key = "abc";
        key += c;
        cout << key << ":" << map.getValue(key) << endl;
        }
    cout << map.size() << endl;
    
    map.remove("abc2");
    map.remove("abc7");
    
    for (int i = 0; i < 10; i++){
        char c = '0' + i;
        string key = "abc";
        key += c;
        cout << key << ":" << map.getValue(key) << endl;
        }
    cout << map.size() << endl;
}