#include <iostream>
#include "queue-using-array.h"
#include "queueLLT.h"
using namespace std;

int main(){
    Queue<char> q;
    q.enqueue(97);
    q.enqueue(98);
    q.enqueue(99);
    q.enqueue(100);
    q.enqueue(101);
    q.enqueue(102);

    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;

    return 0;
}
