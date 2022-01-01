
// prob link: https://leetcode.com/problems/symmetric-tree/

// Recursive
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
    bool dfs(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val != q->val) return false;
        return dfs(p->left, q->right) && dfs(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return dfs(root, root);
    }
};

// Time complx: O(n)
// Space complx: O(h)


// Iterative (Same as recursive)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        stack<TreeNode*> st;
        st.push(root->left);
        st.push(root->right);
        while(!st.empty()){
            auto l = st.top();
            st.pop();
            auto r = st.top();
            st.pop();
            if(l == NULL && r == NULL) continue;
            if(l == NULL || r == NULL) return false;
            if(l->val != r->val) return false;
            st.push(l->left);
            st.push(r->right);
            st.push(l->right);
            st.push(r->left);
        }
        return true;
    }
};

// Time complx: O(n)
// Space complx: O(2^h)  as it is like a queue
// when h = logn -> O(n)
// when h = n -> O(n) as each node has 1 child

// Space complx: O(n)