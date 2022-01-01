
// prob link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// Hash Table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); ++i){
            auto it = mp.find(target-nums[i]);
            if(it != mp.end()){
                return {it->second+1, i+1};
            }
            mp.insert({nums[i], i});
        }
        return {};
    }
};
// Time complx: O(N)
// Space complx: O(N)


// Binary Search
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; ++i){
            int l=0, r=n-1, m;
            while(l + 1 < r){
                m = l + (r-l)/2;
                if(nums[m] < target-nums[i]){
                    l = m;
                }else{
                    r = m;
                }
            }
            if(l != i && nums[l] == target-nums[i]) return {min(l,i)+1, max(l,i)+1};
            if(r != i && nums[r] == target-nums[i]) return {min(r,i)+1, max(r,i)+1};
        }
        return {};
    }
};
// Time complx: O(N*logN)
// Space complx: O(1)


// Two pointer
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, r=n-1;
        while(l < r){
            if(nums[l] + nums[r] == target){
                return {l+1, r+1};
            }else if(nums[l] + nums[r] < target){
                l++;
            }else{
                r--;
            }
        }
        return {};
    }
};
// Time complx: O(N)
// Space complx: O(1)