// prob link: https://leetcode.com/problems/reverse-words-in-a-string/


class Solution {
public:
    string reverseWords(string s) {
        string res;
        stack<string> st;
        int n = s.size();
        int i = 0;
        while(i<n){
            while(i<n && s[i] == ' ') i++;
            string t;
            while(i<n && s[i] != ' '){
                t += s[i++];
            }
            if(t.size() > 0) st.push(t);
        }
        while(st.size() > 1){
            res += st.top();
            st.pop();
            res += ' ';
        }
        res += st.top();
        
        return res;
    }
};
// Time complx: O(n+n) = O(n)
// Space complx: O(n)


class Solution {
public:
    string reverseWords(string s) {
        string res;
        int n = s.size();
        int i = 0;
        reverse(s.begin(), s.end());
        while(i<n){
            while(i<n && s[i] == ' ') i++;
            string t;
            while(i<n && s[i] != ' '){
                t += s[i++];
            }
            if(t.size() > 0){
                reverse(t.begin(),t.end());
                if(res.size() == 0){
                    res += t;
                }
                else{
                    res += ' ';
                    res += t;
                }
            }
        }
        return res;
    }
};
// Time complx: O(n)
// Space complx: O(1)