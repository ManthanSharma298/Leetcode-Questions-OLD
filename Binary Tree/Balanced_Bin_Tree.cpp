

// Problem link: https://leetcode.com/problems/balanced-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


// Method - 1
class Solution {
public:
    
    int height(TreeNode* node){
        
        // base case
        if(node == NULL) return 0; 
        return max(height(node->left), height(node->right)) + 1;
    }
    
    
    bool isBalanced(TreeNode* root) {
        // base case 
        if(root == NULL) return true;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
            
        if(abs(rightHeight - leftHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }
        
        else return false;    
        
    }
};

// same method but diff implementation
class Solution {
public:
    bool res = true;
    int dfs(TreeNode* node){
        if(node == NULL) return 0;
        int lf = dfs(node->left);
        int rt = dfs(node->right);
        if(abs(lf-rt) > 1){
            res = false;
        }
        return max(lf,rt) + 1;
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return res;
    }
};



/*  Time complexity of height function is O(n)
    as T(n) = 2*T(n/2) + k for best case
    and T(n) = T(n-1) + k for worst case 
    but in both case time complexity is O(n)
    
    
    for isBalanced 
    T(n) = k1*N + 2*T(n/2) + k2
    time complexity is O(nlogn)
    

*/



// Method - 2
class Solution {
public:
    
    int height(TreeNode* node){
        
        // base case
        if(node == NULL) return 0; 

        int leftHeight = height(node->left), rightHeight = height(node->right);
        if(leftHeight == -1 || rightHeight == -1) return -1;
        
        if(abs(leftHeight - rightHeight) > 1) return -1; // extra condition 
        
        return max(leftHeight, rightHeight) + 1;
    }
    
    
    bool isBalanced(TreeNode* root) {
       return (height(root) == -1) ? false : true;
    }
};




/*

    time complexity of isBalanced function is O(n)



*/














