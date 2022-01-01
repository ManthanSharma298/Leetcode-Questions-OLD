
// prob link: https://leetcode.com/problems/surrounded-regions/



// DFS solution
class Solution {
public:
    bool isValid(int i, int j, int r, int c){
        return ((i>=0 && i<=r-1) && (j>=0 && j<=c-1));
    }
    void dfs(int i, int j, vector<vector<char>>& board){
        int r = board.size(), c = board[0].size();
        if(board[i][j] == 'O'){
            board[i][j] = '#';
            if(isValid(i+1, j, r, c)){
                dfs(i+1, j, board);
            }
            if(isValid(i, j+1, r, c)){
                dfs(i, j+1, board);
            }
            if(isValid(i, j-1, r, c)){
                dfs(i, j-1, board);
            }
            if(isValid(i-1, j, r, c)){
                dfs(i-1, j, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int r = board.size(), c = board[0].size();
        for(int j=0; j<c; ++j){
            if(board[0][j] == 'O'){
                dfs(0, j, board);
            }
        }
        for(int j=0; j<c; ++j){
            if(board[r-1][j] == 'O'){
                dfs(r-1, j, board);
            }
        }
        for(int i=0; i<r; ++i){
            if(board[i][0] == 'O'){
                dfs(i, 0, board);
            }
        }
        for(int i=0; i<r; ++i){
            if(board[i][c-1] == 'O'){
                dfs(i, c-1, board);
            }
        }
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
        
    }
};
// Time Complx: O(r*c)
// as at max we are checking all entries of matrix