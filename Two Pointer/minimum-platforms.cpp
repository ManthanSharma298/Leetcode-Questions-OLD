// prob link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

int findPlatform(int arr[], int dep[], int n){
    // 0900     0940    0950    1100    1500    1800
    // 0910     1120    1130    1200    1900    2000    
    sort(arr,arr+n);
    sort(dep,dep+n);
    int res = 1;
    int cnt = 1;
    int i=1,j=0;
    while(i<n && j<n){
        if(arr[i] <= dep[j]){
            cnt++;
            res = max(res, cnt);
            i++;
        }
        else{
            cnt--;
            j++;
        }
    }
    return res;
}
// Time complx: O(nlogn) + O(n) = O(nlogn)
// Space complx: O(1)