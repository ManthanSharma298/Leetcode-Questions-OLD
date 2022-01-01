
// prob link: https://leetcode.com/problems/palindromic-substrings/


// DP solution
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), count=0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int diag=0; diag<n; ++diag){
            for(int i=0, j=diag; i<n && j<n; i++, j++){
                if(diag == 0){
                    dp[i][j] = 1;
                    count++;
                }
                else if(diag == 1){
                    if(s[i] == s[j]){
                        dp[i][j] = 1;
                        count++;
                    }
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1]){
                        dp[i][j] = 1;
                        count++;
                    }
                }
            }
        }
        // for(int i=0; i<n; ++i){
        //     for(int j=0; j<n; ++j){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return count;
    }
};

// S = s.length
// Time complx: O(S*S)
// Space complx: O(S*S)


// two pointer
class Solution {
public:
    void palindrome(int l, int r, int &count, string s){
        while(l >= 0 && r <= s.size() && s[l] == s[r]){
            count++;
            l--;
            r++;
        }
    }
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0; i<s.size(); ++i){
            palindrome(i,i,count,s);      //odd length
            palindrome(i,i+1,count,s);    //even length
        }
        return count;
    }
};

// S = s.length
// Time complx: O(S*S)
// Space complx: O(1)