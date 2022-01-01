
// prob link: https://leetcode.com/problems/subtree-of-another-tree/

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
    bool check(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        
        if(p->val != q->val) return false;
        bool L = check(p->left, q->left), R = check(p->right, q->right);
        return (L && R);
    }
    
    bool checking(TreeNode* root, TreeNode* subRoot){
        if(root == NULL) return false;
        if(check(root, subRoot)) return true;
        bool L = checking(root->left, subRoot);
        bool R = checking(root->right, subRoot);
        return (L || R);
        
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL) return true;
        return checking(root, subRoot);
    }
};

// Time complx: O(M*N) worst case       T(N) = T(N-1) + M
//              O(M*logN) best case     T(N) = 2*T(N/2) + M

// Space complx: O(min(N,M))

// where M are nodes present in root
// N nodes are present in root