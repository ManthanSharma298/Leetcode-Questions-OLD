
// prob link: https://leetcode.com/problems/super-egg-drop/


// Recursive
class Solution {
public:
    int superEggDrop(int k, int n) {
        // base case
        if(k == 1) return n;
        if(n == 0 || n == 1) return n;
        
        int res = 1e9;
        for(int f=1; f<=n; ++f){
            // consider worst case
            int val = max(superEggDrop(k-1,f-1),superEggDrop(k,n-f))+1;
            res = min(res, val);
        }
        return res;
    }
};

// Time complx: O(n*2^min(n,k)) 
// Space complx: O(1)     // except stack calls


// rec + memo
class Solution {
public:
    int rec(int k, int n, vector<vector<int>>& dp){
        // base case
        if(k == 1) return n;
        if(n == 0 || n == 1) return n;
        if(dp[k][n] != -1) return dp[k][n];
        
        int res = 1e9;
        for(int f=1; f<=n; ++f){
            // consider worst case
            int val = max(rec(k-1,f-1,dp),rec(k,n-f,dp))+1;
            res = min(res, val);
        }
        dp[k][n] = res;
        return res;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1,-1));
        return rec(k,n,dp);
    }
};

// Time complx: O(n*n*k) 
// Space complx: O(n*k)     


// rec + memo + binary search
class Solution {
public:
    int rec(int k, int n, vector<vector<int>>& dp){
        // base case
        if(k == 1) return n;
        if(n == 0 || n == 1) return n;
        if(dp[k][n] != -1) return dp[k][n];
        
        int res = 1e9, l = 0, r = n, m, val;
        while(l+1 < r){
            m = l + (r-l)/2;
            int bk = rec(k-1,m-1,dp), nbk = rec(k,n-m,dp);
            val = max(bk, nbk)+1;
            if(bk < nbk){
                l = m;
            }
            else{
                r = m;
            }
            res = min(res, val);
        }
        dp[k][n] = res;
        return res;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1,-1));
        return rec(k,n,dp);
    }
};

// Time complx: O(n*k*logn) 
// Space complx: O(n*k)  


// DP + binary search
class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int>(n+1));
        for(int i=0; i<=n; ++i){
            dp[0][i] = 0;
            dp[1][i] = i;
        }
        for(int i=0; i<=k; ++i){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        for(int i=2; i<=k; ++i){
            for(int j=2; j<=n; ++j){
                int res = 1e9, l = 0, r = j, m, val;
                while(l+1 < r){
                    m = l + (r-l)/2;
                    int bk = dp[i-1][m-1], nbk = dp[i][j-m];
                    val = max(bk, nbk)+1;
                    if(bk < nbk){
                        l = m;
                    }
                    else{
                        r = m;
                    }
                    res = min(res, val);
                    dp[i][j] = res;
                }
            }
        }
        return dp[k][n];
    }
};

// Time complx: O(n*k*logn) 
// Space complx: O(n*k) 









