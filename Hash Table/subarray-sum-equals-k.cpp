// prob link: https://leetcode.com/problems/subarray-sum-equals-k/

// Brute force -> O(n^2)

// Optimize
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sm = 0, res = 0;
        for(int num: nums){
            sm += num;
            if(mp.count(sm-k)){
                res += mp[sm-k];
            }
            mp[sm]++;
        }
        return res;
    }
};
// Time complx: O(n)
// Space complx: O(n)