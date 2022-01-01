// prob link: https://leetcode.com/problems/evaluate-division/


class Solution {
public:
    class Node{
    public:
        string s;
        double v;
        Node(string s, double v){
            this->s = s;
            this->v = v;
        }
    };
    
    double dfs(string from, string to, unordered_map<string, vector<Node>>& mp, unordered_map<string,int>& vis){
        if(!mp.count(from) || !mp.count(to)) return -1;
        if(from == to) return 1;
        vis[from]++;
        for(auto cld: mp[from]){
            if(!vis[cld.s]){
                double val = dfs(cld.s,to,mp,vis);
                if(val != -1) return val*(cld.v);
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        
        unordered_map<string, vector<Node>> mp;
        
        for(int i=0; i<e.size(); ++i){
            mp[e[i][0]].push_back(Node(e[i][1], v[i]));
            mp[e[i][1]].push_back(Node(e[i][0], 1.0/v[i]));
        }
        
        vector<double> res(q.size());
        for(int i=0; i<q.size(); ++i){
            unordered_map<string, int> vis;
            res[i] = dfs(q[i][0], q[i][1], mp, vis); 
        }
        
        return res;
    }
};
// Time complx: O(q*(N+E))
// Space complx: O(q*vis.size() + mp.size())