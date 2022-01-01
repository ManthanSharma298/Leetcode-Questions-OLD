
// prob link: https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            auto tp = st.top();
            res.push_back(tp->val);
            st.pop();
            if(tp->right != NULL){
                st.push(tp->right);
            }
            if(tp->left != NULL){
                st.push(tp->left);
            }
        }
        return res;
    }
};

// Time complx: O(n) traversing all nodes
// Space complx: O(h)
// worst case: O(n)
// avg case: O(log n)