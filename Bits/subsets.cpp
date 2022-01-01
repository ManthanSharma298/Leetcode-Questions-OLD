
// prob link: https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> res;
    void rec(int i, vector<int>& subset, vector<int>& nums){   
        if(i == nums.size()){
            res.push_back(subset);  // O(n) operation
            return;
        }
        // exclude
        rec(i+1, subset, nums);
        // include
        subset.push_back(nums[i]);
        rec(i+1, subset, nums);
        subset.pop_back();      // if you are passing subset vector by reference then 
                                // you need to pop out the element
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        rec(0, temp, nums);
        return res;
    }
};

// Time complx: O(n * 2^n) n for putting subset to res matrix but sometime we ignore it 
//                         as in last method we do not consider it 
// Space complx: O(n * 2^n) 2^n for stack calls and n (max) for subset vector

class Solution {
public:
    vector<vector<int>> res;
    void rec(int idx, vector<int>& subset, vector<int>& nums){
        res.push_back(subset);
        for(int i=idx; i<nums.size(); ++i){
            subset.push_back(nums[i]);
            rec(i+1, subset, nums);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        rec(0, subset, nums);
        return res;
    }
};

// Alternate version of above code
// Time complx: O(n * 2^n)
// Space complx: O(n * 2^n)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for(int mask = 0; mask < (1 << n); ++mask){
            vector<int> subset;
            for(int i=0; i<n; ++i){
                if((mask & (1 << i)) != 0){
                    subset.push_back(nums[i]);
                }
            }
            res.push_back(subset);
        }
        
        return res;
    }
};

// Time complx: O(2^n * n)
// Space complx: O(1)
