#include <iostream>
using namespace std;

class Bus{
    public:
        void print();
};

void test();

class Truck{
    private:
        int x;
    protected:
        int y;
    public:
        int z;
        //Truck has made print function oc Bus its friend and it is not part of this function and dont have access of this function
        //it can be placed in any access modifiers as these functions are not part of the class.
        //friend void Bus :: print();
        friend void test();
        //Now class bus can assess all properties of class truck. These classes are friend classes and its one way that is truck
        //cannot access all properties of Bus
        friend class Bus;
};

void Bus :: print(){
    Truck t;
    t.x = 10;
    t.y = 20;
    cout << t.x << " " << t.y << endl;
}

void test(){
    Truck t;
    t.x = 10;
    t.y = 20;
    cout << t.x << " " << t.y << endl;
}

int main(){
    Bus b;
    b.print();
    test();
}

