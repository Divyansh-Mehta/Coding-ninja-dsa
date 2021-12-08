//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
#include<iostream>
#include<vector>
using namespace std;
//O(n) space O(n) time 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<int> count(n + 1,0);
        for (int i = 0; i < n; i++){
           count[nums[i]]++;
        }
        for (int i = 1; i <= n; i++){
            if (count[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// O(n) time (2 iteration) O(1) space
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            int m = (nums[i] < 0) ? (-1 * nums[i] - 1) : nums[i] - 1;
            nums[m] = nums[m] > 0 ? -1 * nums[m] : nums[m];
        }
        for (int i = 0; i < n; i++){
            if (nums[i] > 0){
                ans.push_back(i + 1);
            }
        }
            return ans;
        }
};