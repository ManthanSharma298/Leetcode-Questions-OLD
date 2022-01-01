
// prob Link: https://leetcode.com/problems/combination-sum-iv/

class Solution {
public:
    int rec(vector<int>& nums, int target, vector<int>& cache){
        if(cache[target]){
            return cache[target];
        }
        int total = 0;
        for(int num: nums){
            if(target >= num){
                total += rec(nums, target-num, cache);
            }
        }
        cache[target] = total;
        return cache[target];
    }
    int combinationSum4(vector<int>& nums, int target){
        vector<int>cache(target+1, 0);
        cache[0] = 1;
        return rec(nums, target, cache);
    }
};

// DP solution
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target){
        vector<unsigned int>dp(target+1, 0);
        dp[0] = 1;
        for(int i=1; i<=target; ++i){
            for(int num: nums){
                if(i-num >= 0){
                    dp[i] += dp[i-num];
                }
            }
        }
        return dp[target];
    }
};

// Time complx: O(target*nums.size())
// Space complx: O(target)