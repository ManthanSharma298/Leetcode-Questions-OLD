
// prob link: https://leetcode.com/problems/find-the-duplicate-number/

// Methods

// 1: Sorting
// 2: Using HashTable or Set

// 3: Negative Marking
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int elm: nums){
        	if(nums[abs(elm)-1] < 0){
        		return abs(elm);
        	}
        	nums[abs(elm)-1] *= -1;
        }
        // will never reach here
        return 0;
    }
};

// Time complx: O(N)
// Space complx: O(1)
// But it modifies the array 

// 4: Binary Search
// Prefered Template
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l=1, r=n, m;
        while(l+1 < r){
            int m = l + (r-l)/2;
            int cnt = 0;
            for(int num: nums){
                if(num < m) cnt++;
            }
            if(cnt >= m) r=m;
            else l=m;
        }
        int cnt=0;
        for(int num: nums){
            if(num == l) cnt++;
        }
        if(cnt >= 2) return l;
        return r;
    }
};

// Little bit clean code
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l=1, r=n+1, m;  // make r invalid and finally we check l first
        while(l+1 < r){
            int m = l + (r-l)/2;
            int cnt = 0;
            for(int num: nums){
                if(num < m) cnt++;
            }
            if(cnt >= m) r=m;
            else l=m;
        }
        return l;
    }
};

// Time complx: O(N*logN)
// Space complx: O(1)

// 5: Floyd's slow and fast pointer
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do{
            fast = nums[nums[fast]];
            slow = nums[slow];

        }while(slow != fast);
        
        fast = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

// Time complx: O(N)
// Space complx: O(1)
// But very hard to think

