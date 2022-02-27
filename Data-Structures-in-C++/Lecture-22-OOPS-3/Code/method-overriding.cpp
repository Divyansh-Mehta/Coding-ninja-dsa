#include <iostream>
using namespace std;

class A{
    public:
        void print(){
            cout << "A" << endl;
        }
};

class B : public A{
    public:
        void print(){
            cout << "B" << endl;
        }
};

int main(){
    // B b;
    // A a;
    // a.print();
    // b.print();
    // b.A::print();

    A *a;
    B b;
    a = &b;
    b.print();
    a -> print();

    return 0;
}