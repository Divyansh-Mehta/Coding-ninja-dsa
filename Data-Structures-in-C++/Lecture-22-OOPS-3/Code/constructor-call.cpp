#include <iostream>
using namespace std;

class A{
    public:
    A(){
        cout << "Constructor of A" << endl;
    }
    ~A(){
        cout << "Destructor of A" << endl;
    }
};

class B : A{
    public:
    B(){
        cout << "Constructor of B" << endl;
    }

    ~B(){
        cout << "Destructor of B" << endl;
    }
};

class C : B{
    public:
    C(){
        cout << "Constructor of C" << endl;
    }

    ~C(){
        cout << "Destructor of C" << endl;
    }
};

int main(){
    cout << "Making Object of A" << endl;
    A a;
    cout << endl;

    cout << "Making Object of B" << endl;
    B b;
    cout << endl;

    cout << "Making Object of C" << endl;
    C c;
    cout << endl;

    return 0;
}