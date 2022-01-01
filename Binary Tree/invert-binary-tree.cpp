
// prob link: https://leetcode.com/problems/invert-binary-tree

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


// Recursive
class Solution {
public:
    void dfs(TreeNode* node){
        if(node == NULL) return;
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
        dfs(node->left);
        dfs(node->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};

// Time complx: O(N)
// Space complx: O(h) best case -> O(logN)
//                    worst case -> O(N)

// Iterative

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) continue;
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            q.push(node->left);
            q.push(node->right);
        }
        return root;
    }
};

// Time complx: O(N)
// Space complx: O(N) since in the worst case, the queue will contain all nodes in one level of the binary tree.
// and for a full binary tree, the leaf level has N/2 nodes = O(N) 