#include <iostream>
#include "fraction-class.cpp"
using namespace std;

int main(){
    fraction f1(10, 2), f2(15, 4);

    f1.add(f2);
    f1.print();
    f2.print();
    f1.multiply(f2);
    f1.print();
    f2.print();
    return 0;
}