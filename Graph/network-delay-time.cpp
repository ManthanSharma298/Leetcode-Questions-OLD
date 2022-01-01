
// prob link: https://leetcode.com/problems/network-delay-time/solution/

// Dijkstra's Algorithm
typedef pair<int,int> pii;
class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int inf = INT_MAX;
        vector<pair<int,int>> adj[n + 1];
        vector<int>dist(n+1,inf);
        
        for (auto t : times) {
            adj[t[0]].push_back({t[2], t[1]});
        }
        
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,k});
        dist[k] = 0;
        
        while(!pq.empty()){
            int d = pq.top().first, node = pq.top().second;
            pq.pop();
            for(auto cld: adj[node]){
                int nxtNode = cld.second;
                int cldDist = cld.first;
                if(dist[nxtNode] > dist[node] + cldDist){
                    dist[nxtNode] = dist[node] + cldDist;
                    pq.push({dist[nxtNode], nxtNode});
                }
            }
        }
        int mxTime = -1;
        for(int i=1; i<=n ;++i){
            mxTime = max(mxTime, dist[i]);
        }
        if(mxTime == inf) return -1;
        return mxTime;
    }
};

// Time complx: O((V + E)log(V))    // as we are using min heap
// Space complx: O(N + E)