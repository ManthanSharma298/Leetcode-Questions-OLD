
// prob link: https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    void dfs(int roomNum, vector<vector<int>>& rooms, vector<bool>& vis){
        vis[roomNum] = true;
        for(auto key: rooms[roomNum]){
            if(!vis[key]){
                dfs(key, rooms, vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n, false);
        dfs(0, rooms, vis);
        for(bool flag: vis){
            if(!flag){
                return false;
            }
        }
        return true;
    }
};

// Time complx: O(n)
// Space complx: O(n)