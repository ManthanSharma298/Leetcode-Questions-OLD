
// prob link: https://leetcode.com/problems/minimum-window-substring/


// Sliding Window (Brute force) -> TLE
class Solution {
public:
    bool isValid(unordered_map<char, int> mp){
        for(auto elm: mp){
            if(elm.second > 0) return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(auto elm: t){
            mp[elm]++;
        }
        unordered_map<char, int> find;
        for(auto elm: t){
            find[elm]++;
        }
        
        int len=1e6, l=0, r=0, L,R;
        while(l <= r && r < s.size()){
            while(!isValid(mp) && r < s.size()){
                if(find[s[r]] > 0){
                    mp[s[r]]--;
                }
                r++;
            }
            
            while(isValid(mp) && l <= r){
                if(r-l < len){
                    len = r-l;
                    L=l;
                    R=r;
                }
                if(find[s[l]] > 0){
                    mp[s[l]]++;
                }
                l++;
            }
            
        }
        string res = "";
        for(int i=L; i<R; ++i){
            res += s[i];
        }
        return res;
    }
};

// T = t.length
// S = s.length
// Time complx: O(T + S*T + S) = O(S*T)
// Space complx: O(T)


// Optimised Sliding Window 
class Solution {
public:
    string minWindow(string s, string t) {
        int len=1e6, l=0, r=0, L, R, size = t.size();
        unordered_map<char, int> find;
        for(auto elm: t){
            find[elm]++;
        }
        
        while(r < s.size()){
            // while not valid
            if(find[s[r]] > 0){
                size--;
            }
            find[s[r]]--;
            r++;
            // till valid
            while(size == 0 && l <= r){
                
                if(r-l < len){
                    len = r-l;
                    L=l;
                    R=r;
                }
                // cout<<L<<" "<<R<<"\n";
                find[s[l]]++;
                if(find[s[l]] > 0) size++;
                l++;
                
            }
            
        }
        string res="";
        for(int i=L; i<R; ++i){
            res += s[i];
        }
        return res;
    }
};

// T = t.length
// S = s.length
// Time complx: O(T + S*1 + S) = O(S)
// Space complx: O(T)