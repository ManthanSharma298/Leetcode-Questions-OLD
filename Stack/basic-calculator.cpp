
// prob link: https://leetcode.com/problems/basic-calculator/

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int sign = 1, sm = 0, val = 0;
        for(char ch: s){
            if((ch-'0') >= 0 && (ch-'0') <= 9){
                val = val*10 + (ch-'0');
            }
            else if(ch == '('){
                st.push(sm);
                st.push(sign);
                val = 0;
                sign = 1;
                sm = 0;
            }
            else if(ch == ')'){
                sm += sign*val;
                sm = sm*st.top();   
                st.pop();
                
                sm += st.top();
                st.pop();
                
                val = 0;
                sign = 1;
            }
            else if(ch == '+'){
                sm += sign*val;
                val = 0;
                sign = 1;
            }
            else if(ch == '-'){
                sm += sign*val;
                val = 0;
                sign = -1;
            }
        }
        if(val != 0) sm += sign*val;
        return sm;
    }
};

// Time complx: O(n)
// Space complx: O(n)