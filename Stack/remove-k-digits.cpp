
// prob link: https://leetcode.com/problems/remove-k-digits/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char>s;
        int i=0;
        while(i<n){
            char top = s.top();
            while(!s.empty() && k > 0 && num[i]-'0' < top-'0'){
                s.pop();
                top = s.top();
                k--;
            }
            s.push(num[i]);
            i++;
        }
        while(k>0){
            s.pop();
            k--;
        }
        string res="";
        while(!s.empty()){
            res += s.top();
            s.pop();
        }
        for(int i=res.size()-1; i>=0; i--){
            if(res[i] == '0') res.pop_back();
            else break;
        }
        reverse(res.begin(), res.end());
        return (res == "" ? "0" : res);
    }
};

// Time complx: O(N)
// Space complx: O(N)
