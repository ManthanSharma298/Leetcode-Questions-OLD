
// prob link: https://leetcode.com/problems/container-with-most-water/

// Intution -> we need to remove some unwanted steps taken in dual for loop 
// then we need to find the condition to increment or decrement th l and r pointer
// so the condition is simple i.e. based on the height 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), ans = 0;
        int l = 0, r=n-1;
        while(l<r){
            // we calculate ans in all cases but 
            // remove the unnecessary cases
            // eg ans = (j-i)*min(height[i],height[j])
            // then if we remove the max height element then it may 
            // possible that some element can form container with it 
            // which may be maximum one
            
            ans = max(ans, (r-l)*min(height[l],height[r]));
            if(height[l] < height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)

// let [3,........50..,9]   but we take ans = 3*len
// then if a greater number than 9 exists between them 
// then ans = min(3,50)*(len-k) = 3*(len-k)
// then also we don't loose the maximum one


