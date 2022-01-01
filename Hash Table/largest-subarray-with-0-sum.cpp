
// prob link: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#


int maxLen(int A[], int n){
    int res=0, sum=0;
    unordered_map<int,int> mp;
    mp[0] = -1;
    for(int i=0; i<n; ++i){
        sum += A[i];
        if(mp.count(sum)){
            int idx = mp[sum];
            res = max(res, i-idx);
        }
        else{
            mp[sum] = i;
        }
    }
    return res;
}

// Time complx: O(n)
// Space complx: O(n)