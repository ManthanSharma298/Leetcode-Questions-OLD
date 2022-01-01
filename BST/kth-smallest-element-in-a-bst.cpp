
// prob link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int k, ans;
public:
    void dfs(TreeNode* node){
        if(node == NULL) return;
        
        dfs(node->left);
        k--;
        if(k == 0){
            ans = node->val;
            return;
        }
        dfs(node->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return ans;
    }
};

// Time complx: O(N)
// Space complx: O(N)


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while(true){
            while(root != NULL){
                stk.push(root);
                root = root->left;
            } 
            root = stk.top();
            stk.pop();
            k--;
            if(k == 0) return root->val;
            root = root->right;
        }
    }
};
// IMPORTANT
// Time complx: O(h + k) i.e. O(N + k) for worst case
//                            O(logN + k) for avg case
// Space complx: O(h) i.e. O(N) for worst case
//                         O(logN) for avg case