#include <iostream>
# include "BinaryTreeNode.h"
using namespace std;

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

BinaryTreeNode<int>* inputBTree(){
    int rootData;
    cout << "Enter Data: ";
    cin >> rootData;
    if (rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftNode = inputBTree();
    BinaryTreeNode<int>* rightNode = inputBTree();
    root -> left = leftNode;
    root -> right = rightNode;
    return root;
}

int main(){
    BinaryTreeNode<int>* root = inputBTree();
    printBTree(root);
    delete root;

    return 0;
}