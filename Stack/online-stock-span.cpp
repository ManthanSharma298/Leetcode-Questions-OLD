// prob link: https://leetcode.com/problems/online-stock-span/


class StockSpanner {
    stack<pair<int,int>> s; // {index, price}
    int i;
public:
    StockSpanner() {
        i=0;
    }
    
    int next(int price) {
        int res;
        while(!s.empty() && price >= s.top().second){
            s.pop();
        }
        res = (s.empty() ? i+1 : i-s.top().first);
        s.push({i++, price});
        return res;
    }
};
// Time complx: O(n)
// Space complx: O(2*n) = O(n)