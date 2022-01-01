// prob link: https://leetcode.com/problems/largest-rectangle-in-histogram/


// two iteration
class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        vector<int> lf(n),rt(n);
        stack<int> s;
        
        // lf 
        for(int i=0; i<n; ++i){
            while(!s.empty()){
                if(a[i] > a[s.top()]) break;
                s.pop();
            }
            lf[i] = (s.empty() ? 0 : s.top()+1);
            s.push(i);
        }
        
        //empty stack
        while(!s.empty()) s.pop();
        
        // rt
        for(int i=n-1; i>=0; --i){
            while(!s.empty()){
                if(a[i] > a[s.top()]) break;
                s.pop();
            }
            rt[i] = (s.empty() ? n-1 : s.top()-1);
            s.push(i);
        }
        int res = 0, area;
        for(int i=0; i<n; ++i){
            area = (i-lf[i] + rt[i]-i + 1)*a[i];
            res = max(res, area);
        }
        
        return res;
    }
};
// Time complx: O(n+n) = o(n)
// Space complx: O(n+n+n) = O(n) one stack and two arrays


// single iteration
class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size(), res=0;
        stack<int> s;
        for(int i=0; i<=n; ++i){
            while(!s.empty() && (i == n || a[i] <= a[s.top()]) ){
                int tp = s.top();
                s.pop();   
                int rt = i;
                int lf = (s.empty() ? -1 : s.top());
                res = max(res, (rt-lf-1)*a[tp]);
            }
            s.push(i);
        }
        return res;
    }
};
// Time complx: O(n+n) = O(n)
// Space complx: O(n)