// prob link: https://leetcode.com/problems/clone-graph/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> mp;
public:
    Node* dfs(Node* node){
        if(mp.count(node)) return mp[node];
        Node *newNode = new Node(node->val);
        mp[node] = newNode;
        
        for(auto cld: node->neighbors){
            newNode->neighbors.push_back(dfs(cld));
        }
        
        return mp[node];
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        return dfs(node);
    }
};
// Time complx: O(N + V)
// Space complx: O(N + V) 