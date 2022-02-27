#include <iostream>
using namespace std;

class vehicle{
    public:
    virtual void print() = 0;
};

class car : public vehicle{
    public:
        void print(){
            cout << "B" << endl;
        }
};

int main(){
    //vehicle v;
    car c;
}