
// prob link: https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int findMax(vector<int>& find){
        int mx=0;
        for(int elm: find){
            mx = max(mx, elm);
        }
        return mx;
    }
    int characterReplacement(string s, int k) {
        int mx, total = 0;
        vector<int> find(26, 0);
        int l=0, r=0;
        while(r < s.size()){
            find[s[r]-'A']++;
            r++;

            mx = findMax(find);
            while(r-l-mx > k){
                find[s[l]-'A']--;
                l++;
                
                mx = findMax(find);
            }
            // len-mx <= k
            total = max(total, r-l);
        }
        return total;
    }
};

// Time complx: O(26*s.length)
// Space complx: O(26)