#include <iostream>
#include "template-pair-class.cpp"
using namespace std;

int main(){
    Pair <Pair <int, double>, char> p;
    Pair <int, double> temp;
    temp.setX(10);
    temp.setY(15.5);
    p.setX(temp);
    p.setY('a'); 
    cout << p.getX().getX() << endl;
    cout << p.getX().getY() << endl;
    cout << p.getY() << endl;

    return 0;
}