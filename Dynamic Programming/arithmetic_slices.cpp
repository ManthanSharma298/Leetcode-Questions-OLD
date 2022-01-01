
// prob link: https://leetcode.com/problems/arithmetic-slices/


// Method-1 (basic loop)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), total=0, idx=0;
        if(n < 3) return 0;
        for(int i=2; i<n; i++){
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]){
                total += (i-idx)-1;
                // whether to take this number or not 
                // if we take this number then new subarrays
                // formed will be len(prev_array)-1
            }
            else{
                idx=i-1;
                // then change the idx from 0 to i-1
            }
        }
        return total;
    }
};

// Time complx: O(n)
// Space complx: O(1)

