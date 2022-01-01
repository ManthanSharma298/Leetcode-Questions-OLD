
// prob link: https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xr = n;
        for(int i=0; i<n; ++i){
            xr = xr ^ (i^nums[i]);
        }
        return xr;
    }
};

// Time complx: O(N)
// Space complx: O(1)