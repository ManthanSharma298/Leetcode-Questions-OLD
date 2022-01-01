
// prob link: https://leetcode.com/problems/minimum-cost-for-tickets/


class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[366];
        unordered_set<int>st;
        dp[0] = 0;
        for(int elm: days){
            st.insert(elm);
        }
        for(int i=1; i<=365; i++){

            // Not Travelling on ith day
            if(!st.count(i)){
                dp[i] = dp[i-1];
            }
            // Travelling on ith day
            else{
                int one, week, month;

                one = (i > 1) ? dp[i-1] + costs[0] : costs[0];
                week = (i > 7) ? dp[i-7] + costs[1] : costs[1];
                month = (i > 30) ? dp[i-30] + costs[2] : costs[2];

                dp[i] = min({one, week, month});
            }
        }
        return dp[365];
    }
};



// Time Complexity: O(N), where N is the number of calendar days
// Space Complexity: O(N) for the optimized solution. Stricter, it's a maximum duration among all pass types


// Optimized Solution
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[31];
        unordered_set<int>st;
        for(int elm: days){
            st.insert(elm);
        }
        dp[0] = 0;
        for(int i=1; i<=365; i++){
            // Not Travelling on ith day
            if(!st.count(i)){
                dp[i%31] = dp[(i-1)%31];
            }
            // Travelling on ith day
            else{
                int one, week, month;
            
                one = (i > 1) ? dp[(i-1)%31] + costs[0] : costs[0];
                week = (i > 7) ? dp[(i-7)%31] + costs[1] : costs[1];
                month = (i > 30) ? dp[(i-30)%31] + costs[2] : costs[2];
            
                dp[i%31] = min({one, week, month});
            }
        }
        return dp[365%31];
    }
};

// Time Complexity: O(N), where N is the number of calendar days
// Space Complexity: O(31) for the optimized solution. Stricter, it's a maximum duration among all pass types




