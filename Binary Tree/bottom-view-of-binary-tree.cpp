
// prob link: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#

class Solution{
public:
    vector <int> bottomView(Node *root) {
        vector<int> res;
        if(root == NULL) return res;
        map<int,int> mp;
        unordered_map<Node*, int> h;
        queue<Node*> q;
        q.push(root);
        h[root] = 0;
        while(!q.empty()){
            Node* node = q.front();
            int x = h[node];
            mp[x] = node->data;
            q.pop();
            if(node->left){
                q.push(node->left);
                h[node->left] = x-1;
            }
            if(node->right){
                q.push(node->right);
                h[node->right] = x+1;
            }
        }
        for(auto itr: mp){
            res.push_back(itr.second);
        }
        return res;
    }
};

// Time complx: O(n)
// Space complx: O(n) + O(n) + O(n) = O(n)