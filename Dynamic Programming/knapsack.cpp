
// prob link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1


// Method-1 (recursion or brute force)

int knapsack(int W, vector<int>weight, vector<int>values, int n){
    if(W == 0 || n == 0) return 0;
    if(weight[n-1] > W){  //exclude
        return knapsack(W,weight,values,n-1);
    }
    else{
        int taken = knapsack(W-weight[n-1],weight,values,n-1);
        int notTaken = knapsack(W,weight,values,n-1);
        return max(taken+values[n-1], notTaken);
    }
}


// Time Complx: O(2^n)
// Space Complx: O(n)



//Method-2 (DP)

const int MX_SIZE = 1000;
int dp[MX_SIZE][MX_SIZE];


int knapsack(int W, vector<int>weight, vector<int>values, int n){
    for(int w=1; w<=W; w++){
        for(int idx=1; idx<=n; idx++){
            if(weight[idx-1] > w){
                dp[idx][w] = dp[idx-1][w];
            }
            else{
                int taken = dp[idx-1][w-weight[idx-1]];
                int notTaken = dp[idx-1][w];
                dp[idx][w] = max(taken+values[idx-1], notTaken);
            }
        }
    } 
    return dp[n][W];
}
// time: O(n^2)
// space: O(n^2)   2d array is used


