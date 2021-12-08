//https://leetcode.com/problems/binary-tree-tilt/
class Solution {
public:
    pair<int, int> helper(TreeNode* root){
        if (root == NULL){
            pair<int, int> ans;
            ans.first = 0;
            ans.second = 0;
            return ans;
        }
            if (root -> right == NULL && root -> left == NULL){
            pair<int, int> ans;
            ans.first = 0;
            ans.second = root -> val;
            return ans;
        }
        pair<int, int> leftAns = helper(root -> left);
        pair<int, int> rightAns = helper(root -> right);
        pair<int, int> ans;
        ans.first = abs(leftAns.second - rightAns.second) + leftAns.first + rightAns.first;
        ans.second = rightAns.second + leftAns.second + root -> val;
        return ans;
    }
    int findTilt(TreeNode* root) {
        return helper(root).first;
    }
};