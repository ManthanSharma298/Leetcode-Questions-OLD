
// prob link: https://www.hackerrank.com/challenges/coin-change/problem



// this is unbounded knapsack problem
// recursive backtrack solution
long rec(long n, vector<long> c, long idx){
	 if(n == 0)
       return 1;
     if(n < 0)
         return 0;
     if(idx < 0)
         return 0;

     long icld, excld;
     icld = rec(n-c[idx], c, idx);
     excld = rec(n, c, idx-1);
     return icld + excld;
 }

//Dynamic programming solution
long getWays(long n, vector<long> c) {
    long idx = c.size();
    vector<vector<long>>dp(idx+1, vector<long>(n+1, 0));
    for (long i=0; i<=idx; i++){
        for(long j=0; j<=n; j++){
            if(i == 0 && j == 0) 
                dp[i][j] = 1;
            else if(i == 0)
                dp[i][j] = 0;
            else if(j == 0)
                dp[i][j] = 1;
            else{
                long taken = 0, notTaken;
                if(j >= c[i-1])
                    taken = dp[i][j-c[i-1]];
                notTaken = dp[i-1][j];
                dp[i][j] = taken + notTaken;
            }
        }
    }
    return dp[idx][n];
}


// 1D DP solution same as coin change problem
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>dp(amount+1, 0);
        dp[0] = 1;
        for(int coin: coins){
            for(int j=coin; j<=amount; j++){       // dp[j-coin] --> j >= coin
                dp[j] = dp[j] + dp[j-coin];
            }
        }
        return dp[amount];
    }
};



