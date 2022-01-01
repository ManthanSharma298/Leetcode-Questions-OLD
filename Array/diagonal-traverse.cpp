// prob link: https://leetcode.com/problems/diagonal-traverse/


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res(m*n,0);
        int r=0, c=0, i=0;
        bool flg = true;
        while(r<m && c<n){
            // up
            if(flg){
                while(r-1>=0 && c+1 < n){
                    res[i++] = mat[r][c];
                    r--;
                    c++;
                }
                res[i++] = mat[r][c];
                if(c == n-1){
                    r++;
                }
                else{
                    c++;
                }
            }
            // down
            else{
                while(r+1<m && c-1>=0){
                    res[i++] = mat[r][c];
                    r++;
                    c--;
                }
                res[i++] = mat[r][c];
                if(r == m-1){
                    c++;
                }
                else{
                    r++;
                }
            }
            flg = !flg;
        }
        return res;
    }
};

// Time complx: O(m*n)
// Space complx: O(1) except the res array