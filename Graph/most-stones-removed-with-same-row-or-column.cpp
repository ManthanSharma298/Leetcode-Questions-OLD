// prob link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/


class Solution {
public:
    void dfs(int idx, vector<vector<int>>& stones, vector<int>& vis){
        vis[idx] = 1;
        for(int i=0; i<stones.size(); ++i){
            if(!vis[i] && (stones[i][0] == stones[idx][0] || stones[i][1] == stones[idx][1])){
                dfs(i,stones,vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int e = stones.size(), comp = 0;
        vector<int> vis(e, 0);
        for(int i=0; i<e; ++i){
            if(!vis[i]){
                comp++;
                dfs(i,stones,vis);
            }
        }
        return e - comp;
    }
};
// Time complx: O(e + e) = O(e)
// Space complx: O(e)

// we can optimise it by using unordered_map<int, vector<int>> rows, cols