// prob link: https://leetcode.com/problems/single-element-in-a-sorted-array/


class Solution {
public:
    int isVal(int m, vector<int>& nums){
        int n = nums.size();
        if(m+1 < n && nums[m] == nums[m+1] && m%2 == 0) return 1;
        if(m-1 >= 0 && nums[m] == nums[m-1] && m%2 == 1) return 1;
        return 0;
        
    }
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l=-1, r=n-1;    // TTTT'F'FFFFF  I need to return first false
        while(l+1 < r){
            int m = l+(r-l)/2;
            if(isVal(m, nums)){
                l = m;
            }
            else{
                r = m;
            }
        }
        return nums[r];
    }
};

// Time complx: O(logn)
// Space complx: O(1)