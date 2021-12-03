#include<iostream>
#include "BinaryTreeNode.h"
using namespace std;

int main(){
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(10);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(20);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(30);
    root -> left = node1;
    root -> right = node2;
}