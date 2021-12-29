#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> ourMap;
    ourMap["abc"] = 1;
    ourMap["abc1"] = 2;
    ourMap["abc2"] = 3;
    ourMap["abc3"] = 4;
    ourMap["abc4"] = 5;
    ourMap["abc5"] = 6;

    unordered_map<string, int>::iterator it;
    for (it = ourMap.begin(); it != ourMap.end(); it++){
        cout << it -> first << "->" << it -> second << endl;
    }

    return 0;
}