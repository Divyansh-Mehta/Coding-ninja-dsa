//https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = nums[0], n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        for (int i = 1; i < n; i++){
            ans[i] = product;
            product *= nums[i];
        }
        product = nums[n - 1];
        for (int i = n - 2; i >= 0; i--){
            ans[i] *= product;
            product *= nums[i];
        }
        return ans;
    }
};