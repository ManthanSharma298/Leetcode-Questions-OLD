
// prob link: https://leetcode.com/problems/diameter-of-binary-tree/

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
    int res;
    int dfs(TreeNode* node){
        if(node == NULL) return 0;
        int lf = dfs(node->left);
        int rt = dfs(node->right);
        res = max(res,lf+rt);
        return max(lf,rt) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        this->res = 0;  // just for fashion
        dfs(root);
        return res;
    }
};

// Time complx: O(n)
// Space complx: O(h)