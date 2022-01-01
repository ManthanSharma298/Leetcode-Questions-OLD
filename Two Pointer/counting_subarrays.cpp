
// prob link: https://www.interviewbit.com/problems/counting-subarrays/


// Two pointer Approach
int solve(vector<int> &A, int B) {
    int l = 0, r = 0, summ = A[0], count = 0, n = A.size();
    while(l<n && r<n){
        if(summ < B){
            if(l <= r)
                count += r-l+1;
            r++;
            if(r < n){
                summ += A[r];
            }
        }
        else{
            summ -= A[l];
            l++;
        }
    }
    return count;
}

/*
    [1,2,3, ...] if sum of three numbers is less than B = 10
    then [3], [2,3], [1,2,3] are added to count as new number is 3
    hence we add the lenght of array made by pointers i.e. r-l+1
    (this is done before incrementing r)
*/

// Time Complx: O(n)
// Space Complx: O(1)


