
// prob link: https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level=0;
        TreeNode* node;
        vector<vector<int>> result;
        vector<int>temp;
        queue<TreeNode* >q;
        if(root == NULL) return {};
        q.push(root);
        level++;
     
        while(!q.empty()){
            temp = {};
            while(level--){
                node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            result.push_back(temp);
            level = q.size();
           
        }
        return result;
    }
};

// n -> number of nodes
// Time complx: O(n)    as we are traversing through all nodes once
// Space complx: O(n)   used by queue