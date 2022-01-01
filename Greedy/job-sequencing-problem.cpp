// prob link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#


// class Solution
static bool cmp(Job a, Job b){
    return a.profit > b.profit;
}
vector<int> JobScheduling(Job arr[], int n) {
    sort(arr,arr+n,cmp);
    int s=0;
    for(int i=0; i<n; ++i){
        s = max(s, arr[i].dead);
    }
    vector<int> dp(s+1,0);
    int res = 0, j=0;
    for(int i=0; i<n; ++i){
        for(int k=arr[i].dead; k>=1; --k){
            if(dp[k] == 0){
                dp[k] = 1;
                j++;
                res += arr[i].profit;
                break;
            }
        }
    }
    return {j, res};
}
// Time complx: O(nlogn) + O(n*s) = O(n*s)
// Time complx: O(s)