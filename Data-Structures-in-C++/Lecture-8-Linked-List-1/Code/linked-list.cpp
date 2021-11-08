#include <iostream>
#include "node.cpp"
using namespace  std;

/*
int main(){
    Node n1(1);
    Node *head = &n1;
    Node n2(2);
    n1.next = &n2;
    cout << head -> data;  // will print n1
    cout << "\n" << head -> next -> data;

    return 0;
}
*/

void print(Node *head){
    Node *p = head;
    while(p != NULL){
        cout << p -> data;
        p = p -> next;
    }
}
int main(){
/*
    Node n1(1);
    Node *head = &n1;
    Node n2(2), n3(3), n4(4), n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    print(head);
*/
 Node *head = NULL, *tail = NULL;
 for (int i = 0; i < 5; i++){
     if (head == NULL){
         Node *p = new Node(i + 1);
         head = p;
         tail = p;
     }
     else{
         Node *p = new Node(i + 1);
         tail -> next = p;
         tail = tail -> next;
     }
 }
    print(head);
    return 0;
    }