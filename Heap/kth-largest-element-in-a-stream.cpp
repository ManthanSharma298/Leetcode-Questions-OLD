// prob link: https://leetcode.com/problems/kth-largest-element-in-a-stream/


class KthLargest {
    priority_queue<int,vector<int>,greater<int>> pq;    // min heap
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num: nums){
            pq.push(num);
        }
        while(pq.size() > k){
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > k){
            pq.pop();
        }
        return pq.top();
    }
};

// Time complx: O(N*log(N)) + M*O(log(k))   M is number of calls
// Space complx: O(N)