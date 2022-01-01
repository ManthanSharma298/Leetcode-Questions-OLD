
//prob link: https://leetcode.com/problems/numbers-with-same-consecutive-differences/

// every digit has two choices either it is prevDig + k or prevDig - k
// hence it can be imagined like a binary tree so solved using DFS and BFS

class Solution {
    int k;
    vector<int>ans;
public:
    
    bool isValid(int num){
        return (num >= 0 && num <= 9);
    }
    void dfs(int n, int val){
        
        if(n == 0){
            ans.push_back(val);
            return;
        }
        
        int lastDig = val%10;
        
        if(k == 0){
            dfs(n-1, val*10 + lastDig);
        }
        else{
            int newNum = lastDig + k;
            if(isValid(newNum)){
                dfs(n-1, val*10 + newNum);
            }
            newNum = lastDig - k;
            if(isValid(newNum)){
                dfs(n-1, val*10 + newNum);
            }
        }
    }
        
    vector<int> numsSameConsecDiff(int n, int k) {
        this->k = k;
    
        for(int i=1;i<=9;++i){
            dfs(n-1, i);
        }
        return ans;
    }
};

// T(n) = 2*T(n) + c
// Time complx: O(2^n)


// Space complx: this is a recursive function where max number of stack calls are n
// In addition a vector ans with lenght can go upto 2^n (imagine like a tree).
// hence space complx: O(2^n) + O(n) = O(2^n)








