#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* inputBTLevelWise(){
    int rootData;
    cout << "Enter Root: ";
    cin >> rootData;
    if (rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int leftChild;
        cout << "Enter left child of " << front -> data << ": ";
        cin >> leftChild;
        if (leftChild != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChild);
            front -> left = child;
            pendingNodes.push(child);
        }
        int rightChild;
        cout << "Enter right child of " << front -> data << ": ";
        cin >> rightChild;
        if (rightChild != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChild);
            front -> right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printBTree(BinaryTreeNode<int>* root){
    if (root == NULL){
        return;
    }
    cout << root -> data << ": ";
    if (root -> left != NULL){
        cout << "L" << root -> left -> data;
    }
    if (root -> right != NULL){
        cout << "R" << root -> right -> data;
    }
    cout << endl;
    printBTree(root -> left);
    printBTree(root -> right);
}

int main(){
    BinaryTreeNode<int>* root = inputBTLevelWise();
    printBTree(root);
    delete root;

    return 0;
}