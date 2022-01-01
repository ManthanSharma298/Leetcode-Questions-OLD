
// prob link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int res;
public:
    int dfs(TreeNode* node){
        if(node == NULL) return 0;
        int L = dfs(node->left);
        int R = dfs(node->right);
        L = max(L,0);
        R = max(R,0);
        res = max(res, L + node->val + R);
        return max(L,R) + node->val;
    }
    int maxPathSum(TreeNode* root) {
        res = root->val;
        dfs(root);
        
        return res;
    }
};

// TIme complx: O(n)
// Space complx: O(h)