
// prob link: https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        double res=1;
        long long p = n;
        if(p < 0) p = -p;
        while(p){
            if(p%2 == 1){   // odd
                res = res*x;
                p -= 1;
            }
            else{   // even
                x = x*x;
                p /= 2;
            }
        }
        if(n < 0) return (double)1/res;
        return res;
    }
};

// Time complx: O(logn)
// Space complx: O(1)