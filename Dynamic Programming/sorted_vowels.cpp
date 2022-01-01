
// prob link: https://leetcode.com/problems/count-sorted-vowel-strings/submissions/

// Method-1 
class Solution {
public:
   
    int countVowelStrings(int n) {
        vector<vector<int>>	dp(n+1, vector<int>(6, 0));
		for(int j=1 ;j<=5; ++j){
			dp[0][j] = 1;
		}
		for(int i=1; i<=n; ++i){
			for(int j=5; j>=1; --j){
				if(j == 5){
					dp[i][j] = 1;
                    continue;
				}
				dp[i][j] = dp[i][j+1] + dp[i-1][j];
			}
		}
		return dp[n][1];
    }
};

// dp approach with 2d array
// Time complx: O(nk)
// Space complx: O(nk)



// Method-2
class Solution {
public:
   
	int countVowelStrings(int n) {
		int dp[] = {1,1,1,1,1};	
		for(int nn=0; nn<n; ++nn){
			for(int j=3; j>=0; --j){
				dp[j] += dp[j+1];
			}
		}
		return dp[0];
	}
};

// dp approach with 1d array
// Time complx: O(nk)
// space complx: O(1)








