
// prob link: https://leetcode.com/problems/validate-binary-search-tree/

//
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
    vector<int>nodes;
public:
    
    void dfs(TreeNode* node){
        if(node == NULL) return;
        
        dfs(node->left);
        nodes.push_back(node->val);
        dfs(node->right);
    }
    
    bool isValidBST(TreeNode* root) {
        
        dfs(root);
        for(int i=0;i<nodes.size() - 1;++i){
            if(nodes[i] >= nodes[i+1]) return false;
        }
        return true;
    }
    
   
};
// Time complx: O(logn)
// Space complx: O(n + logn) = O(n)


// modified version (in this array is not used)
// need to declare TreeNode* prev in class
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        bool L = isValidBST(root->left);
        
        if(prev != NULL && prev->val >= root->val) return false;
        prev = root;
        
        bool R = isValidBST(root->right);

        return (L && R);        
    }

// Time complx: O(logn)
// Space complx: O(logn)









