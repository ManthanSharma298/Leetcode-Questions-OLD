
//Prob link: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

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



// Inorder solution
class Solution {		
private:
    int totalSum = 0,prevSum = 0;
public:

    void sumOfnodes(TreeNode* node){
        if(node == NULL) return;

        totalSum += node->val;
        sumOfnodes(node->left);
        sumOfnodes(node->right);

    }
    void dfs(TreeNode* node){
        if(node == NULL) return;

        dfs(node->left);
        int temp = node->val;
        node->val = totalSum - prevSum;
        prevSum += temp;

        dfs(node->right);
    }
    TreeNode* bstToGst(TreeNode* root) {
        sumOfnodes(root);
        dfs(root);
        return root;
    }
};



//Brute force or initial approach (we need to do it in one recursive function to further reduce time and space complexities 
// Time complx = O(n)
// Space complx = O(h)




// Reversed Inorder solution
class Solution {
private:
    int prevSum = 0;
public:

    void dfs(TreeNode* node){
        if(node == NULL) return;
		
        dfs(node->right);
		int temp = node->val;
        node->val +=  prevSum;
        prevSum += temp;


        dfs(node->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        return root;
    }
};

// Time complx = O(n)
// Space complx = O(h)


























