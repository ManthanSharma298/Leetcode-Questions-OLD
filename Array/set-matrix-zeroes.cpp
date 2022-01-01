
// prob link: https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        stack<pair<int,int>> st;    // can also use vector
        for(int i=0; i<m; ++i){
            for(int j=0; j<n;++j){
                if(matrix[i][j] == 0) st.push({i,j});
            }
        }
        
        while(!st.empty()){
            auto p=st.top();
            int x=p.first, y=p.second;
            for(int i=0; i<n; ++i){
                matrix[x][i] = 0;
            }
            for(int i=0; i<m; ++i){
                matrix[i][y] = 0;
            }
            st.pop();
        }
    }
};

// Time complx: O(n*m) + O(n*m*(n+m)) = O(n*m*(n+m))
// Space complx: O(n*m)
// But this is NOT IN-PLACE



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        bool flag = false;
        for(int j=0; j<n; ++j){
            if(matrix[0][j] == 0){
                flag = true;
                break;
            }
        }
        for(int j=0; j<n; ++j){
            for(int i=1; i<m; ++i){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(matrix[i][j] == 0){
                    for(int k=0; k<n; ++k){
                        matrix[i][k] = 0;
                    }
                    break;
                }
            }
        }
        for(int j=0; j<n; ++j){
            if(matrix[0][j] == 0){
                for(int i=0; i<m; ++i){
                    matrix[i][j] = 0;
                }
            }
        }
        // if first row containes a zero
        if(flag){
            for(int j=0; j<n; ++j){
                matrix[0][j] = 0;
            }
        }
        
    }
};

// Time complx: O(n) + O(n*m) + O(n*m*n) + O(n*m) + O(n) = O(n*m*n)
// Space complx: O(1)