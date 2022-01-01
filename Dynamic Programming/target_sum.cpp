// prob link: https://leetcode.com/problems/target-sum/


// same as number of subsets with given sum x 
int func(vector<int> &nums, int target){
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = target; j >= nums[i]; j--)
        {
            dp[j] = dp[j] + dp[j - nums[i]];    // j-nums[i] >= 0 --> j >= nums[i]
        }
    }
    return dp[target];
}

int findTargetSumWays(vector<int> &nums, int target){   
    int summ = 0;
    for (int elm : nums)
        summ += elm;

    if ((summ + target) % 2 == 1)
        return 0;
    target = (summ + target) / 2;
    return func(nums, target);
}

// eg {1,1,1,1,1}  target=3
// +(1,1,1,1)  -(1)
//      s1      s2
// s1-s2 = target      && s1+s2 = summ
// s1 = (summ + target)/2  


// Time Complx: O(nums.size*target)
// Space Complx: O(target) 





