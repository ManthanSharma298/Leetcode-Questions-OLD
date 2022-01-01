
// prob link: https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode* curr = root;
        while(curr != NULL || !st.empty()){
            if(curr){
                st.push(curr);
                curr = curr->left;
            }
            else{
                auto tp = st.top();
                if(tp->right == NULL){
                    res.push_back(tp->val);
                    st.pop();
                    while(!st.empty() && st.top()->right == tp){
                        res.push_back(st.top()->val);
                        tp = st.top();
                        st.pop();
                    }
                }
                else{
                    curr = tp->right;
                }
            } 
        }
        return res;
    }
};

// Time complx: O(n)
// Space complx: O(h)