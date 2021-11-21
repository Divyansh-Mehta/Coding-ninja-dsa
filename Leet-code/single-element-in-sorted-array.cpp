//https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/

class Solution {
public:
   /* O(n) bit manipulation 
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int single = 0;
        for (int i = 0; i < n; i++){
            single ^= nums[i];
        }
        return single;
    }
    */
    // O(logn) binary search approach
    int singleNonDuplicate(vector<int>& nums){
        int l = 0;
        int r = nums.size() - 1;
        while (l < r){
            int mid = (l + r) / 2;
            bool isEven = (r - mid) % 2 == 0;
            if (nums[mid] == nums[mid + 1]){
                if (isEven){
                    l = mid + 2;
                }
                else {
                    r = mid - 1;
                }
            }
            else if (nums[mid] == nums[mid - 1]){
                if (isEven){
                    r = mid - 2;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                return nums[mid];
            }
        }
        return nums[l];
    }
};