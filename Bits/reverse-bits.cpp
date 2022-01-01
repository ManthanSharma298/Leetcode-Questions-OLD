
// prob link: https://leetcode.com/problems/reverse-bits/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0, bit = 31;
        while(n){
            res += (n & 1) << bit;
            bit--;
            n >>= 1;
        }
        return res;
    }
};

