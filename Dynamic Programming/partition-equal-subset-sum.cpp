
// prob link: https://leetcode.com/problems/partition-equal-subset-sum/


// same as subset sum problem
bool equalPartition(vector<int>& nums) {
    int summ = 0;
    for(int elm: nums)
        summ += elm;
    if(summ%2 == 1)
        return false;
    summ /= 2;
    
    vector<vector<bool>>dp(nums.size()+1, vector<bool>(summ+1, 0));
    for(int i=0; i<=nums.size(); i++){
        for(int j=0; j<=summ; j++){
            if(i == 0 && j == 0) dp[i][j] = true;
            else if(i == 0) dp[i][j] = false;
            else if(j == 0) dp[i][j] = true;
            else{
                int taken = false, notTaken;
                if(nums[i-1] <= j){
                    taken = dp[i-1][j-nums[i-1]];
                }
                notTaken = dp[i-1][j];
                dp[i][j] = taken || notTaken;
            }
        }
    }
    return dp[nums.size()][summ];
    }

// time: O(n^2)
// space: O(n^2)   2d array is used




