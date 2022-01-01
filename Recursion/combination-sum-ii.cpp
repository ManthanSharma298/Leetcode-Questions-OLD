
// prob link: https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    vector<vector<int>> res;
    void rec(int idx, int target, vector<int>& v, vector<int>& candidates){
        if(target == 0){
            res.push_back(v);
            return;
        }
        for(int i=idx; i<candidates.size(); ++i){
            if(i != idx && candidates[i] == candidates[i-1]) continue;
            if(target-candidates[i] >= 0){
                v.push_back(candidates[i]);
                rec(i+1, target-candidates[i], v, candidates);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        rec(0, target, v, candidates);
        return res;
    }
};

// Time complx: O(k * 2^n)
// Space complx: O(k * 2^n) + O(n) {for stack}