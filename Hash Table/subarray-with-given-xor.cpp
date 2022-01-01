
// prob link: https://www.interviewbit.com/old/problems/subarray-with-given-xor/

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> mp;
    int xr=0, cnt=0;
    for(int i=0; i<A.size(); ++i){
        xr ^= A[i];
        if(xr == B) cnt++;
        int a = xr^B;
        if(mp.count(a)){
            cnt += mp[a];
        }
        mp[xr]++;
    }
    return cnt;
}

// Time complx: O(n) or O(n*logn) depending on which map you are using
// Space complx: O(n)