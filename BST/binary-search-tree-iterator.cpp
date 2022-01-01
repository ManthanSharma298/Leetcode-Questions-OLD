// prob link: https://leetcode.com/problems/binary-search-tree-iterator/


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
class BSTIterator {
    stack<TreeNode*> s;
public:
    void left(TreeNode* node){
        while(node){
            s.push(node);
            node = node->left;
        }
    }
    BSTIterator(TreeNode* root) {
        left(root);
    }
    
    int next() {
        auto tp = s.top();
        s.pop();
        left(tp->right);
        return tp->val;
    }
    bool hasNext() {
        return !s.empty();
    }
};
// Time complx of next(): O(h) for some and O(1) for some cases HENCE amortised O(1)
// Time complx of hasNext(): O(1)
// Space complx: O(h)