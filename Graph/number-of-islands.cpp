
// https://leetcode.com/problems/number-of-islands/


// DFS solution
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid){
        int r = grid.size(), c = grid[0].size();
        if(grid[i][j] == '1'){
            grid[i][j] = 'V';
            if(j+1 < c){
                dfs(i, j+1, grid);
            }
            if(j-1 >= 0){
                dfs(i, j-1, grid);
            }
            if(i+1 < r){
                dfs(i+1, j, grid);
            }
            if(i-1 >= 0){
                dfs(i-1, j, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size(), c = grid[0].size(), islands = 0;
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    islands++;
                }
                
            }
        }
        return islands;
    }
};

// Time complx: O(r*c)
// Space complx: O(r*c)     {worst case}
// dfs uses stack and we fill atmost r*c(all elements) recursive calls