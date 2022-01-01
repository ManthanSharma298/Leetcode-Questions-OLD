
// prob link: https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/

class Solution {
    const static int N = 45;
    long long dp[N];
public:
    int rec(int num){
        if(num == 0) return 0;
        int idx;
        for(int i=1; i<N; ++i){
            if(num < dp[i]){
                idx = i;
                break;
            }
        }
        idx--;
        return rec(num - dp[idx]) + 1;
    }
    int findMinFibonacciNumbers(int k) {
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3; i<N; ++i){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return rec(k);
    }
};

// Time complx: O(45*45) or O(logk*logk)
// Space complx: O(45) or O(logk)
