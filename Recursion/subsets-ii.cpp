
// prob link: https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    int n;
    vector<vector<int>> res;
    void rec(int idx, vector<int> subset, vector<int>& nums){
        res.push_back(subset);
        for(int i=idx; i<n; ++i){
            if(i == idx || nums[i] != nums[i-1]){
                subset.push_back(nums[i]);
                rec(i+1, subset, nums);
                subset.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end()); // so that we can compare nums[i] and nums[i-1]
        vector<int> subset;
        rec(0, subset, nums);
        return res;
    }
};

// Time complx: O(n * 2^n)
// Space complx: O(n * 2^n) + O(n) = O(n * 2^n)