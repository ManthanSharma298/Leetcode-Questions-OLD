// prob link: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/


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

// NOT PASSED
class Solution {
public:
    int sm = 0;
    int tmp;
    TreeNode* prev;
    bool isBST(TreeNode* node){
        if(node == NULL) return true;
        
        bool L = isBST(node->left);
        if(prev && prev->val >= node->val) return false;
        prev = node;
        tmp += node->val;
        bool R = isBST(node->right);
        return L && R;
    }
    void dfs(TreeNode* node){
        if(node == NULL) return;
        dfs(node->left);
        
        prev = NULL;
        tmp = 0;
        if(isBST(node)){
            sm = max(sm,tmp);
        }
        
        dfs(node->right);
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return sm;
    }
};
// Time complx: O(n*n)


// PASSED 
class Solution {
    int mxSum = 0;
    int mx = 1e9, mn = -1e9;
public:
    vector<int> dfs(TreeNode* node){
        if(node == NULL) return {1,mx,mn,0};
        
        auto L = dfs(node->left);
        auto R = dfs(node->right);
        if(L[0] == 0 || R[0] == 0 || node->val <= L[2] || node->val >= R[1]) return {0,mn,mx,0};
        
        mxSum = max(mxSum, L[3]+R[3]+node->val);
        
        return {1,min(node->val,L[1]),max(node->val,R[2]),L[3]+R[3]+node->val};
        
    }
    int maxSumBST(TreeNode* node){
        dfs(node);
        return mxSum;
    }
};
// Time complx: O(n)
// Space complx: O(h) + O(k) -> O(k) for vector<int> passed by dfs function