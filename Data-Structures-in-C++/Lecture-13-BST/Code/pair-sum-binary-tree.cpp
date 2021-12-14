/*
Pair Sum Binary Tree
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.

Note:
1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains an integer, that denotes the value of S.

Output Format :
Print each pair in a new line, as described in the task. 

Constraints:
Time Limit: 1 second

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15
Sample Output 1:
5 10
6 9
*/

#include <iostream>
#include <queue>
#include<vector>
#include<algorithm>
#include <climits>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

/*
O(n^2) will lead to TLE
bool find(BinaryTreeNode<int> *root, int x){
	if (root == NULL){
        return false;
    }    
    
    if (root -> data == x){
        return true;
        root -> data = INT_MIN;
    }
    return find(root -> left, x) || find(root -> right, x);
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    static BinaryTreeNode<int> *originalRoot = root;
    if (root == NULL){
        return;
    }
    if (root -> data != INT_MIN){
        int temp = root -> data;
        root -> data = INT_MIN;
        bool isFound = find(originalRoot, sum - temp);
        if (isFound){
            if (temp < sum - temp){
                cout << temp << " " << sum - temp << "\n";
            }
            else{
                cout << sum - temp << " " << temp << "\n";
            }
        }
    }
    pairSum(root -> left, sum);
    pairSum(root -> right, sum);
}
*/

//O(n)
void intoArray(BinaryTreeNode<int>* root, vector<int> &arr){
    if (root == NULL){
        return;
    }
    arr.push_back(root -> data);
    intoArray(root -> left, arr);
    intoArray(root -> right, arr);
}

//O(nlogn)
void pairSum(BinaryTreeNode<int> *root, int sum) {
    vector<int> arr;
    intoArray(root, arr);
    sort(arr.begin(), arr.end());
    int i = 0, j = arr.size() - 1;
    while(i < j){
        if (arr[i] + arr[j] < sum){
            i++;
        }
        else if (arr[i] + arr[j] > sum){
            j--;
        }
        else{
            cout << arr[i] << " " << arr[j] << "\n";
            i++;
            j--;
        }
    }
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}