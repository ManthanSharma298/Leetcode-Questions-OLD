// prob link: https://leetcode.com/problems/n-queens/


class Solution {
    vector<vector<string>> res;
public:
    bool isVal(int r, int c, vector<string>& s){
        int n = s.size();
        // row
        for(int j=0; j<n; ++j){
            if(s[r][j] == 'Q') return false;
        }
        // bottom-right
        int rr=r, cc=c;
        while(rr<n && cc<n){
            if(s[rr++][cc++] == 'Q') return false;
        }
        // top-left
        rr=r, cc=c;
        while(rr>=0 && cc>=0){
            if(s[rr--][cc--] == 'Q') return false;
        }
        // top-right
        rr=r, cc=c;
        while(rr>=0 && cc<n){
            if(s[rr--][cc++] == 'Q') return false;
        }
        // bottom-left
        rr=r, cc=c;
        while(rr<n && cc>=0){
            if(s[rr++][cc--] == 'Q') return false;
        }
        return true;
        
    }
    void rec(int c, vector<string>& s, int n){
        if(c == n){
            res.push_back(s);
            return;
        }
        for(int r=0; r<n; ++r){
            if(isVal(r,c,s)){
                s[r][c] = 'Q';
                rec(c+1, s, n);
                s[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> s(n, string(n, '.'));
        rec(0, s, n);
        return res;
    }
};
// Time complx: O(n^3)
// Space complx: O(1)


class Solution {
    vector<vector<string>> res;
    unordered_set<int> rw, dl, dr;
public:
    bool isVal(int r, int c){
        if(rw.count(r) || dl.count(r-c) || dr.count(r+c)) return false;
        return true;
        
    }
    void rec(int c, vector<string>& s, int n){
        if(c == n){
            res.push_back(s);
            return;
        }
        for(int r=0; r<n; ++r){
            if(isVal(r,c)){
                s[r][c] = 'Q';
                // fill sets
                rw.insert(r);
                dr.insert(r+c);
                dl.insert(r-c);
                rec(c+1, s, n);
                
                s[r][c] = '.';
                // remove
                rw.erase(rw.find(r));
                dr.erase(dr.find(r+c));
                dl.erase(dl.find(r-c));
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> s(n, string(n, '.'));
        rec(0, s, n);
        return res;
    }
};
// T(n) = n*T(n-1) + O(n^2) -> O(n!) approx
// Time complx: O(n!)