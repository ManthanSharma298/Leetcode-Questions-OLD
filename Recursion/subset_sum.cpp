
// prob link: https://practice.geeksforgeeks.org/problems/subset-sums2234/1#

class Solution{
public:
    vector<int> res;
    void rec(int i, vector<int> arr, int N, int sm){
        if(i == N){
            res.push_back(sm);
            return;
        }
        // include
        rec(i+1, arr, N, sm+arr[i]);
        // exclude
        rec(i+1, arr, N, sm);
    }
    vector<int> subsetSums(vector<int> arr, int N){
        rec(0, arr, N, 0);
        sort(res.begin(), res.end());
        return res;
    }
};

// Time complx: O(2^n)
// Space complx: O(2^n) + O(n) = O(2^n)