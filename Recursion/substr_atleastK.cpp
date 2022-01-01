
// prob link: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

class Solution {
public:
    int longestSubstring(string s, int k) {
		int fq[26];

		int uqElm = 0;
		for(char ch : s){
			if(fq[ch - 'a'] == 0){
				uqElm++;
				fq[ch - 'a'] = 1;
			}
		}
		int ans = 0;
		memset(fq, 0, sizeof(fq));
		for(int uqNum = 1; uqNum <= uqElm; uqNum++){
			memset(fq, 0, sizeof(fq));
			int l = 0, r = 0, num = 0, kCount = 0;
			while(r < s.size()){
				if(num <= uqNum){
					if(fq[s[r] - 'a'] == 0) num++;
					fq[s[r] - 'a']++;
					if(fq[s[r] - 'a'] == k) kCount++;
					r++;
				}
				else{
                    if(fq[s[r] - 'a'] == k) kCount--;
					fq[s[l] - 'a']--;
					if(fq[s[r] - 'a'] == 0) num--;
					l++;
				}
				if(kCount == num && num == uqNum){
					ans = max(r-l,ans);
				}	
			}
		}
		return ans;
    } 

};



// this is sliding window or two pointer approach
// Time complx: O(uqNum*n) = O(26*n) = O(n) 
// Space complx: O(1)
















