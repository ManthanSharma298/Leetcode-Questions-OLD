
// prob link: https://leetcode.com/problems/minimum-path-sum/



// Method-1 (Recursion with Memoization)
// Bottom-Up approach
class Solution {
    int dp[201][201];
public:
    
    int dfs(vector<vector<int>>& grid, int i, int j){
        int m = grid.size(), n = grid[0].size();
        if(i >= m || j >= n)
            return 1e6;
        if(i == m-1 && j == n-1)
            return grid[i][j];
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int down = dfs(grid, i+1, j), right = dfs(grid, i, j+1);
        dp[i][j] =  min(down, right) + grid[i][j];
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        for(int i=0;i<201;i++){
            for(int j=0;j<201;j++){
                dp[i][j] = -1;
            }
        }
        return dfs(grid, 0, 0);
    }
};
// Time complx: O(m*n)
// Space complx: O(m*n)



// Method-2 (2d-DP)
// Top-Down approach
class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) 
                    dp[i][j] = grid[i][j];
                else if(i == 0)
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                else if(j == 0)
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                else 
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

// Time complx: O(m*n)
// Space complx: O(m*n)


// Method-2 (2d-DP)
// Top-Down approach
class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int>prev(n, 0);
        vector<int>curr(n, 0);
        
        // filling prev array
        prev[0] = grid[0][0];
        for(int j=1; j<n; j++){
            prev[j] = prev[j-1] + grid[0][j];
        }
        // handle corner cases
        if(m == 1){
            return prev[n-1];
        }
        for(int i=1; i<m; i++){
            for(int i=0; i<n; i++){
                curr[i] = 0; 
            }
            for(int j=0; j<n; j++){
                if(j == 0)
                    curr[j] = prev[j] + grid[i][j];
                else 
                    curr[j] = min(curr[j-1], prev[j]) + grid[i][j];
            }
            for(int i=0; i<n; i++){
                prev[i] = curr[i];
            }
        }
        return curr[n-1];
    }
};

// Time complx: O(m*n)
// Space complx: O(n)
