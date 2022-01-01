
// prob link: https://leetcode.com/problems/combination-sum/

class Solution {
public:
    int n;
    vector<int> v;
    vector<vector<int>> res;
    void rec(int i, int target, vector<int>& candidates){
        if(target == 0){
            res.push_back(v);
            return;
        }
        // exclude
        if(i < n-1){
            rec(i+1, target, candidates);
        }
        // include
        if(target-candidates[i] >= 0){
            v.push_back(candidates[i]);
            rec(i, target-candidates[i], candidates);
            v.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        rec(0,target,candidates);
        return res;
    }
};

// Time complx: O(k * 2^target) as height of rec tree is target/number so at max target(number = 1)
// Space complx: O(k * x)
// where k is avg length of v array
// and x is number of combinations s.t. their sum is equal to target

// eg
//    2->2->2->2
// 7->5->3->1->-1
// 7/2 = 4 is the height of this tree
// because we are taking one element as many times as possible