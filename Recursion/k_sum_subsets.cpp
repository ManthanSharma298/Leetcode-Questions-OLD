
// prob link: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

// Method - 1
class Solution {
public:
    
    bool partition(int idx, vector<int>&nums, vector<bool>&vis, int k, int currSum, int reqSum){
        
        // if k-1 subsets are formed then only one left which have reqSum
        if(k == 1)
            return true;
        
        if(currSum == reqSum)
            return partition(0, nums, vis, k-1, 0, reqSum);
            
        for(int i=idx; i<nums.size();++i){
            if(!vis[i]){
                vis[i] = true;
                if(partition(idx + 1, nums, vis, k, currSum + nums[i], reqSum))
                    return true;
                vis[i] = false;		// Backtrack
            }
        }
        return false;
        
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int summ = 0;
        for(int elm : nums){
            summ += elm;
        }
        if(k <= 0 || summ % k != 0) return false;
        
        vector<bool>vis(nums.size(), false);
        return partition(0, nums, vis, k, 0, summ/k);
    }
};



// Method - 2 (little bit optimization taking array for storage)
class Solution {
public:
    
    bool partition(int idx, int sidx, vector<int>&nums, vector<bool>&vis, vector<int>&subsetSum, int k, int reqSum){
        if(subsetSum[sidx] == reqSum){
            if(sidx == k-2)     // k-1 subsets are formed then no need to go further
                return true;
            
            return partition(0, sidx+1, nums, vis, subsetSum, k, reqSum);
        } 
            
        for(int i=idx; i<nums.size();++i){
            
            if(vis[i]) continue;
            int newSum = subsetSum[sidx] + nums[i];
            
            if(newSum <= reqSum){       // we need to take this element
                vis[i] = true;
                subsetSum[sidx] = newSum;
                
                bool temp = partition(i + 1, sidx, nums, vis, subsetSum, k, reqSum);
                
                //Backtrack
                vis[i] = false;
                subsetSum[sidx] -= nums[i];
                
                if(temp)
                    return true;
            }
        }
        return false;
        
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k == 1) return true;
        
        int summ = 0;
        for(int elm : nums){
            summ += elm;
        }
        
        if(nums.size() < k || k <= 0 || summ % k != 0) return false;
        
        vector<bool>vis(nums.size(), false);
        vector<int>subsetSum(k, 0);
        
        vis[0] = true;
        subsetSum[0] = nums[0];
        
        return partition(0, 0, nums, vis, subsetSum, k, summ/k);
    }
};







