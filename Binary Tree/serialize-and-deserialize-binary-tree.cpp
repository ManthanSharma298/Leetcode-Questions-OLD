
// prob link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "N";
        string L = serialize(root->left);
        string R = serialize(root->right);
        return to_string(root->val)+","+L+","+R;
    }
    void tokenize(const std::string &s, const char delim,
            std::vector<std::string> &out){
    std::string::size_type beg = 0;
    for (auto end = 0; (end = s.find(delim, end)) != std::string::npos; ++end){
        out.push_back(s.substr(beg, end - beg));
        beg = end + 1;
    }
 
    out.push_back(s.substr(beg));
    }
    
    TreeNode* deserialise(queue<string>& q){
        if(q.size() == 0) return NULL;
        string ch = q.front();
        q.pop();
        
        if(ch == "N") return NULL;
        TreeNode* newNode = new TreeNode(stoi(ch));
        cout<<newNode->val<<" ";
        newNode->left = deserialise(q);
        newNode->right = deserialise(q);
        
        // cout<<newNode->val<<": "<<newNode->left<<" "<<newNode->right<<"\n";
        return newNode;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> out;
        char delim = ',';
        tokenize(data, delim, out);

        queue<string>q;
        for(string elm: out){
            q.push(elm);
            // cout<<elm<<" ";
        }
        // cout<<"\n";
        return deserialise(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// Time complx: O(N)
// Space complx: O(N)