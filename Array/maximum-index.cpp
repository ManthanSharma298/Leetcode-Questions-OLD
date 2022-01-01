
// prob link: https://practice.geeksforgeeks.org/problems/maximum-index-1587115620/1#

class Solution{
public:
        
    // arr[]: input array
    // n: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) {
        vector<pair<int,int>> v(n);
        for(int i=0; i<n; ++i){
            v[i] = {arr[i],i};
        }
        sort(v.begin(), v.end());
        
        int res = 0, mn = v[0].second;
        for(int i=1; i<n; ++i){
            res = max(res, v[i].second-mn);
            mn = min(mn, v[i].second);
        }
        return res;
    }
};

// Time complx: O(n*log(n))
// Space complx: O(n)


int maxIndexDiff(int arr[], int n) {
    int res = 0;
    vector<int> rt(n);
    rt[n-1] = arr[n-1];
    for(int i=n-2; i>=0; --i){
        rt[i] = max(rt[i+1], arr[i]);
    }
    int i=0, j=0;
    while(i<n && j<n){
        if(rt[j] >= arr[i]){
            res = max(res, j-i);
            j++;
        }
        else{
            i++;
        }
    }
    return res;
}

// Time complx: O(n)
// Space complx: O(n)