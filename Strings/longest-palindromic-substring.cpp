
// prob link: https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int size = 0,L,R;
        // for odd length
        for(int i=0; i<s.size(); ++i){
            int k=0;
            while(i-k >= 0 && i+k <s.size() && s[i-k] == s[i+k]){
                if(size < 2*k+1){
                    size = 2*k+1;
                    L = i-k;
                    R = i+k;
                }
                k++;
            }
        }
        // for even length
        for(int i=0; i<s.size(); ++i){
            int k=0;
            while(i-k >= 0 && i+k+1 <s.size() && s[i-k] == s[i+k+1]){
                if(size < 2*k+2){
                    size = 2*k+2;
                    L = i-k;
                    R = i+k+1;
                }
                k++;
            }
        }
        string res = "";
        for(int i=L; i<=R; ++i){
            res += s[i];
        }
        return res;
    }
};

// Time complx: O(N*N)
// Space complx: O(1)