
// prob link: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

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
    
    pair<int,TreeNode*> depth(TreeNode* node){		// bottom-up approach
        
        if(node == NULL) return {0, node};
        
        pair<int,TreeNode*> LsubTree = depth(node->left),
                        RsubTree = depth(node->right);
        
        if(LsubTree.first == RsubTree.first)		// return node
            return {LsubTree.first + 1, node};
        else if(LsubTree.first > RsubTree.first)
            return {LsubTree.first + 1, LsubTree.second};		// return to left subtree
        else
            return {RsubTree.first + 1, RsubTree.second};		// return to right subtree
        
        
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return depth(root).second;
    }
};

/*
 *	depth of leaf nodes are marked as 0
 *	
 * */







