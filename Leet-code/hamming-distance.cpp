//https://leetcode.com/problems/hamming-distance/submissions/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0, Xor = x^y;
        while(Xor){
            count += Xor % 2;
            Xor >>= 1;
        }
        return count;
    }
};