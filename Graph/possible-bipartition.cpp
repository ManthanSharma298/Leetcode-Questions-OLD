
// prob link: https://leetcode.com/problems/possible-bipartition/

// BFS solution
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int size = 0, paint = 0;
        vector<vector<int>> adj(n+1);
        for(auto val: dislikes){
            adj[val[0]].push_back(val[1]);
            adj[val[1]].push_back(val[0]);
        }
        queue<int>q;
        vector<int>color(n+1, -1);
        for(int i=1; i<=n; ++i){
            if(color[i] == -1){
                q.push(i);
                while(!q.empty()){
                    paint = (paint == 1) ? 0 : 1;
                    size = q.size();
                    while(size--){
                        int par = q.front();
                        q.pop();
                        color[par] = paint;
                        for(int cld: adj[par]){
                            if(color[cld] == -1){
                                q.push(cld);
                            } 
                            else if(color[cld] == paint){
                                return false;
                            }
                        }
                    }    
                }
            }
        }
        return true;
    }
};


// Time complx: O(N + E)
// Space complx: O(N) + O(E) = O(N + E) -> vis array + queue


// DFS solution
class Solution {
public:
    bool dfs(int node, int paint, vector<vector<int>>& adj, vector<int>& color){
        color[node] = paint;
        paint = (paint == 1) ? 0 : 1;
        for(int cld: adj[node]){   
            if(color[cld] == -1){
                if(!dfs(cld, paint, adj, color)){
                    return false;
                }
            }
            else if(color[cld] == color[node]){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int paint = 0;
        vector<vector<int>> adj(n+1);
        vector<int>color(n+1, -1);
        for(auto val: dislikes){
            adj[val[0]].push_back(val[1]);
            adj[val[1]].push_back(val[0]);
        }
        for(int i=1; i<=n; ++i){
            if(color[i] == -1 && !dfs(i, paint, adj, color)){
                return false;
            }
        }
        return true;
    }
};

// Time complx: O(N + E)
// Space complx: O(N + E) = vis array O(N) + recursive stack O(E)