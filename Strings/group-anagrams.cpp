
// prob link: https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto elm: strs){
            string temp = elm;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(elm);
        }
        vector<vector<string>> res;
        for(auto elm: mp){
            res.push_back(elm.second);
        }
        
        return res;
    }
};

// S = strs.length
// s = strs[i].length
// Time complx: O(S*s*logs + S)
// Space complx: O(S+s)


class Solution {
public:
    string countSort(string s){
        int occur[26] = {0};
        string res = "";
        for(auto elm: s){
            occur[elm-'a']++;
        }
        for(int i=0; i<26; i++){
            // while(occur[i]--){
            //     res += char(i+'a');
            // }
            res += string(occur[i], i+'a');
        }
        return res;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto elm: strs){
            mp[countSort(elm)].push_back(elm);
        }
        vector<vector<string>> res;
        for(auto elm: mp){
            res.push_back(elm.second);
        }
        
        return res;
    }
};

// S = strs.length
// s = strs[i].length
// Time complx: O(S*s + S)
// Space complx: O(S+s) -> like in graph O(V + E)