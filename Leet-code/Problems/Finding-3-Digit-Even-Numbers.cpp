//https://leetcode.com/problems/finding-3-digit-even-numbers/

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        int digCount[10] = {0};
        for(int i = 0; i < digits.size(); i++){
            digCount[digits[i]]++;
        }
        for (int i = 1; i <= 9; i++){
            for (int j = 0; j <= 9 && digCount[i]; j++){
                for (int k = 0; k<= 8 && (digCount[j] > (i == j)); k += 2){
                    if (digCount[k] > (i == k) + (j == k)){
                        ans.push_back(i * 100 + j * 10 + k);
                    }
                }
            }
        }
        return ans;
    }
};