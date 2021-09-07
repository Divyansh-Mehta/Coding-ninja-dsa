#include <iostream>
using namespace std;

int main(){
    //Constant reference to a non-constant int
    int j1 = 10;
    const int &i1 = j1;

    //Constant reference to a constant int
    const int j2 = 10;
    const int &i2 = j2;

    //reference to a constant int
    const int j3 = 10;
    //int &i3 = j3;  error

    return 0;
}