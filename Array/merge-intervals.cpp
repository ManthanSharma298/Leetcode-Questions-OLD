
// prob link: https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){ return a[0] < b[0]; });
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1; i<n; ++i){
            vector<int> a = res.back();
            vector<int> b = intervals[i];
            if(a[1] >= b[0]){
                res.back()[0] = min(a[0], b[0]);
                res.back()[1] = max(a[1], b[1]);
            }else{
                res.push_back(b);
            }
        }
        return res;
    }
};

// Time complx: O(n*logn) + O(n) = O(n*logn)
// Space complx: O(n*2)
