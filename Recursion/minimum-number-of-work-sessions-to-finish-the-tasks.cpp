// prob link: https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/

// 1. rec (TLE)
// rec + memo (Accepted)
class Solution {
public:
    vector<int> ss;
    vector<int> a;
    int t;
    unordered_map<string, int> dp;
    
    string generateKey(int i){
        string res;
        vector<int> cp = ss;
        sort(cp.begin(), cp.end());
        for(int i=0; i<cp.size(); ++i){
            res += to_string(cp[i]);
            res += '#';
        }
        
        return res;
    }
    int dfs(int i){
        if(i == a.size()) return 0;
        
        string key = generateKey(i);
        if(dp.count(key)){
            return dp[key];
        }
        int res = 14;
        // include in prev session
        for(int j=0; j<ss.size(); ++j){
            if(ss[j] + a[i] <= t){
                ss[j] += a[i];
                res = min(res, dfs(i+1));
                ss[j] -= a[i];
            }
        }
        // create another session
        ss.push_back(a[i]);
        res = min(res, 1 + dfs(i+1));
        ss.pop_back();
        
        return dp[key] = res;
    }
    
    int minSessions(vector<int>& tasks, int t) {
        a = tasks;
        this->t = t;
        return dfs(0);
    }
};