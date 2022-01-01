// prob link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/


class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size();
        int p = part.size();
        int i=0;
        while(i+p-1 < s.size()){
            if(s.substr(i,p) == part){
                string t = s.substr(0,i) + s.substr(i+p,n-i-p);
                s = t;
                // cout<<t<<" ";
                i=0;
                continue;
            }
            i++;
        }
        return s;
    }
};
// Time complx: O(n*n*m)
// Space complx: O(n)


// use string as stack
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size();
        int p = part.size();
        string res;
        int i = 0;
        while(i<n){
            res.push_back(s[i++]);
            if(res.size() >= p && res.substr(res.size()-p, p) == part){
                for(int j=0; j<p; ++j){
                    res.pop_back();
                }
            }
        }
        
        return res;
    }
};
// Time complx: O(n*m)
// Space complx: O(n)


// To optimize more you need KMP algo -> O(n+m)