// prob link: https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        for(int num: nums){
            pq.push(num);
        }
        for(int i=0; i<k-1; ++i){
            pq.pop();
        }
        return pq.top();
    }
};
// Time complx: O(N + K*log(N))
// Space complx: O(N)

class Solution {
    int k;
public:
    int part(int l, int r, vector<int>& nums){
        int pvt = nums[r];
        int id = l;
        for(int i=l; i<r; ++i){
            if(nums[i] < pvt){
                swap(nums[id],nums[i]);
                id++;
            }
        }
        swap(nums[id], nums[r]);
        
        if(id == k) return nums[k];
        else if(id > k) return part(l, id-1, nums);
        else return part(id+1, r, nums);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        this->k = n-k;
        return part(0, n-1, nums);
    }
};
// Time complx-> n + n/2 + n/4 + .... = 2*n = O(n) {avg case}
//               n + n-1 + n-2 + .....  O(n^2) {worst case when pivot is smallest or greatest}
// Space complx: O(1)