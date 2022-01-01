// prob link: https://leetcode.com/problems/trim-a-binary-search-tree/

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

class Solution {
public:
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL) return NULL;   // also removes nodes that are to be trimmed
        
        
        // this is also not needed the above condition will satisfy this
        
        // if(root->val == low){
        //     root->left = NULL;
        //     root->right = trimBST(root->right, low, high);
        //     return root;
        // }
        
        if(root->val < low){
            return trimBST(root->right, low, high);
        }
        if(root->val > high){
            return trimBST(root->left, low, high);
        }
        
        // reach here means the node can't be removed 
        // so trim its left and right subtree
        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
        return root;
    }
};
