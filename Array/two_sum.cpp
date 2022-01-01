
// prob link: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int idx;
        unordered_map<int,int>list;
        for(int i=0; i<nums.size(); i++){
            auto it = list.find(target - nums[i]);
            idx = (it != list.end()) ? it->second : -1;
            if(idx != -1){
                return {i, idx};
            }
            list.insert({nums[i], i});
        }
        return {};
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
