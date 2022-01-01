// prob link: https://leetcode.com/problems/next-greater-element-ii/


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> s;
        for(int i=2*n-1; i>=0; --i){
            while(!s.empty()){
                if(s.top() <= nums[i%n]) s.pop();
                else{
                    if(i>=0 && i<n){
                        res[i] = s.top();
                    }
                    break;
                }
            }
            if(s.empty() && i>=0 && i<n){
                res[i] = -1;
            }
            s.push(nums[i%n]);
        }
        return res;
    }
};
// Time complx: O(2*n + 2*n) = O(n)
// Space complx: O(2*n) = O(n)