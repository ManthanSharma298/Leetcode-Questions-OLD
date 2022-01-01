// prob link: https://leetcode.com/problems/string-to-integer-atoi/


class Solution {
public:
    int myAtoi(string s) {
        long long res = 0;
        int i = 0, sign = 1, n = s.size();
        if(s.size() == 0) return res;
        // white spaces
        while(i<n && s[i] == ' '){
            i++;
        }
        // - or +
        if(i<n){
            if(s[i] == '-'){
                sign = -1;
                i++;
            }
            else if(s[i] == '+'){
                sign = 1;
                i++;
            }
            
        }
        // counting digits
        while(s[i]-'0' >= 0 && s[i]-'0' <= 9){
            if(res > (long long)3e9) break;
            res *= 10;
            res += s[i]-'0';
            i++;
        }
        res = sign*res;
        if(res > INT_MAX) res = INT_MAX;
        if(res < INT_MIN) res = INT_MIN;
        
        return res;
    }
};
// Time complx: O(n)
// Space complx: O(1)