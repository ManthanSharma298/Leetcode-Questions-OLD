// prob link: https://leetcode.com/problems/permutations/


// using freq array
class Solution {
    vector<vector<int>> res;
public:
    void rec(vector<int>& curr, vector<int>& f, vector<int>& nums){
        if(curr.size() == nums.size()){
            res.push_back(curr);
            return;
        }
        for(int i=0; i<nums.size(); ++i){
            if(f[i] == 1) continue;
            curr.push_back(nums[i]);
            f[i] = 1;
            rec(curr, f, nums);
            f[i] = 0;
            curr.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> f(nums.size(), 0);
        vector<int> curr;
        rec(curr, f, nums);
        return res;
    }
};
// Time complx: O(n*n!)
// Space complx: O(n) + O(n) for curr and f array


class Solution {
    vector<vector<int>> res;
public:
    void rec(int i, vector<int>& nums){
        if(i == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int j=i; j<nums.size(); ++j){
            swap(nums[i], nums[j]);
            rec(i+1, nums);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        rec(0, nums);
        return res;
    }
};
// Time complx: O(n*n!)
// Space complx: O(1) except res vector