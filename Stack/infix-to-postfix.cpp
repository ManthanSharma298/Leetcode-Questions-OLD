
// prob link: https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1#


bool p(char c1, char c2){
    if(c2 == '(') return false;
    if(c1 == '^') return false;
    if(c1 == '*' || c1 == '/'){
        if(c2 == '+' || c2 == '-') return false;
        return true;
    }
    else return true;
}
string infixToPostfix(string s){
    string res;
    stack<char> st;
    for(char ch: s){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            res += ch;
        }
        else if(ch == '('){
            st.push(ch);
        }
        else if(ch == ')'){
            while(st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && p(ch,st.top())){
                res += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}