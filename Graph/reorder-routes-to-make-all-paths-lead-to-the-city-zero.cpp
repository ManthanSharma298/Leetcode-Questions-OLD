// prob link: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/


class Solution {
public:
    int res;
    void dfs(int n, vector<set<int>>& g, vector<vector<int>>& c, vector<int>& vis){
        vis[n] = 1;
        for(int cld: c[n]){
            if(vis[cld]) continue;
            if(g[cld].count(n) == 0){
                res++;
            }
            dfs(cld, g, c, vis);
        }
    }
    int minReorder(int n, vector<vector<int>>& e) {
        vector<set<int>> g(n); 
        vector<vector<int>> c(n);
        vector<int> vis(n,0);
        
        for(int i=0; i<e.size(); ++i){
            g[e[i][0]].insert(e[i][1]);
        }
        for(int i=0; i<e.size(); ++i){
            c[e[i][0]].push_back(e[i][1]);
            c[e[i][1]].push_back(e[i][0]);
        }
        dfs(0, g, c, vis);
        return res;
    }
};

// Time complx: O(N)
// Space complx: O(E) + O(N) = O(N+E)


// Taking childs with sign but keep in mind 0 can't be taken, but in thhis question 0 is the root so no problem
class Solution {
public:
    int res;
    void dfs(int n, vector<vector<int>>& g, vector<int>& vis){
        vis[n] = 1;
        for(int cld: g[n]){
            if(vis[abs(cld)] == 1) continue;
            dfs(abs(cld),g,vis);
            if(cld > 0) res++;
        }
    }
    int minReorder(int n, vector<vector<int>>& e) {
        vector<vector<int>> g(n);
        vector<int> vis(n, 0);
        for(int i=0; i<e.size(); ++i){
            g[e[i][0]].push_back(e[i][1]);
            g[e[i][1]].push_back(-e[i][0]);
        }
        dfs(0,g,vis);
        return res;
    }
};

// Time complx: O(N)
// Space complx: O(N) = O(N)

// 0 -> {+1, -4} childs are stored like this