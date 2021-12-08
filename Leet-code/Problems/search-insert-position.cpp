//https://leetcode.com/problems/search-insert-position/submissions/
#include <vector>
using namespace std;

//My solution
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size() -  1;
        while (l <= r){
            int mid = (l + r) / 2;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] > target){
                if(mid == 0){
                    return 0;
                }
                else if (nums[mid - 1] < target){
                    return mid;
                }
                r = mid - 1;
            }
            else {
                if (mid == nums.size() - 1){
                    break;
                }
                else if (nums[mid + 1] > target){
                    return mid + 1;
                }
                l = mid + 1;
            }  
            }
            return nums.size();
        }
};
//Discussion
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size() -  1;
        while (l <= r){
            int mid = (l + r) / 2;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] > target){
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }  
            
        }    
            return l;
    }
    
};