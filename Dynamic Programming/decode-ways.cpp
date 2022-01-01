
// prob link: https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int rec(int i, string s){
        int n = s.size();
        if(i == n) return 1;
        if(s[i] == '0') return 0;
        int res = rec(i+1, s);
        if(i+1<n){
            if(s[i] == '1' || (s[i] == '2' && s[i+1]>='0' && s[i+1]<='6')){
                res += rec(i+2, s);
            }
        }
        return res;
    }
    int numDecodings(string s) {
        return rec(0, s);
    }
};

class Solution {
public:
    int dp[105];
    int rec(int i, string s){
        int n = s.size();
        if(i == n) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        
        int res = rec(i+1, s);
        if(i+1<n){
            if(s[i] == '1' || (s[i] == '2' && s[i+1]>='0' && s[i+1]<='6')){
                res += rec(i+2, s);
            }
        }
        return dp[i] = res;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return rec(0, s);
    }
};

class Solution {
public:
    int dp[105];
    int numDecodings(string s) {
        int n = s.size();
        dp[n] = 1;
        for(int i=n-1; i>=0; --i){
            if(s[i] == '0'){
                dp[i] = 0;
                continue;
                // continue as I can't make 06 as a number
            }
            dp[i] = dp[i+1];
            if(i+1<n){
                if(s[i] == '1' || (s[i] == '2' && s[i+1]>='0' && s[i+1]<='6')){
                    dp[i] += dp[i+2];
                }
            }
        }
        return dp[0];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int nnxt,nxt,curr;
        nxt = 1;
        for(int i=n-1; i>=0; --i){
            curr = 0;
            if(s[i] == '0'){
                nnxt = nxt;
                nxt = 0;
                continue;
            }
            curr = nxt;
            if(i+1<n){
                if(s[i] == '1' || (s[i] == '2' && s[i+1]>='0' && s[i+1]<='6')){
                    curr += nnxt;
                }
            }
            int tmp = nxt;
            nxt = curr;
            nnxt = tmp;
        }
        return curr;
    }
};