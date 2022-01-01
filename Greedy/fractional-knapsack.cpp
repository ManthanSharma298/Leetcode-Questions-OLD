// prob link: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#


class Solution{
public:
    static bool cmp(Item i, Item j){
        return ((double)i.value/i.weight > (double)j.value/j.weight);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double res = 0;
        sort(arr, arr+n, cmp);
        for(int i=0; i<n; ++i){
            if(W == 0) break;
            int w = arr[i].weight;
            int x = min(w, W);
            double rt = (double)arr[i].value/w;
            res += x*rt;
            W -= x;
        }
        return res;
    }
};

// Time complx: O(nlogn) + O(n)
// Space complx: O(1) except arr