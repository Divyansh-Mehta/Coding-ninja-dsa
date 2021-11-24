#include<iostream>
#include <queue>
#include "treenode.h"
using namespace std;

void printTree(TreeNode<int>* root){
    if (root == NULL){
        return;                 //It is an edge case and not base case
    }

    cout << root -> data << ": ";

    for (int i = 0; i < root -> children.size(); i++){
        cout << root -> children[i] -> data << " ";
    }
    cout << endl;

    for (int i = 0; i < root -> children.size(); i++){
        printTree(root -> children[i]);
    }
}

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter Root Data: ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pending;
    pending.push(root);

    while (!pending.empty()){
        TreeNode<int> *front = pending.front();
        pending.pop();
        int numChild;
        cout << "Enter no of children of " << front -> data << ": ";
        cin >> numChild;
        for (int i = 0; i < numChild; i++){
            int childData;
            cout << "Enter " << i + 1 << "th child of " << front ->data << ": ";
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front -> children.push_back(child);
            pending.push(child);
        }
    }
    return root;
}

int countNode(TreeNode<int>* root){
    int ans = 1;
    for (int i = 0; i < root -> children.size(); i++){
        ans += countNode(root -> children[i]);
    }
    return ans;
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    int n = countNode(root);
    cout << "No of nodes: " << n;

    return 0;
}