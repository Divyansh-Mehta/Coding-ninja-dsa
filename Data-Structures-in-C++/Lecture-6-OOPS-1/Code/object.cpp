#include<iostream>
#include "student-class.cpp"
using namespace std;

int main(){
    student s1;
    student *s2 = new student;

    s1.age = 21;
    s1.rollNO = 101;

    (*s2).age = 22;
    s2 -> rollNO = 102;
    cout << s1.age << " " << s1.rollNO << endl;
    cout << s2 -> age << " " << s2 -> rollNO << endl;

    return 0;
}