// prob link: https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?leftPanelTab=0


int isVal(int m, vector<int>& a, int c){
    int n = a.size();
    int cnt=1;
    int i=0,j=1;
    while(j<n){
        if(a[j]-a[i] >= m){
            i = j;
            cnt++;
        }
        j++;
    }
    return (cnt >= c);
}

int aggressiveCows(vector<int> &a, int k){
    sort(a.begin(),a.end());
    int l=1, r=1e9+1;
    // TTTTT'T'FFFFFFF
    while(l+1 < r){
        int m = l+(r-l)/2;
        if(isVal(m,a,k)){
            l = m;
        }
        else{
            r = m;
        }
    }
    return l;
}
// Time complx: O(n*logn)
// Space complx: O(logn) space used in sorting as in-built uses quick sort 