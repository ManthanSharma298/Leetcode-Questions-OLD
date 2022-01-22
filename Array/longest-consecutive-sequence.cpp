// prob link: https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        int mxLen = 0, int len;
        for(int elm: nums){
            s.insert(elm);
        }
        for(int elm: nums){
            if(!s.count(elm-1)){
                len = 0;
                while(s.count(elm)){
                    len++;
                    elm++;
                }
                mxLen = max(mxLen, len);
            }
        }
        return mxLen;
    }
};

// Time complx: O(N)
// Space complx: O(N)


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt=1;
        int res = 0;
        for(int i=1; i<nums.size(); ++i){
            if(nums[i] == nums[i-1]+1){
                cnt++;
            }
            else if(nums[i] == nums[i-1]){
                continue;
            }
            else{
                res = max(res, cnt);
                cnt=1;
            }
        }
        if(nums.size() > 0) res = max(res, cnt);
        
        return res;
    }
};

// Time complx: O(N*logN)
// Space complx: O(1)


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int elm: nums){
            s.insert(elm);
        }
        
        int res = 0;
        int cnt=1;
        for(int num: nums){
            if(!s.count(num+1)){
                int v=1;
                while(s.count(num-v)){
                    cnt++;
                    v++;
                }
                res = max(res, cnt);
                cnt=1;
            }
            
        }
        
        return res;
    }
};
// Time complx: O(N)
// Space complx: O(N)
// Same as the first one but done by me