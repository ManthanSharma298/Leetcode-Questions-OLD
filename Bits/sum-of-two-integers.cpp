
// prob link: https://leetcode.com/problems/sum-of-two-integers/


class Solution {
public:
    int getSum(int a, int b) {
        int temp;
        while(b != 0){
            temp = a;
            a = a ^ b;
            b = temp & b;
            b = (unsigned int)b<<1;
        }
        return a;
    }
};

