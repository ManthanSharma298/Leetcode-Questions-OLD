
// prob link: https://leetcode.com/problems/implement-trie-prefix-tree/

class TrieNode{
public:
    bool isEnd;
    TrieNode *children[26];
    // int *array = new int[26];
};
class Trie {
private: 
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *temp = root;
        for(char ch: word){
            if(temp->children[ch-'a'] == NULL){
                temp->children[ch-'a'] = new TrieNode();
            }
            temp = temp->children[ch-'a'];
        }
        temp->isEnd = true;
    }
    
    // Time complx: O(word.length)
    // Space complx: O(26*word.length) = O(word.length)
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *temp = root;
        for(char ch: word){
            if(temp->children[ch-'a'] == NULL){
                return false;
            }else{
                temp = temp->children[ch-'a'];
            }
        }
        return temp->isEnd;
    }

    // Time complx: O(word.length)
    // Space complx: O(1)
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *temp = root;
        for(char ch: prefix){
            if(temp->children[ch-'a'] == NULL){
                return false;
            }else{
                temp = temp->children[ch-'a'];
            }
        }
        return true;
    }

    // Time complx: O(prefix.length)
    // Space complx: O(1)
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */