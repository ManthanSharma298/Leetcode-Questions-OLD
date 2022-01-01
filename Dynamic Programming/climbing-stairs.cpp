
// prob link: https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        // dp[i] = dp[i-1] + dp[i-2]
        int before = 0, prev = 1, curr;
        for(int i=1; i<=n; ++i){
            curr = prev + before;
            before = prev;
            prev = curr;
        }
        return curr;
    }
};

// Time complx: O(n)
// Space complx: O(1)