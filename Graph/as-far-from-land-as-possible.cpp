
// prob link: https://leetcode.com/problems/as-far-from-land-as-possible/

// DFS solution
class Solution {
public:
    void dfs(int i, int j, int dist, vector<vector<int>>& grid){
        int n = grid.size();
        if (i<0 || j<0 || i>=n || j>=n || (grid[i][j] != 0 && dist >= grid[i][j])) return;
        // if grid[i][j] != 0 then only continue if dist < grid[i][j] 

        grid[i][j] = dist;
        dfs(i+1, j, dist+1, grid);
        dfs(i-1, j, dist+1, grid);
        dfs(i, j+1, dist+1, grid);
        dfs(i, j-1, dist+1, grid);

    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), maxDistance = -1;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    dfs(i, j, 1, grid);
                }
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] != 1){
                    maxDistance = max(maxDistance, grid[i][j]-1);
                }
            }
        }
        return maxDistance;
    }
};

// Time complx: O(n*n*num_of_land_cells)
// Space complx: O(n*n) for stack in recursion


// BFS solution
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), size = 0, step = 0;
        queue<pair<int,int>> q;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] == 1){
                    q.push({i+1, j});
                    q.push({i-1, j});
                    q.push({i, j+1});
                    q.push({i, j-1});
                }
            }
        }
        while(!q.empty()){
            size = q.size();
            step++;
            while(size--){
                int i = q.front().first, j = q.front().second;
                q.pop();
                if(i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == 0){
                    grid[i][j] = step;
                    q.push({i+1, j});
                    q.push({i-1, j});
                    q.push({i, j+1});
                    q.push({i, j-1});
                }
            }
        }
        return (step == 1 ? -1 : step-1);
    }
};

/*[[1,0,0,0],
  [0,0,0,0],
  [0,0,1,0],
  [0,1,0,0]]

  then we get 
    1 1 2 3 
    1 2 1 2 
    2 1 1 1 
    1 1 1 2 


    finally step is incremented one more 
    so return step-1
    but if step == 1 then there are no water bodies
    return -1

// Time complx: O(n*n)
// Space complx: O(n)
    // for each node we insert atmost 4 childs
    hence space complx of queue is O(n*4) = O(n)

*/