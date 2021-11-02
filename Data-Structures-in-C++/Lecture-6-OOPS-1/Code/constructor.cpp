#include <iostream>
using namespace std;

class student{
    private:
    int age;
    int rollNo;

    public:

    // Default constructor
    student(){
        cout << "Default constructor" << endl;
        age = 0;
        rollNo = 0;
    }

    // Parameterised constructor
    student(int age, int rollNo){
        this -> age = age;
        this -> rollNo = rollNo;
    }

    void display(){
        cout << "Age: " << age << " " << "Roll no.: " << rollNo <<  endl;
    }
};

int main(){
    student s1;
    s1.display();

    student s2(20, 18);
    s2.display();

    student *s3 = new student (18, 23);
    s3 -> display();

    return 0;

}