
// prob link: https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> res;
public: 
    void rec(TreeNode* node){
        if(node == NULL) return;
        rec(node->left);
        res.push_back(node->val);
        rec(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        rec(root);
        return res;
    }
};

// Time complx: O(n);   T(n) = 2*T(n/2) + k
// Space complx: O(h)
// worst case: O(n)
// avg case: O(log n)


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr != NULL || !st.empty()){
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }
};
// Time complx: O(n) traversing all nodes
// Space complx: O(h)
// worst case: O(n)
// avg case: O(log n)
