
// prob link: https://www.interviewbit.com/problems/subset-sum-problem/


int solve(vector<int> &A, int B) {
    vector<vector<int>>dp(A.size()+1, vector<int>(B+1, 0));
    for(int i=0; i<=A.size(); i++){
        for(int j=0; j<=B; j++){
            if(i == 0 && j == 0) dp[i][j] = 1;
            else if(j == 0) dp[i][j] = 1;
            else if(i == 0) dp[i][j] = 0;
            else{
                int taken = 0, notTaken;
                if(A[i-1] <= j){
                    taken = dp[i-1][j-A[i-1]];
                }
                notTaken = dp[i-1][j];
                dp[i][j] = taken || notTaken;
            }
        }
    }
    return dp[A.size()][B];
}
// time: O(n^2)
// space: O(n^2)   2d array is used

int solve(vector<int> &A, int B) {
    vector<int>dp(B+1, 0);
    dp[0] = 1;
    for(int i=0; i<A.size(); i++){
        for(int j=B; j>=A[i]; j--){
            dp[j] = dp[j] || dp[j - A[i]];
        }
    }
    return dp[B];
}


// advantage of using this is that elements can be zero in above implementation
// we can't take 0 elements
// Time Complx: O(B*A.size)
// Space Complx: O(B)

// dp[j] = dp[j] || dp[j-elm]
// this means either dp[j] is true or dp[j-elm] is true 
// then the sum j is possible 
// if dp[j-elm] is true then by adding elm to this we get the sum j
//
// for more info visit: https://www.youtube.com/watch?v=-httet0UVUU



