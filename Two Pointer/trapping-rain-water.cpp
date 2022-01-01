// prob link: https://leetcode.com/problems/trapping-rain-water/


class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        if(n <= 2) return res;
        vector<int> lf(n),rt(n);
        lf[0] = height[0];
        rt[n-1] = height[n-1];
        for(int i=1; i<n; ++i){
            lf[i] = max(lf[i-1],height[i]);
        }
        for(int i=n-2; i>=0; --i){
            rt[i] = max(rt[i+1],height[i]);
        }
        for(int i=1; i<n-1; ++i){
            res += min(lf[i],rt[i])-height[i];
        }
        return res;
    }
};
// Time complx: O(n)+O(n)+o(n) = O(n)
// Space complx: O(n)+O(n) = O(n)


class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        if(n <= 2) return res;
        
        int lmax = height[0], rmax = height[n-1];
        int l=0, r=n-1;
        while(l < r){
            if(lmax < rmax){
                res += lmax-height[l];
                l++;
                lmax = max(lmax, height[l]);
            }
            else{
                res += rmax-height[r];
                r--;
                rmax = max(rmax, height[r]);
            }
        }
        return res;
    }
};
// Time complx: O(n)
// Space complx: O(1)