
// prob likn: https://leetcode.com/problems/word-break/


// considering all cases
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int sLen = s.length(), wLen = wordDict.size();
        vector<int>dp(sLen,false);
        for(int i=sLen-1; i>=0; --i){
            for(int j=1; j<=sLen-i; ++j){
                for(auto w: wordDict){
                    if(j == sLen-i && s.substr(i,j) == w){
                        dp[i] = true;
                        break;
                    }
                    else if(i+j < sLen && s.substr(i,j) == w && dp[i+j] == true){
                        dp[i] = true;
                        break;
                    }   
                }
                if(dp[i]) break;
            }
        }
        return dp[0];
    }
};

// Time complx: O(sLen*sLen*wLen)
// Space complx: O(sLen)



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int sLen = s.length();
        vector<int>dp(sLen,false);
        for(int i=sLen-1; i>=0; --i){
            for(auto word: wordDict){
                if(word.size() == sLen-i && s.substr(i, word.size()) == word){
                    dp[i] = true;
                    break;
                }
                else if(i + word.size() < sLen && s.substr(i, word.size()) == word && dp[i + word.size()]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};

// Time complx: O(sLen*wLen*wordDict[i])
// Space complx: O(sLen)
