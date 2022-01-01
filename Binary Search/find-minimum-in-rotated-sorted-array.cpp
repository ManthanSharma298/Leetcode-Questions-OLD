// prob link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/


class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l=-1, r=n-1;
        while(l+1 < r){
            int m = l+(r-l)/2;
            if(nums[n-1] > nums[m]){
                r = m;
            }
            else{
                l = m;
            }
        }
        return nums[r];
    }
};

// FFFF'T'TTTT

// Time complx: O(logn)
// Space complx: O(1)