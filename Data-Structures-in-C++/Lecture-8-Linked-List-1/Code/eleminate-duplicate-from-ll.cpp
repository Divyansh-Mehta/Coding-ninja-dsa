/*
Eliminate duplicates from LL
You have been given a singly linked list of integers where the elements are sorted in ascending order. Write a function that removes the consecutive duplicate values such that the given list only contains unique elements and returns the head to the updated list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements(in ascending order) of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

Output format :
For each test case/query, print the resulting singly linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5

Time Limit: 1sec
Where 'M' is the size of the singly linked list.

Sample Input 1 :
1
1 2 3 3 3 3 4 4 4 5 5 7 -1
Sample Output 1 :
1 2 3 4 5 7 

Sample Input 2 :
2
10 20 30 40 50 -1
10 10 10 10 -1
Sample Output 2 :
10 20 30 40 50
10
*/

#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;

/* workes for non sorted array also
Node *removeDuplicates(Node *head)
{
    //Write your code her
    Node *ptr1 = head, *ptr2 = NULL;
    while (ptr1 != NULL && ptr1 -> next != NULL){
        ptr2 = ptr1;
        while (ptr2 -> next != NULL){
            if (ptr2 -> next -> data == ptr1 -> data){
                Node * p = ptr2 -> next;
                ptr2 -> next = ptr2 -> next -> next;
                delete p;
            }
            else{
                ptr2 = ptr2 -> next;
            }
        }
        ptr1 = ptr1 -> next;
    }
    return head;
}
*/
Node *removeDuplicates(Node *head)
{
    Node *ptr1 = head, *ptr2 = NULL;
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL && ptr2->data == ptr1->data)
        {
            Node *p = ptr2;
            ptr2 = ptr2->next;
            delete p;
        }
        ptr1->next = ptr2;
        ptr1 = ptr2;
    }
    return head;
}

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        head = removeDuplicates(head);
        print(head);
    }
    return 0;
}