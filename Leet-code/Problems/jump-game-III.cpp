//https://leetcode.com/problems/jump-game-iii/
class Solution
{
private:
    bool helper(vector<int> &arr, int start, int count)
    {
        if (start >= arr.size() || start < 0)
        {
            return false;
        }
        if (count > arr.size())
        {
            return false;
        }
        if (arr[start] == 0)
        {
            return true;
        }
        return helper(arr, start + arr[start], count + 1) || helper(arr, start - arr[start], count + 1);
    }

public:
    bool canReach(vector<int> &arr, int start)
    {
        return helper(arr, start, 0);
    }
};