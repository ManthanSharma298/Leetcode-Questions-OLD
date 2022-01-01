// prob link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/


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
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        TreeNode* lf = root->left, * rt = root->right;
        flatten(lf);
        flatten(rt);
        TreeNode* it = lf;
        while(it && it->right){
            it = it->right;
        }
        if(it){
            it->right = rt;
            root->right = lf;
            root->left = NULL;
        }
    }
};
// Time complx: O(n)
// Space complx: O(h)   -> worst case O(n), avg case -> O(logn) 
