
// prob link: https://leetcode.com/problems/same-tree

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        
        if(p->val != q->val) return false;
        bool l = isSameTree(p->left, q->left);
        bool r = isSameTree(p->right, q->right);
        return (l && r);
        
    }
};

// Time complx: O(N) visiting all node once
// or you can think of this T(n) = 2*T(n/2) + c

// Space complx: depth of a tree i.e. best case -> O(logN)
//                                    worst case -> O(N)

/*  let depth = d
    number of nodes at each depth are 2^d
    hence
    2^0 + 2^1 + ..... + 2^d = N (total nodes)
    2^(d+1) - 1 = N
    d = log(N+1) - 1
    d = O(logN) 
*/


// Iterative 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode* >qe;
        qe.push(p);
        qe.push(q);
        
        while(!qe.empty()){
            TreeNode* pNode = qe.front();
            qe.pop();
            TreeNode* qNode = qe.front();
            qe.pop();
            if(pNode == NULL && qNode == NULL) continue;
            if(pNode == NULL || qNode == NULL) return false;
            if(pNode->val != qNode->val) return false;
            qe.push(pNode->left);
            qe.push(qNode->left);
            qe.push(pNode->right);
            qe.push(qNode->right);
        }
        
        return true;
        
    }
};


// Time complx: O(N) 
// Space complx: best case -> O(logN)
//               worst case -> O(N)