
// prob link: https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res(n+1, 0);
        for(int i=1; i<=n; ++i){
            int cnt = 0, num = i;
            while(num){
                cnt += num % 2;
                num >>= 1;
            }
            res[i] = cnt;
        }
        return res;
    }
};