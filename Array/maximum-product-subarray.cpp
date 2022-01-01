
// prob link: https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), mxPro, mx, mn;
        mxPro = nums[0];
        mx = nums[0];
        mn = nums[0];
        for(int i=1; i<n; ++i){
            int temp = mx;
            mx = max({mx*nums[i], mn*nums[i], nums[i]});
            mn = min({temp*nums[i], mn*nums[i], nums[i]});
            mxPro = max(mxPro, mx);
        }
        return mxPro;
    }
};

// Time complx: O(N)
// Space complx: O(1)