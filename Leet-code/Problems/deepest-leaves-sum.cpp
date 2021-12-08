//https://leetcode.com/problems/deepest-leaves-sum/
// recursive approach ..
class Solution {
public:
    pair<int, int> helper(TreeNode* root){
        if (root == NULL){
             pair<int, int> ans;
            ans.first = 0;
            ans.second = 0;
            return ans;
        }
        if (root -> left == NULL && root -> right == NULL){
            pair<int, int> ans;
            ans.first = root -> val;
            ans.second = 1;
            return ans;
        }
        pair<int, int> leftAns = helper(root -> left);
        pair<int, int> rightAns = helper(root -> right);
        pair<int, int> ans;
        ans.second = max(leftAns.second, rightAns.second) + 1;
        if (rightAns.second == leftAns.second){
            ans.first = rightAns.first + leftAns.first;
        }
        else if (rightAns.second > leftAns.second){
            ans.first = rightAns.first;
        }
        else{
            ans.first = leftAns.first;
        }
        return ans;
    }
    int deepestLeavesSum(TreeNode* root) {
        return helper(root).first;
    }
};

// using queue
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> pn;
        pn.push(root);
        pn.push(NULL);
        while(!pn.empty()){
            TreeNode* front = pn.front();
            pn.pop();
            if (front == NULL){
                if(pn.empty()){
                    break;
                }
                else{
                    res = 0;
                    pn.push(NULL);
                }
            }
            else{
                res += front -> val;
                if (front -> left != NULL){
                    pn.push(front -> left);
                }
                if (front -> right != NULL){
                    pn.push(front -> right);
                }
            }
        }
        return res;
    }
};

