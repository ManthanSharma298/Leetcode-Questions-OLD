
// prob link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l=0, r=n-1, m;
        while(l + 1 < r){
            m = l + (r-l)/2;
            if(nums[m] > nums[n-1]){
                l = m;
            }else{
                r = m;
            }
        }
        return min(nums[l], nums[r]);
    }
};

// Time complx: O(logN)
// Space complx: O(1)