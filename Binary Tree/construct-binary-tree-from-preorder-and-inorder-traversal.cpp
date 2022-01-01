
// prob link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    
    TreeNode* build(int inS, int inE, int preS, int preE, vector<int>& preorder, vector<int>& inorder){
        if(inS > inE || preS >= preorder.size()) return NULL;
        TreeNode* currRoot = new TreeNode(preorder[preS]);
        int idx;
        for(int i=inS; i<=inE; ++i){
            if(inorder[i] == preorder[preS]){
                idx = i;
                break;
            }
        }
        currRoot->left = build(inS, idx-1, preS+1, preS-inS+idx, preorder, inorder);
        currRoot->right = build(idx+1, inE, preS-inS+idx+1, preE, preorder, inorder);
        return currRoot;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return build(0, n-1, 0, n-1, preorder, inorder);
    }
};

// Time complx: O(N*N)
// Space complx: O(N)


// optimize it with hashmap
///////////////////////////////////////////////
