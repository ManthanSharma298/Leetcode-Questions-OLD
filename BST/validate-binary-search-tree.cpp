
// prob link: https://leetcode.com/problems/validate-binary-search-tree/

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

// Approach 1
// HINT IS INORDER 
// IF IT IS A VALID BST THEN INORDER MUST BE IN SORTED ORDER
class Solution {
    TreeNode* prev = NULL;
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        
        bool L = isValidBST(root->left);
        if(prev != NULL && prev->val >= root->val) return false;
        prev = root;
        bool R = isValidBST(root->right);
        
        return (L && R);
    }
};

// Time complx: O(n)
// Space complx: O(n)

// Iteratively
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        TreeNode* prev = NULL;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(curr || !s.empty()){
            while(curr){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            if(prev != NULL && prev->val >= curr->val) return false;
            prev = curr;
            curr = curr->right;
        }
        return true;
    }
};

// Time complx: O(n)
// Space complx: O(n)

// mn,mx technique
class Solution {
public:
    bool isValid(long long mn, long long mx, TreeNode* root){
        if(root == NULL) return true;
        if(root->val <= mn || root->val >= mx) return false;
        bool L = isValid(mn, root->val, root->left);
        bool R = isValid(root->val, mx, root->right);
        
        return (L && R);
    }
    bool isValidBST(TreeNode* root) {
        long long mn = -1e10;
        long long mx = 1e10;
        return isValid(mn,mx,root);
    }
};

// Time complx: O(n)
// Space complx: O(n)