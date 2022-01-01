// prob link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/


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
    TreeNode* rec(int i, int j, vector<int>& nums){
        if(i > j) return NULL;
        int m = (i+j)/2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = rec(i,m-1,nums);
        root->right = rec(m+1,j,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return rec(0,nums.size()-1,nums);
    }
};

// Time complx: O(n)
// Space complx: O(logn)    // as it is height balanced