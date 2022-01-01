
// prob link: https://leetcode.com/problems/jump-game/;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool>dp(n, false);
        dp[0] = true;
        for(int i=1; i<n; ++i){
            for(int j=i-1; j>=0; --j){
                if(j + nums[j] >= i && dp[j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};

// Time Complex: O(n*n)
// Space Complx: O(n)

/*  idea is that we iterate from last index and check 
    that can we reach upto that point if we reach then 
    we decrease our last index to that index and further
    check for that.
    if not then last index remains same
    finally we check if our index is equal to 0
    if yes then we can rezh from n-1 to 0 or from 0 to n-1
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), lastIdx = n-1;
        for(int i=n-2; i>=0; --i){
            if(i + nums[i] >= lastIdx){
                lastIdx = i;
            }
        }
        return (lastIdx == 0);
    }
};

// Time Complex: O(n)
// Space Complx: O(1)