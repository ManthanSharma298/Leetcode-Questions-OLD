
// prob link: https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    vector<vector<string>> res;
    bool isPalin(string s, int l, int r){
        while(l <= r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
    void rec(int idx, vector<string>& v, string s){
        if(idx >= s.size()){
            res.push_back(v);
            return;
        }
        for(int i=idx; i<s.length(); ++i){
            if(isPalin(s,idx,i)){
                v.push_back(s.substr(idx,i-idx+1));
                rec(i+1,v,s);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        rec(0,v,s);
        return res;
    }
};

// Time complx: O(k*n*2^n)
// Space complx: O(2^n) + O(n) = O(2^n)