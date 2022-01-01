
// prob link: https://www.interviewbit.com/problems/minimum-difference-subsets/


// extention of subset sum problem
int func(vector<int> &nums) {
    
    int summ = 0, minDiff = 1e6;
    for(int elm: nums)
        summ += elm;
    
    vector<vector<int>>dp(nums.size()+1, vector<int>(summ+1, 0));
    for(int i=0; i<=nums.size(); i++){
        for(int j=0; j<=summ; j++){
            if(i == 0 && j == 0) dp[i][j] = 0;
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
    /*       0 1 2 3 4 5 6 7    {sum values}

        0 -> 0 0 0 0 0 0 0 0  
        1 -> 1 0 0 0 0 0 0 0  
        2 -> 1 0 0 0 0 0 1 0  
        3 -> 1 0 0 0 0 0 1 1  
        4 -> 1 0 0 0 0 1 1 1    // in this row represents that by taking all elements of array 
                                // a subset exists with sum equal to j
                                // hence we are traversing and find the min value of difference i.e. abs(j-(totalSum-j))
    */
    for(int j=0; j<=summ; ++j){
        if(dp[nums.size()][j])
            minDiff = min(minDiff, abs(summ - 2*j));
    }
    return minDiff; 
}

// Time Complx: O(m*n)
// Space Complx: O(m*n)


// little bit observation
// if s1 + s1 = summ
// we need to find min of abs(j-(summ-j))
// we can remove abs by assuming    j <= summ-j ---> j <= summ/2

for(int j=0; j<=summ/2; ++j){
    if(dp[nums.size()][j])
        minDiff = min(minDiff, summ - 2*j);    
} 





