
// prob link: https://leetcode.com/problems/course-schedule-ii/

// DFS solution
class Solution {
public:
    void dfs(int n, vector<bool>&visi, vector<vector<int>>& adj, stack<int>&stk){
        visi[n] = true;
        for(int cld: adj[n]){
            if(!visi[cld]){
                dfs(cld, visi, adj, stk);
            }
        }
        stk.push(n);
    }
    bool acyclic(int n, vector<bool>&vis, vector<bool>&visUntil, vector<vector<int>>& adj){
        vis[n] = true;
        visUntil[n] = true;
        for(int cld: adj[n]){
            if(!vis[cld]){
                if(!acyclic(cld, vis, visUntil, adj)){
                    return false;
                }
            }
            else if(visUntil[cld]){
                return false;
            }
        }
        visUntil[n] = false;
        return true;
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>>adj(n);
        vector<bool>vis(n, false), visUntil(n, false);
        for(auto elm: p){
            adj[elm[1]].push_back(elm[0]);
        }
        for(int i=0; i<n; ++i){
            if(!vis[i] && !acyclic(i, vis, visUntil, adj)){ // graph is cyclic
                return {};
            }
        }
        stack<int>stk;
        vector<int>ans;
        vector<bool>visi(n, false);
        for(int i=0; i<n; ++i){
            if(!visi[i]){
                dfs(i, visi, adj, stk);
            }
        }
        while(!stk.empty()){
            ans.push_back(stk.front());
            stk.pop();
        }
        return ans;
    }
};

// Time complx: O(E + V) = O(n + p.size())
// Space complx: O(E + V) = O(n + p.size())


// BFS solution
class Solution {
public:
    bool acyclic(int n, vector<bool>&vis, vector<bool>&visUntil, vector<vector<int>>& adj){
        vis[n] = true;
        visUntil[n] = true;
        for(int cld: adj[n]){
            if(!vis[cld]){
                if(!acyclic(cld, vis, visUntil, adj)){
                    return false;
                }
            }
            else if(visUntil[cld]){
                return false;
            }
        }
        visUntil[n] = false;
        return true;
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>>adj(n);
        vector<int>ans = {};
        vector<bool>vis(n, false), visUntil(n, false);
        for(auto elm: p){
            adj[elm[1]].push_back(elm[0]);
        }   
        for(int i=0; i<n; ++i){
            if(!vis[i] && !acyclic(i,vis,visUntil,adj)){
                return ans;
            }
        }
        vector<int>indeg(n, 0);
        for(int i=0; i<n; ++i){
            for(int cld: adj[i]){
                indeg[cld]++;
            }
        }
        queue<int>q;
        for(int i=0; i<n; ++i){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int cld: adj[node]){
                indeg[cld]--;
                if(indeg[cld] == 0){
                    q.push(cld);
                }
            }
        }
        return ans;
    }
};

// Time complx: O(E + V) = O(n + p.size())
// Space complx: O(E + V) = O(n + p.size())