#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    for (int i = 0; i < 100; i++){
        cout << "Capacity: " << v.capacity() << " ";
        cout << "Size: " << v.size() << endl;
        v.push_back(i + 1);
    }

    for (int i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }

    return 0;
}