
// prob link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1#


class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int x=0, y=0;
            while(x < n){
                if(arr1[x] > arr2[y]){
                    swap(arr1[x], arr2[y]);
                    for(int i=0; i<m-1; ++i){
                        if(arr2[i+1] < arr2[i]){
                            swap(arr2[i+1], arr2[i]);
                        }
                    }
                }
                x++;
            }
        } 
};
// Time complx: O(n*m)
// Space complx: O(1)

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int i=0, j=0, k=n-1;
            while(i <= k && j < m){
                if(arr1[i] > arr2[j]){
                    swap(arr1[k], arr2[j]);
                    j++;
                    k--;
                }else{
                    i++;
                }
            }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        } 
};

// Time complx: O(n+m) + O(nlogn) + O(mlogm) = O((n+m)*log(n+m))
// Space complx: O(1)
