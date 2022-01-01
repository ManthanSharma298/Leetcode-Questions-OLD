
// prob link: https://leetcode.com/problems/insert-interval/


class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int n = intervals.size(), i = 0;
        if (n == 0){
            ans.push_back(newInterval);
            return ans;
        }
        while (i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        while (i < n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        while (i < n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1) no external storage used except the given array  

