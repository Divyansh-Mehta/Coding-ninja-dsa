#include <iostream>
#include "node.cpp"
using namespace std;

Node * insertNode(Node *head, int i, int data){
    Node * newNode = new Node(data), *temp = head;
    
    if (i == 0){
        newNode -> next = head;
        head = newNode;
        return head;
    }
    int count = 0;
    while (temp != NULL && count < i - 1){
        temp = temp -> next;
        count++;
    }

    if (temp != NULL){
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
    return head;
}

int main(){
    Node *head = takeinput();
    cout << "Before inserting:\n";
    print(head);
    head = insertNode(head, 2, 100);
    cout << "\nAfter inserting:\n";
    print(head);

    return 0;
}