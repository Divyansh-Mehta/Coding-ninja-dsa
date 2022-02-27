#include <iostream>
using namespace std;

class Vehicle{
    private:
        int maxSpeed;

    protected:
        int numTyres;

    public:
        string color;

    Vehicle(){
        cout << "Vehicle's default constructor" << endl;
    }

    Vehicle(int z){
        cout << "Vehicle's Parametrized constructor" << endl;
    maxSpeed = z;
    }

    void print(){
        cout << "Vehicle" << endl;
    }

    ~Vehicle(){
        cout << "Vehicle's destructor" << endl;
    }
};

class Car : public Vehicle{
    public:
        int numGears;

        Car(){
            cout << "Car's default constructor" << endl;
        }

        ~Car(){
            cout << "Car's Destructor" << endl;
        }

        void print(){
            cout << "NumTyres: " << numTyres << endl;
            cout << "Color: " << color << endl;
            cout << "Num Gears: " << numGears << endl;
        }
};

class Truck : public Vehicle{
    public:
        Truck(){
            cout << "Truck's constructor" << endl;
        }

        ~Truck(){
            cout << "Truck's destructor" << endl;
        }
};

class Bus : public Car, public Truck{
    public:
        Bus(){
            cout << "Bus's Constructor" << endl;
        }

        ~Bus(){
            cout << "Bus's Destructor" << endl;
        }
};

int main(){
    Bus b; 
    b.Car::print();
}