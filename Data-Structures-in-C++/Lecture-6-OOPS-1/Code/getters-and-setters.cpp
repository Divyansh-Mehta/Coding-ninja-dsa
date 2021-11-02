#include <iostream>
using namespace std;

class student{
    private:
    int rollNo;
    int age;

    public:
    void setAge(int x){
        age = x;
    }
    void setRollNo(int x){
        rollNo = x;
    }
    int getAge(){
        return age;
    }

    int getRollNo(){
        return rollNo;
    }

    void display(){
        cout << "Age :" << age << " " << "Roll no. :" << rollNo; 
    }
};

int main(){
    student s;
    s.setAge(20);
    s.setRollNo(18);
    cout << "Getters:\n";
    cout << "Age :" << s.getAge() << " " << "Roll no. :" << s.getRollNo();
    cout << "\nDisplay: ";
    cout << endl;
    s.display();

    return 0; 
}