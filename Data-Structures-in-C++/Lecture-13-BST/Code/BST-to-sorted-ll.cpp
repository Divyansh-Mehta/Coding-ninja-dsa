/*
Code: BST to Sorted LL
Given a BST, convert it into a sorted linked list. You have to return the head of LL.

Input format:
The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   

Output Format:
The first and only line of output prints the elements of sorted linked list.

Constraints:
Time Limit: 1 second

Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1:
2 5 6 7 8 10
*/

#include <iostream>
#include <queue>
#include <utility>

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

/*O(n^2)
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    if (root == NULL){
        return NULL;
    }
    Node<int> *leftAns = constructLinkedList(root -> left);
    Node<int> *rightAns = constructLinkedList(root -> right);
    Node<int> *node = new Node<int>(root -> data);
    
    node -> next = rightAns;
    if (leftAns == NULL){
        return node;
    }
    Node<int> *temp = leftAns;
    while (temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = node;
    return leftAns;
}

*/

// Better O(n) approach
pair<Node<int> *, Node<int> *> helper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<Node<int> *, Node<int> *> ans;
        ans.first = NULL;
        ans.second = NULL;
        return ans;
    }
    pair<Node<int> *, Node<int> *> leftAns = helper(root->left);
    pair<Node<int> *, Node<int> *> rightAns = helper(root->right);
    pair<Node<int> *, Node<int> *> ans;
    Node<int> *node = new Node<int>(root->data);
    node->next = rightAns.first;
    if (leftAns.second != NULL)
    {
        leftAns.second->next = node;
    }

    if (leftAns.first != NULL)
    {
        ans.first = leftAns.first;
    }
    else
    {
        ans.first = node;
    }

    if (rightAns.second != NULL)
    {
        ans.second = rightAns.second;
    }
    else
    {
        ans.second = node;
    }

    return ans;
}

Node<int> *constructLinkedList(BinaryTreeNode<int> *root)
{
    return helper(root).first;
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;

    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    Node<int> *head = constructLinkedList(root);

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}