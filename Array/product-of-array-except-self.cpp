
// prob link: https://leetcode.com/problems/product-of-array-except-self/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n, 1);
        vector<int>post(n, 1);
        // fill pre
        pre[0] = nums[0];
        for(int i=1; i<n; ++i){
            pre[i] = nums[i]*pre[i-1];
        }
        // fill post
        post[n-1] = nums[n-1];
        for(int i=n-2; i>=0; --i){
            post[i] = nums[i]*post[i+1];
        }
        // fill nums
        for(int i=0; i<n; ++i){
            if(i == 0){
                nums[i] = post[i+1];
            }else if(i == n-1){
                nums[i] = pre[i-1];
            }else{
                nums[i] = post[i+1]*pre[i-1];
            }    
        }
        return nums;
    }
};

// Time complx: O(N)
// Space complx: O(N) need to be optimized


// The output array does not count as extra space for space complexity analysis as given in question
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int right = 1;
        vector<int>res(n, 1);
        
        res[0] = nums[0];
        for(int i=1; i<n-1; ++i){
            res[i] = res[i-1]*nums[i];
        }
        
        for(int i=n-1; i>=1; --i){
            res[i] = res[i-1]*right;
            right *= nums[i];
        }
        res[0] = right;
        return res;
    }
};

// Time complx: O(N)
// Space complx: O(1)