
// prob link: https://leetcode.com/problems/sort-colors/

// Two Pass
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0=0, c1=0, c2=0;
        for(int elm: nums){
            if(elm == 0) c0++;
            else if(elm == 1) c1++;
            else c2++;
        }
        int i=0;
        while(c0--){
            nums[i] = 0;
            i++;
        }
        while(c1--){
            nums[i] = 1;
            i++;
        }
        while(c2--){
            nums[i] = 2;
            i++;
        }
    }
};

// Time complx: O(2*N) = O(N)
// Space complx: O(1);


// One Pass
class Solution {
public:
    void swp(int i, int j, vector<int>& a){
        int temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l=0, m=0, r=n-1;
        
        while(l <= m && m <= r){    // while(m <= r) is also true as l <= m is always valid
            if(nums[m] == 0){
                swp(m++, l++, nums);
            }
            else if(nums[m] == 2){
                swp(m, r--, nums);
            }
            else{
                m++;
            }
        }
    }
};

// Time complx: O(N)
// Space complx: O(1);
