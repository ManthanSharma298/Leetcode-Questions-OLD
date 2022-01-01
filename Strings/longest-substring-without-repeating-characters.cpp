
// prob link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> find;
        int l = 0, r = 0, total = 0;
        while(l <= r && r < s.size()){
            if(!find[s[r]]){
                find[s[r]]++;
                r++;
            }
            else{
                while(find[s[r]]){
                    find[s[l]]--;
                    l++;
                }
            }
            total = max(total, r-l);
        }
        return total;
    }
};

// Time complx: O(s.length)
// Space complx: O(s.length)


// Done Again By Me
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l=0, r=0, res=0, n = s.length();
        while(r<n && l<=r){
            while(mp[s[r]] > 0 && l <= r){
                mp[s[l++]]--;
            }
            mp[s[r]]++;
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};

// Time complx: O(s.length)
// Space complx: O(s.length)
