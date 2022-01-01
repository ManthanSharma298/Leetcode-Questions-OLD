// prob link: https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0


// not used BST properties
void f(BinaryTreeNode<int> *node, int x, int& res){
    if(node == NULL) return;
    f(node->left,x,res);
    if(node->data >= x && res == -1){
        res = node->data;
    }
    f(node->right,x,res);
}
int findCeil(BinaryTreeNode<int> *node, int x){
	int res = -1;
	f(node,x,res);
	return res;
}
// Time complx: O(n)
// Space complx: O(h)



int findCeil(BinaryTreeNode<int> *node, int x){
	int res = -1;
    while(node != NULL){
        if(node->data == x) return x;
        else if(node->data > x){
            res = node->data;
            node = node->left;
        }
        else{
            node = node->right;
        }
    }
    return res;
}
// Time complx: O(h)
// Space complx: O(h)