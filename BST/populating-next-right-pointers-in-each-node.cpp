// prob link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node*> q;
        q.push(root);
        Node* prev;
        while(!q.empty()){
            int sz = q.size();
            prev = NULL;
            for(int i=0; i<sz; ++i){
                Node* r = q.front();
                q.pop();
                
                r->next = prev;
                prev = r;
                
                if(r->right) q.push(r->right);
                if(r->left) q.push(r->left);
            }
        }
        return root;
    }
    
};
// Time complx: O(n) worst case as elements in level become 2^h and h = logn
// Space complx: O(n)



// recursive
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        
        if(root->left) root->left->next = root->right;
        if(root->right && root->next) root->right->next = root->next->left;
        
        connect(root->left);
        connect(root->right);
        
        return root;
    }
};
// Time complx: O(n)
// Space complx: O(logn) taken by recursive calls



// iterative
class Solution {
public:
    Node* connect(Node* root) {
        Node* lev = root, *tmp;
        while(lev){
            tmp = lev;
            while(lev){
                if(lev->left) lev->left->next = lev->right;
                if(lev->right && lev->next) lev->right->next = lev->next->left;
                lev = lev->next;
            }
            lev = tmp->left;
        }   
        return root;
    }  
};
// Time complx: O(n)
// Space complx: O(1) 