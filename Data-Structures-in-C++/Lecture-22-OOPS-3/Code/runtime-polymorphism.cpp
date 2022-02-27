#include <iostream>
using namespace std;

class A{
    public:
        virtual void print(){
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
    A *a = new B;
    B b;

    a -> print();
    b.print();

    return 0;
}