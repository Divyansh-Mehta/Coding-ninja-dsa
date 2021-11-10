#include <iostream>
#include "node.cpp"
using namespace std;

Node * takeInput1(){
    int data;
    cin >> data;
    Node *head = NULL;
    while (data != -1){
        Node *newNode = new Node(data);
        if (head == NULL){
            head = newNode;
        }
        else{
            Node *temp = head;
            while (temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
        cin >> data;
    }
    return head;
}

Node * takeInput2(){
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1){
        Node *newNode = new Node(data);
        if (head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = tail -> next;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head){
    Node *p = head;
    while(p != NULL){
        cout << p -> data;
        p = p -> next;
    }
}

int main(){
    Node *head = takeInput2();
    print(head);

    return 0;
}