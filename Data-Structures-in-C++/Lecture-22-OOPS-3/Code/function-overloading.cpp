#include <iostream>
using namespace std;

int test(int a, int b){
    cout << a << " " << b << endl;
    return 0;
}

int test(int a){
    cout << a << endl;
    return 0;
}

int test(){
    cout << " " << endl;
    return 0;
}

int test(float a, int b){
    return 0;
}

int test(int a, float b){
    return 0;
}

int main(){
    test(1, 2);
    test(3);
    test();

    return 0;
}