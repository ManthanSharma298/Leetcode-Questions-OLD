
// prob link: https://leetcode.com/problems/redundant-connection/

// DFS solution
// we make adj list by excluding a given edge
// then check if all the elements of visited array is true
// return that edge
class Solution {
public:
    void dfs(int curr, vector<vector<int>>&adj, vector<bool>&vis){
        vis[curr] = true;
        for(auto cld: adj[curr]){
            if(!vis[cld]){
                dfs(cld, adj, vis);
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        for(int i=n-1; i>=0; --i){
            vector<vector<int>>adj(n+1);
            vector<bool>vis(n+1, false);
            for(int j=0; j<n; ++j){
                if(j == i) continue;
                adj[edges[j][0]].push_back(edges[j][1]);
                adj[edges[j][1]].push_back(edges[j][0]);
            }   
            dfs(1, adj, vis);
            bool chk = true;
            for(int k=1; k<=n; ++k){
                if(vis[k] == false){
                    chk = false;
                    break;
                }
            }
            if(chk){
                return {edges[i][0], edges[i][1]};
            }
        }
        return {};
    } 
};

// Union find method
// ////////////////////////////////////////////////////