
// rpb link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

// DP solution
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int>buy(n);
        vector<int>sell(n);
        buy[0] = prices[0];
        sell[0] = 0;
        for(int i=1; i<n; i++){
            buy[i] = min(buy[i-1], prices[i] - sell[i-1]);
            // if we have money from selling stock at i-1
            // then prices for buying a new stock is prices[i] - sell[i-1]
            // ACTUALLY WE CALCULATE THE MIN COST OF BUYING A STOCK
            // we can write as min(buy[i-1], prices[i] - sell[i-1])
            sell[i] = max(sell[i-1], prices[i] - buy[i-1] - fee);
        }
        return sell[n-1];
    }
};  

// Time Complexity : O(n)
// Space Complexity : O(n)

// Optimized space solution
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(), buy = prices[0], sell = 0;
        for(int i=1; i<n; i++){
            buy = min(buy, prices[i] - sell);
            // if we have money from selling stock at i-1
            // then prices for buying a new stock is prices[i] - sell[i-1]
            // ACTUALLY WE CALCULATE THE MIN COST OF BUYING A STOCK
            // we can write as min(buy[i-1], prices[i] - sell[i-1])
            sell = max(sell, prices[i] - buy - fee);
        }
        return sell;
    }
};  

// Time Complexity : O(n)
// Space Complexity : O(1)
