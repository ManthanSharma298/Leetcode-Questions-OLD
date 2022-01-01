// prob link: https://www.codingninjas.com/codestudio/problems/convert-a-given-binary-tree-to-doubly-linked-list_893106?leftPanelTab=0


/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
BinaryTreeNode<int>* nxt;
void dfs(BinaryTreeNode<int>* root){
    if(root == NULL) return;
   	
    dfs(root->right);
    root->right = nxt;
    if(nxt) nxt->left = root;
    nxt = root;
    dfs(root->left);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    nxt = NULL;
    dfs(root);
    while(root->left){
        root = root->left;
    }
    return root;
}
// Time complx: O(n) + O(n) = O(n)
// Space complx: O(h)


// *************************************************************
BinaryTreeNode<int>* prv;
BinaryTreeNode<int>* start;

void dfs(BinaryTreeNode<int>* root){
    if(root == NULL) return;
   	
    dfs(root->left);	// move left
 
    if(prv == NULL) start = root;
    root->left = prv;
    if(prv) prv->right = root;
    prv = root;
    
    dfs(root->right);	// move right
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    prv = NULL;
    dfs(root);
  
    return start;
}
// Time complx: O(n)
// Space complx: O(h)