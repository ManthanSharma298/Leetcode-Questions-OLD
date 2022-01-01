
// prob link: https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int>count(26, 0);
        for(char ch: s){
            count[ch-'a']++;
        }
        for(char ch: t){
            count[ch-'a']--;
        }
        for(int elm: count){
            if(elm != 0) return false;
        }
        return true;
    }
};

// Time complx: O(N)
// Scape complexity: O(26) = O(1)