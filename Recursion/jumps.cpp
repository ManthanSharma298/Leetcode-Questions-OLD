
// prob link: https://leetcode.com/problems/jump-game-iii/

class Solution {
    set<int>st;
public:
    bool canReach(vector<int>& arr, int idx) {
        
        if(st.count(idx) || idx < 0 || idx >= arr.size()) return false;
        if(arr[idx] == 0) return true;
        
        st.insert(idx); // important when to return false and indx is not out of bound
        return (canReach(arr, idx + arr[idx]) || canReach(arr, idx - arr[idx]));
    }
};


// Time complx: O(logn)
// Space complx: O(n)


// OPTIMIZATION
// to reduce space complx to O(1)
// we need to change arr[i] to -arr[i] when reach an index i
// and apply condition if arr[i] < 0 return false
