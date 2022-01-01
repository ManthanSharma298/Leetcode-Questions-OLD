// prob link: https://leetcode.com/problems/maximum-earnings-from-taxi/


class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        const int N = 100002;
        long long dp[N] = {0};
        // dp[i] = max earning starting from i
        int r = rides.size();
        // dp[0] = 0
        for(int i=n; i>=1; --i){
            dp[i] = max(dp[i], dp[i+1]); // skip ride
            for(int j=0; j<r; ++j){
                if(rides[j][0] == i){
                    long long d = rides[j][1]-rides[j][0]+rides[j][2];
                    dp[i] = max(dp[i], dp[rides[j][1]] + d);
                }
            }
        }
        return dp[1];   // as if dp[i] < dp[i+1] then also dp = dp[i+1] as dp[i] = max(dp[i], dp[i+1])
    }
};
// Time complx: O(n*r)
// Space complx: O(n)



class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        const int N = 100002;
        long long dp[N] = {0};
        // dp[i] = max earning starting from i
        int r = rides.size();
        // dp[0] = 0
        sort(rides.begin(),rides.end());
        int j=r-1;
        for(int i=n; i>=1; --i){
            dp[i] = max(dp[i], dp[i+1]); // skip ride
            while(j>=0 && rides[j][0] >= i){
                if(rides[j][0] == i){
                    long long d = rides[j][1]-rides[j][0]+rides[j][2];
                    dp[i] = max(dp[i], dp[rides[j][1]] + d);
                }
                j--;
            }
        }
        return dp[1];   // as if dp[i] < dp[i+1] then also dp = dp[i+1] as dp[i] = max(dp[i], dp[i+1])
    }
};
// Time complx: O(n+r)
// Space complx: O(n)