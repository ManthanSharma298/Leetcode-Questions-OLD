
// prob link: https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    
    int dfs(int i, int j, vector<vector<int>>& grid){
        int r = grid.size(), c = grid[0].size(), area;
        // condition
        if(grid[i][j] == 1){
            grid[i][j] = 0;     // mark it as visited
            area = 1;
            if(i+1 < r){
                area += dfs(i+1, j, grid);
            }
            if(i-1 >= 0){
                area += dfs(i-1, j, grid);
            }
            if(j+1 < c){
                area += dfs(i, j+1, grid);
            }
            if(j-1 >= 0){
                area += dfs(i, j-1, grid);
            }
            return area;
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0, r = grid.size(), c     = grid[0].size();
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(grid[i][j] == 1){
                    maxArea = max(maxArea, dfs(i, j, grid));
                }
            }
        }
        return maxArea;
    }
};

// Time complx: O(r*c)
// Space complx: O(r*c)