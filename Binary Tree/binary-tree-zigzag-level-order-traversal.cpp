
// prob link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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

// 1. Reverse the temp array while doing level order traversal

// 2. Using two stack
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        vector<int> temp;
        stack<TreeNode*> l,r;
        l.push(root);
        while(!l.empty() || !r.empty()){
            temp = {};
            while(!l.empty()){
                auto node = l.top();
                temp.push_back(node->val);
                l.pop();
                if(node->left){
                    r.push(node->left);
                }
                if(node->right){
                    r.push(node->right);
                }
            }
            res.push_back(temp);
            temp = {};
            while(!r.empty()){
                auto node = r.top();
                temp.push_back(node->val);
                r.pop();
                if(node->right){
                    l.push(node->right);
                }
                if(node->left){
                    l.push(node->left);
                }
            }
            if(temp.size() > 0) res.push_back(temp);    // to avoid [] push into res
        }
        return res;
    }
};

// Time complx: O(n);
// Space complx: O(n) + O(n) + O(n) = O(n) (for temp,l,r)

// Using Deque
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        vector<int> temp;
        deque<TreeNode*> dq;
        dq.push_back(root);
        int flg = 0;
        while(!dq.empty()){
            temp = {};
            int s = dq.size();
            for(int i=0; i<s; ++i){
                if(!flg){
                    auto node = dq.front();
                    dq.pop_front();
                    temp.push_back(node->val);
                    if(node->left){
                        dq.push_back(node->left);
                    }
                    if(node->right){
                        dq.push_back(node->right);
                    }
                }
                else{
                    auto node = dq.back();
                    dq.pop_back();
                    temp.push_back(node->val);
                    if(node->right){
                        dq.push_front(node->right);
                    }
                    if(node->left){
                        dq.push_front(node->left);
                    }
                }
            }
            flg ^= 1;
            res.push_back(temp);
        }
        return res;
    }
};
// Time complx: O(n)
// Space complx: O(n) + O(n) = O(n)