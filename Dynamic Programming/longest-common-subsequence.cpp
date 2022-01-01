
// prob link: https://leetcode.com/problems/longest-common-subsequence/


// This is Top-Down Approach
int LongestCommonSubsequence(string r, string s, int indR, int indS){
    if(indR < 0 || indS < 0) return 0;

    if(r[indR] == s[indS]){
        return 1 + LongestCommonSubsequence(r, s, indR-1, indS-1);
    }
    else{
        return max(LongestCommonSubsequence(r, s, indR, indS-1), LongestCommonSubsequence(r, s, indR-1, indS));
    }
}

//Time Complx: 2^n


// rec + memo
// IMP: IT DOESN'T WORK WHEN WE USE rec(string s, string t, int i, int j)
// ONLY WORKS WHEN rec(string &s, string &t, int i, int j) PASSED BY REFERNCE
class Solution {
    int dp[1005][1005];
public:
    int rec(string &s, string &t, int i, int j){
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j]){
            return dp[i][j] = 1 + rec(s,t,i-1,j-1);
        }
        else{
            return dp[i][j] = max(rec(s,t,i-1,j), rec(s,t,i,j-1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return rec(text1, text2, text1.size()-1, text2.size()-1);
    }
};

// Optimisation:
//
class Solution {
    int dp[1000][1000];
public:
    int longestCommonSubsequence(string r, string s) {
        int indR = r.length(), indS = s.length();

        for(int i=1; i<=indR; ++i){
            for(int j=1; j<=indS; ++j){
                if(r[i-1] == s[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[indR][indS];
    }
};



// Time Complx: O(mn)
// Space Complx: O(mn)

