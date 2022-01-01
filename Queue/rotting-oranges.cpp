// prob link : https://leetcode.com/problems/rotting-oranges/


class Solution {
public:
    int isValid(int x, int y, vector<vector<int>>& grid){
        int m=grid.size(), n=grid[0].size();
        return (x<0 || y<0 || x>=m || y>=n || grid[x][y] != 1 ? 0 : 1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size(), n=grid[0].size(), time=0;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    time = -1;
                }
            }
        }
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; ++i){
                int x=q.front().first, y=q.front().second;
                q.pop();
                if(isValid(x+1,y,grid)){
                    grid[x+1][y] = 2;
                    q.push({x+1,y});
                }
                if(isValid(x-1,y,grid)){
                    grid[x-1][y] = 2;
                    q.push({x-1,y});
                }
                if(isValid(x,y+1,grid)){
                    grid[x][y+1] = 2;
                    q.push({x,y+1});
                }
                if(isValid(x,y-1,grid)){
                    grid[x][y-1] = 2;
                    q.push({x,y-1});
                }
            }
            time++;
        }
        int f=1;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] == 1){
                    f=0;
                    break;
                }
            }
        }
        
        return (f ? time : -1);
    }
};

// Little bit clean code can we more cleaned if use dir array for four directions
class Solution {
public:

    int isValid(int x, int y, vector<vector<int>>& grid){
        int m=grid.size(), n=grid[0].size();
        return (x<0 || y<0 || x>=m || y>=n || grid[x][y] != 1 ? 0 : 1);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size(), n=grid[0].size(), time=0, one=0;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] == 0) continue;
                else{
                    if(grid[i][j] == 2) q.push({i,j});
                    one++;
                }
            }
        }
        if(one == 0) return 0;  // edge case
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; ++i){
                int x=q.front().first, y=q.front().second;
                q.pop();
                if(isValid(x+1,y,grid)){
                    grid[x+1][y] = 2;
                    q.push({x+1,y});
                }
                if(isValid(x-1,y,grid)){
                    grid[x-1][y] = 2;
                    q.push({x-1,y});
                }
                if(isValid(x,y+1,grid)){
                    grid[x][y+1] = 2;
                    q.push({x,y+1});
                }
                if(isValid(x,y-1,grid)){
                    grid[x][y-1] = 2;
                    q.push({x,y-1});
                }
            }
            time++;
            one -= sz;
        }
        return (one > 0 ? -1 : time-1);
    }
};
// Time complx: O(N*N*4) as at max N*N elements are there in a queue and we are checking in 
//                          all four directions
// Space complx: O(N*N)
