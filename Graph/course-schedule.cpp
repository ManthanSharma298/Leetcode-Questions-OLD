
// prob link: https://leetcode.com/problems/course-schedule/

// DFS solution
class Solution {
public:
    bool dfs(int n, vector<bool>&vis, vector<bool>&visUntil, vector<vector<int>>& adj){
        vis[n] = true;
        visUntil[n] = true;
        for(int cld: adj[n]){
            if(!vis[cld]){
                if(!dfs(cld, vis, visUntil, adj)){
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
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>>adj(n);
        vector<bool>vis(n, false), visUntil(n, false);
        for(auto elm: p){
            adj[elm[1]].push_back(elm[0]);
        }
        for(int i=0; i<n; ++i){
            if(!vis[i] && !dfs(i, vis, visUntil, adj)){
                return false;
            }
        }
        return true;
    }
};

// Time complx: O(n + p.size())
// Space complx: O(n + p.size())



// BFS solution
class Solution {
public:

    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        for(auto elm: p){
            adj[elm[1]].push_back(elm[0]);
        }   
        //creating indegree
        for(int i=0; i<n; ++i){
            for(int cld: adj[i]){
                indeg[cld]++;
            }
        }
        // applying bfs
        queue<int>q;
        for(int i=0; i<n; ++i){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        int cnt=0;
        while(!q.empty()){
            int node = q.front();
            cnt++;
            q.pop();
            for(int cld: adj[node]){
                indeg[cld]--;
                if(indeg[cld] == 0){
                    q.push(cld);
                }
            }
        }
        return (cnt == n) ? true : false;
    }
};

// Time complx: O(N+E)
// Space complx: O(N) indeg array + O(E) queue = O(N+E)


