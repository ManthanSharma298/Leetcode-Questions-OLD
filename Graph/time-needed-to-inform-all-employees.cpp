
// prob link: https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution {
public:
    int dfs(int node, vector<int>& informTime, vector<vector<int>>& adj){
        if(adj[node].size() == 0) return 0;
        int maxTime = 0;
        for(int cld: adj[node]){
            maxTime = max(maxTime, dfs(cld, informTime, adj));
        }
        return maxTime + informTime[node];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        for(int i=0; i<manager.size(); i++){
            if(manager[i] != -1){
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(headID, informTime, adj);
    }
};

// Time complx: O(n)
// Space complx: O(n*n)     to store the graph

// Bottom Up Approach
class Solution {
public:
    int dfs(int node, vector<int>& manager, vector<int>& informTime){
        if(manager[node] != -1){
            informTime[node] += dfs(manager[node], manager, informTime);
            manager[node] = -1;     // as not again call parent node
        }
        return informTime[node];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int time = 0;
        for(int i=0; i<n; ++i){
            time = max(time, dfs(i, manager, informTime));
        }
        return time;
    }
};

// Time complx: O(n)
// Space complx: O(n)   but no extra space is required O(n) for manager array  