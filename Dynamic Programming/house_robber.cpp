
// prob link: https://leetcode.com/problems/house-robber/


// Method-1
// without dp just with 2 for loop
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), maxVal;
        if(n == 1) return nums[0];
        vector<int>dp(n, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        
        for(int i=2; i<n ;i++){
            maxVal = -1;
            for(int j=0; j<i-1; j++){
                if(maxVal < dp[j]){
                    maxVal = dp[j];
                }
            }
            dp[i] = maxVal + nums[i];
        }
        maxVal = -1;
        for(int i=0;i<n;++i){
            maxVal = max(maxVal, dp[i]);
        }
        return maxVal;
    }
};

// Time Complexity : O(n^2)
// Space Complexity : O(n)



// Method-2
// from above we get an idea of storing previous values
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[1], nums[0]);
        vector<int>dp(n);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for(int i=2; i<n; i++){
            // we have two choices either to rob ith house or not
            // if we rob then we get dp[i-2] + nums[i]
            // if we leave this house then we get dp[i-1] + 0

            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)



// Method-3
// from above we get an idea of storing previous values
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[1], nums[0]);
        vector<int>dp(3);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for(int i=2; i<n; i++){
            // we have two choices either to rob ith house or not
            // if we rob then we get dp[i-2] + nums[i]
            // if we leave this house then we get dp[i-1] + 0

            dp[i%3] = max(dp[(i-2)%3] + nums[i], dp[(i-1)%3]);
        }
        return dp[(n-1)%3];
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)


// Method-4
// instead of an array we use two variables to store last and last of last value
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), prev, last, temp;
        prev = nums[0];
        if(n == 1) return prev;
        last = max(nums[1], prev);
        if(n == 2) return last;
        
        for(int i=2; i<n; i++){
            temp = last;
            last = max(last, prev + nums[i]);
            prev = temp;
        }
        return last;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
