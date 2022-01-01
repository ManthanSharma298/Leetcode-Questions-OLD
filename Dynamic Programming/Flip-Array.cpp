// prob link: https://www.interviewbit.com/old/problems/flip-array/

int Solution::solve(const vector<int> &a) {
    int inf = 1e6; 
    int sm = 0;
    int n = a.size();
    for(int i=0; i<n; ++i){
        sm += a[i];
    }
    sm /= 2;
    int dp[sm+1];
    for(int i=0; i<=sm; ++i){
        dp[i] = inf;
    }
    dp[0] = 0;
    for(int i=0; i<n; ++i){
        for(int j=sm; j>=a[i]; --j){
            dp[j] = min(dp[j], dp[j - a[i]] + 1);
        }
    }
    for(int i=sm; i>=0;i--){
        if(dp[i] != inf) return dp[i];
    }
}

// Approach
// x - y = sum
// we need to minimize the sum, optimised way is when x and y are close enough
// hence we start from sum/2 to 0 and try to calculate the min numer of elm that forms x (x < y)
// hence we need to flip these many number of elements

// Time complx: O(n*sum)
// Space complx: O(sum)
