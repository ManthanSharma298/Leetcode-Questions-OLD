
//prob link: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

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
private:
    int prev = -1, minDist = 1e6;
public:
  
    void dfs(TreeNode* node){       // inorder traversal
        if(node == NULL) return;
        
        dfs(node->left);
        if(prev == -1)
            prev = node->val;
            
        else{
            minDist = min(minDist, node->val - prev);
            prev = node->val;
        }
        
        dfs(node->right);
    }
    
    
    
    int minDiffInBST(TreeNode* root) {
        
        dfs(root);
        return minDist;
        
    }
};

// Time complx: O(N)
//Space complx: O(h)
// where h is height of tree




















