// prob link: https://leetcode.com/problems/sudoku-solver/


class Solution {
    int n = 9;
public:
    bool check(char v, int r, int c, vector<vector<char>>& board){
        for(int i=0; i<n; ++i){
            if(board[i][c] == v) return false;
            if(board[r][i] == v) return false;
            if(board[3*(r/3)+i/3][3*(c/3)+i%3] == v) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(board[i][j] == '.'){
                    // try all values
                    for(char val='1'; val<='9'; ++val){
                        if(check(val,i,j,board)){
                            board[i][j] = val;
                            if(solve(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    // if there is no valid solution
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

// Time complx: O(9^(n*n)) where 9 is the number of possible choices for a place