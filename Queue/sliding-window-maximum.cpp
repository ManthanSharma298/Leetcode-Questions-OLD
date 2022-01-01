// prob link: https://leetcode.com/problems/sliding-window-maximum/


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n-k+1);
        deque<int> d;
        for(int i=0; i<n; ++i){
            if(!d.empty() && d.front() < i-k+1) d.pop_front();
            while(!d.empty() && nums[i] > nums[d.back()]){
                d.pop_back();
            }
            d.push_back(i);
            if(i>=k-1){
                res[i-k+1] = nums[d.front()];
            }
        }
        return res;
    }
};
// Time complx: O(n+n) = O(n)
// Space complx: O(n)