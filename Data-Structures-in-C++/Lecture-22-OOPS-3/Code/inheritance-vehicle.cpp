#include <iostream>
#include <string>
using namespace std;

class Vehicle{
    private:
        int maxSpeed;

    protected:
        int numTyres;
    
    public:
        string color;
};

// Syntax: class child : access-specifier parent{};
class Car : public Vehicle{
    public:
        int numGears;

        void print(){
            cout << "NumTypes: " << numTyres << endl;
            cout << "Color: " << color << endl;
            cout << "NumGears: " << numGears << endl;
            //cout << "MaxSpeed: " << maxSpeed << endl; "cannot access this property as private properties are not inherited"
        }
};

int main(){
    Vehicle v;
    v.color = "Blue";
    /* cannot access private and protected(only in child classes) members outside class
    v.maxSpeed = 200;
    v.numTyres = 4;
    */
    Car c;
    c.color = "black";

    return 0;
}