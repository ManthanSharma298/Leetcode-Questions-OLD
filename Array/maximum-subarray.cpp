
// prob link: https://leetcode.com/problems/maximum-subarray/

// prefix array
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), mxSum = -1e6;
        //prefix array
        vector<int>pre(n+1, 0);
        for(int i=1; i<=n; ++i){
            pre[i] = pre[i-1] + nums[i-1];
        }
        for(int i=1; i<=n; ++i){
            for(int j=i; j<=n; ++j){
                mxSum = max(mxSum, pre[j]-pre[i-1]);
            }
        }
        return mxSum;
    }
};

// Time complx: O(N*N)
// Space complx: O(1)

// DP approach
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), mxSum;
        vector<int>dp(n,0);
        dp[0] = nums[0];
        mxSum = dp[0];
        for(int i=1; i<n; ++i){
            dp[i] = (dp[i-1] < 0) ? nums[i] : dp[i-1] + nums[i];
            mxSum = max(mxSum, dp[i]);
        }
        return mxSum;
    }
};

// Time complx: O(N)
// Space complx: O(N)

// optimize DP approach
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), mxSum, prev, curr;
        prev = nums[0];
        mxSum = nums[0];
        for(int i=1; i<n; ++i){
            curr = (prev < 0) ? nums[i] : prev + nums[i];
            mxSum = max(mxSum, curr);
            prev = curr;
        }
        return mxSum;
    }
};

// Time complx: O(N)
// Space complx: O(1)
