#include <iostream>
#include "stack-using-array.cpp"
#include "stackArrayT.cpp"
#include "StackLLT.cpp"
using namespace std;

int main(){
    /*
    StackUsingArrayDynamic s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.isEmpty() << endl;
    cout << s.top() <<  endl;
    StackArrayT<char> s2;
    s2.push('a');
    s2.push('b');
    s2.push('c');
    s2.push(100);
    s2.push(101);
    s2.push(102);
    cout << s2.pop() << endl;
    cout << s2.pop() << endl;
    cout << s2.isEmpty() << endl;
    cout << s2.top();
    */
   StackLLT<char> s;
   s.push('a');
   s.push('b');
   cout << s.pop() <<  endl;
   cout << s.top() << endl;
   cout << s.isEmpty() << endl;
   cout << s.pop() << endl;
   cout << s.isEmpty() << endl;

    return 0;
}