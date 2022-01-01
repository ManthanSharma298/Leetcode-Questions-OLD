
// prob link: https://leetcode.com/problems/longest-increasing-subsequence/

// Method-1

int rec(vector<int>& nums, int nxt, int currIdx){

    if(currIdx == -1) return 0; 
    int taken = 0, notTaken;
    if(nums[currIdx] < nxt){    // then only it will be taken
        taken = 1 + rec(nums, nums[currIdx], currIdx-1);
    }
    notTaken = rec(nums, nxt, currIdx-1);
    return max(taken, notTaken);

}
int lengthOfLIS(vector<int>& nums) {
   return rec(nums, MXINT, nums.size()-1); 
}

// Time Complx: O(2^n)
// Space Complx: O(n)



//Method-2

class Solution {
private:
    static const int sz = 3000;
    int dp[sz][sz];

public:
    
    int rec(vector<int> &nums, int nxtIdx, int currIdx){

        if (currIdx == -1){
            return 0;
        }
        if (dp[nxtIdx][currIdx] > 0){
            return dp[nxtIdx][currIdx];
        }
        int taken = 0, notTaken;
        if (nxtIdx == nums.size() || nums[currIdx] < nums[nxtIdx]){     // then only current element will be taken
            taken = 1 + rec(nums, currIdx, currIdx - 1);
        }
        notTaken = rec(nums, nxtIdx, currIdx - 1);
        dp[nxtIdx][currIdx] = max(taken, notTaken);

        return dp[nxtIdx][currIdx];
    }
    int lengthOfLIS(vector<int>& nums) {
        return rec(nums, nums.size(), nums.size()-1); 

    }
};

// time: O(n^2)
// space: O(n^2)   2d array is used



//Method-3 (dp best solution)
class Solution {
public:
    int lengthOfLIS(vector<int> &nums){
        int mxVal, ans = 1;
        int len = nums.size();

        vector<int>dp(len, 0);
        dp[0] = 1;
    
        for(int i=1; i<len; ++i){
            mxVal = 0;
            for(int j=0; j<i; ++j){
                if(nums[i] > nums[j]){
                    mxVal = max(mxVal, dp[j]);
                }
            }
            dp[i] = mxVal + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    
    }
};

// Time Complx: O(n*n)
// Space Complx: O(n)




// Method-4 
int lengthOfLIS(vector<int> &nums){
    vector<int>tails;
    tails.push_back(nums[0]);
    for(int i=1; i<nums.size(); ++i){
        if(tails.back() < nums[i]){
            tails.push_back(nums[i]);
        }
        else{
            for(int j=0; j<tails.size(); ++j){
                if(tails[j] >= nums[i]){
                    tails[j] = nums[i];
                    break;
                }
            }
        }
    }    
    return tails.size();
    
}


// Time Complx: O(n*n)  worst case {little bit optimisted from previous one in time complx}
// Space Complx: O(n)



//Method-5(Best possible optimisation on Method-4)
int lengthOfLIS(vector<int> &nums)
{
    vector<int> tails;
    tails.push_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i)
    {
        if (tails.back() < nums[i]){
            tails.push_back(nums[i]);
        }
        else{
            int l = 0, r = tails.size() - 1, mid, idx;
            while (l + 1 < r){
                mid = l + (r - l) / 2;
                if (tails[mid] < nums[i])
                {
                    l = mid;
                }
                else
                {
                    r = mid;
                }
            }
            
            if (tails[l] >= nums[i])
                idx = l;
            else
                idx = r;
            
            tails[idx] = nums[i];
        }
    }
    return tails.size();
}

// Time Complx: O(n*log(n)) 
// Space Complx: O(n)




