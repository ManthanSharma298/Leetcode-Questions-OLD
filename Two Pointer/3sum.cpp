
// prob link: https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; ++i){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l=i+1, r=n-1, sum = -nums[i];
            while(l < r){
                if(nums[l] + nums[r] == sum){
                    res.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l+1]){
                        l++;
                    }
                    while(l < r && nums[r] == nums[r-1]){
                        r--;
                    }
                    l++;
                    r--;
                }else if(nums[l] + nums[r] < sum){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return res;
    }
};

// Time complx: O(N*logN + N*N) = O(N*N)
// Space complx: O(1)