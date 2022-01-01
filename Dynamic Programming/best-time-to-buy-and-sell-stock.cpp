
// prob link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


// DP solution
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minTill;
        vector<int>dp(n);
        dp[0] = 0;
        minTill = prices[0];
        for(int i=1; i<n; i++){
            dp[i] = max(dp[i-1], prices[i] - minTill);
            minTill = min(minTill, prices[i]);
        }
        return dp[n-1];
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)



// DP solution
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size(), prev, curr;
        int minTill;
        prev = 0;
        curr = 0;
        minTill = prices[0];
        for(int i=1; i<n; i++){
            curr = max(prev, prices[i] - minTill);
            minTill = min(minTill, prices[i]);
            prev = curr;
        }
        return curr;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
