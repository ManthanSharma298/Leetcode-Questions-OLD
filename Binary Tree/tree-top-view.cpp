
// prob link: https://www.hackerrank.com/challenges/tree-top-view/problem

void topView(Node* root) {
    if(root == NULL) return;
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto node = q.front().first;
        int h = q.front().second;
        q.pop();
        if(mp.count(h) == 0){
            mp[h] = node->data;
        }
        if(node->left){
            q.push({node->left,h-1});
        }
        if(node->right){
            q.push({node->right,h+1});
        }
    }
    for(auto itr: mp){
        cout<<itr.second<<" ";
    }
    cout<<"\n";
}
// Time complx: O(n)
// Space complx: O(n) + O(n) = O(n)