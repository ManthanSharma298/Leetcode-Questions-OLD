// problem link: https://www.interviewbit.com/old/problems/allocate-books/


int isValid(vector<int>& A, int B, int sum){
    int n = A.size();
    int cnt = 1;
    int curr = 0;
    for(int i=0; i<n; ++i){
        if(A[i] > sum) return 0;
        else if(curr+A[i] <= sum){
            curr += A[i];
        }
        else{
            curr = A[i];
            cnt++;
        }
    }
    return (cnt <= B);
}
int Solution::books(vector<int> &A, int B) {
    if(B == 0) return -1;
    int n = A.size();
    int sum = 0;
    if(B > n) return -1;
    for(int i=0; i<n; ++i){
        sum += A[i];
    }
    int l = 0, r = sum;
    while(l+1 < r){
        int m = l+(r-l)/2;
        if(isValid(A,B,m)){
            r = m;
        }
        else{
            l = m;
        }
    }
    if(isValid(A,B,r)) return r;
    return -1;
}
// Time complx: O(n*logn)
// Space complx: O(1)