
// prob link: https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(char ch: s){
            if(ch == '(' || ch == '{' || ch == '[')
                stk.push(ch);
            
            else{
                if(stk.empty()) return false;
                else if(ch == ')'){
                    if(stk.top() == '('){
                        stk.pop();
                    }
                    else{
                        return false;
                    }
                }
                else if(ch == '}'){
                    if(stk.top() == '{'){
                        stk.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    if(stk.top() == '['){
                        stk.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        if(stk.empty()) return true;
        return false;
    }
};

// Time complx: O(s.length)
// space complx: O(s.length)