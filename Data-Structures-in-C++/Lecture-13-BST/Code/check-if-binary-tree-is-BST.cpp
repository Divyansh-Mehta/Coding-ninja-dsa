/*
Check if a Binary Tree is BST
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format :
The first and only line of output contains either true or false.

Constraints :
Time Limit: 1 second

Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1
Sample Output 1 :
true

Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
Sample Output 2 :
false
*/

#include <iostream>
#include <queue>
#include <climits>

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

/*
Approach-1... O(N * H)
int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    return (root->data > leftMax) && (root->data <= rightMin) &&
           isBST(root->left) && isBST(root->right);
}
*/

/* Appraoch-2... O(N)
class Triplet{
    public:
    bool isBST;
    int minimum;
    int maximum;
};

Triplet helper(BinaryTreeNode<int> *root){
    if (root == NULL){
        Triplet ans;
        ans.isBST = true;
        ans.minimum = INT_MAX;
        ans.maximum = INT_MIN;
        return ans;
    }
    
    Triplet rightAns = helper(root -> right);
    Triplet leftAns = helper(root -> left);
    Triplet ans;
    ans.isBST = rightAns.isBST && leftAns.isBST && 
        root -> data > leftAns.maximum && root -> data <= rightAns.minimum;
    
    ans.minimum = min(root -> data, min(leftAns.minimum, rightAns.minimum));
    ans.maximum = max(root -> data, max(leftAns.maximum, rightAns.maximum));
    
    return ans;
}

bool isBST(BinaryTreeNode<int> *root) {
    return helper(root).isBST;
}
*/

//Approach-3.. top to bottom
bool isBST(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->data < min || root->data > max)
    {
        return false;
    }

    return isBST(root->left, min, root->data - 1) &&
           isBST(root->right, root->data, max);
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
    cout << (isBST(root) ? "true" : "false");
}