#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    
    Node(int data){
        this -> data = data;
        next = NULL;
    }

    /*
    ~Node(){
        if (next != NULL){
        delete next;
        }
    }
    */
};

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
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
