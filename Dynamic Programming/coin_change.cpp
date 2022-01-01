
// prob link: https://leetcode.com/problems/coin-change/


// variation of number of possible ways in coin change 
// Method-1 (2d DP)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, 0));
        for(int i=0; i<=n; i++){
            for(int j=0; j<=amount; j++){
                if(i == 0 && j == 0)
                    dp[i][j] = 0;
                else if(j == 0)
                    dp[i][j] = 0;
                else if(i == 0)
                    dp[i][j] = 1e6;
                else{
                    int taken = (j >= coins[i-1]) ? dp[i][j-coins[i-1]] : 1e6;
                    int notTaken = dp[i-1][j];
                    dp[i][j] = min(1+taken, notTaken);
                }
            }
        }
        return ((dp[n][amount] > 1e6) ? -1 : dp[n][amount]);
    }
};
// Time Complx: O(amount*coins.size)
// Space Complx: O(amount*coins.size)


// Method-2 (1d DP)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, 1e6);
        dp[0] = 0;
        for(int coin: coins){
            for(int j=coin; j<=amount; j++){       // dp[j-coin] --> j >= coin
                dp[j] = min(dp[j], 1+dp[j-coin]);
            }
        }
        return ((dp[amount] >= 1e6) ? -1 : dp[amount]);
    }
};

// for 1D DP:
// moving from left to right --> unbounded knapsack -> each element can be used infinite time
// moving from right to left --> bounded knapsack -> each element can be used maximum one time

// Hence in this case we move from left to right
// starting from j=coins because either start from j=0 and put the condition if(j >= coin) or directly start from j=coin


// Time Complx: O(amount*coins.size)
// Space Complx: O(amount)







