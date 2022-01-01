
// prob link: https://leetcode.com/problems/generate-parentheses/


// backtrack solution
class Solution {
    vector<string>ans;
public:
    
    void rec(string String, int l, int r){
        if(l == 0 && r == 0){
            ans.push_back(String);
            return;
        }
        if(l < r){
            string temp = String;
            if(l >= 1){
                temp.push_back('(');
                rec(temp,l-1,r);
            }
            if(r >= 1){
                String.push_back(')');
                rec(String,l,r-1);
            }    
        }
        if(l == r){
            String.push_back('(');
            rec(String,l-1,r);
        }
    }
    vector<string> generateParenthesis(int n) {
        rec("",n,n);
        return ans;
    }
};

// Time Complexity : O(4^n/sqrt(n))
// Space Complexity : O(4^n/sqrt(n))
// (Calculation is beyound scope)

// https://leetcode.com/problems/generate-parentheses/solution/