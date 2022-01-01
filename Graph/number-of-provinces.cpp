
// prob link: https://leetcode.com/problems/number-of-provinces/


// In this question basically we need to find number of connected components in a undirected graph
// DFS Solution
class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>&vis, int idx){
        int n = isConnected.size();
        vis[idx] = true;
        for(int j=0; j<n; ++j){
            if(isConnected[idx][j] == 1 && !vis[j]){
                dfs(isConnected, vis, j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int connections = 0, n = isConnected.size();
        vector<bool>vis(n, false);
        for(int i=0; i<n; ++i){
            if(!vis[i]){
                connections++;
                dfs(isConnected, vis, i);
            }
        }
        return connections;
    }
};

// Time complx: O(N+E)  at large values E = V*V
// Space complx: O(N)

// Union Find Solution
class Solution {
public:
    int findParent(int idx, vector<int>&parent){
        return (parent[idx] == idx) ? idx : findParent(parent[idx], parent);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), components = n;
        vector<int>parent(n);
        for(int i=0; i<n; ++i){     // initially all belong to different group
            parent[i] = i;
        }
        // checking if merging is possible
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                if(isConnected[i][j] == 1){
                    int prntI = findParent(i, parent),
                        prntJ = findParent(j, parent);
                    if(prntI != prntJ){     // need to merge as they are connected
                        parent[prntJ] = prntI;      // Important Step
                        components--;
                    }
                }
            }
        } 
        return components;
    }
};

// Time complx: O(n*n*logn) {worst case}
// Space complx: O(n)   {extra space for parent array}
