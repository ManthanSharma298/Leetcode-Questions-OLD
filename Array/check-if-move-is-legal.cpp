
// prob link: https://leetcode.com/problems/check-if-move-is-legal/

class Solution {
public:
    bool isValid(int x, int y){
        return (x<8 && x>=0 && y<8 && y>=0);
    }
    char iv(char ch){
        return (ch == 'B' ? 'W' : 'B');
    }
    bool f(vector<vector<char>>& board, vector<int> dir, int rMove, int cMove, char color){
        int x = rMove, y = cMove;
        int xx = dir[0], yy = dir[1];
        
        x += xx;
        y += yy;
        if(isValid(x,y) && board[x][y] != iv(color)){
            return false;
        }
        
        while(isValid(x, y)){
            if(board[x][y] == color) return true;
            if(board[x][y] == '.') return false;
            x += xx;
            y += yy;
        }
        return false;
    }
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        vector<vector<int>> dir = {{1,0},{1,1},{1,-1},{-1,0},{-1,1},{-1,-1},{0,1},{0,-1}};
        for(int i=0; i<8; ++i){
            if(f(board, dir[i], rMove, cMove, color)) return true;
        }
        return false;
    }
};

// Time complx: O(8*8) = O(1) in this case otherwise O(8*n) = O(n)
// Space complx: O(1) except the array