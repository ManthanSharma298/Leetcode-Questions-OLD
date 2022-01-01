// prob link: https://leetcode.com/problems/min-stack/


class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int,int>> s; 
    int mn;
    MinStack() {
        mn = INT_MAX;
    }
    
    void push(int val) {
        mn = min(mn, val);
        s.push({val, mn});
    }
    
    void pop() {
        s.pop();
        mn = (s.empty() ? INT_MAX : s.top().second);    // important step
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};
// Time complx: O(1)
// Space complx: O(2*n) = O(n)