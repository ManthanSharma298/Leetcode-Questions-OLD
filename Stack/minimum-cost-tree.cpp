
// prob link: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int cost = 0;
        int n = arr.size();
        vector<int>sk;
        sk.push_back(100);
        for(int elm : arr){
            while(sk.back() <= elm){
                int num = sk.back();
                sk.pop_back();
                cost += min(sk.back(), elm) * num;
            }
            sk.push_back(elm);
        }
        
        // Now remains a sorted array
        for(int i = sk.size()-1; i >= 2; i--){
            cost += sk[i]*sk[i-1];
        }
        return cost;
    }
};


//Time Complx: O(N)
//Space Complx: O(N)

// for explaination: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/discuss/339959/One-Pass-O(N)-Time-and-Space





