
// prob link: https://leetcode.com/problems/design-add-and-search-words-data-structure/

class TrieNode{
 public:
    bool isEnd = false;
    TrieNode* children[26];
};

class WordDictionary {
private:
    TrieNode* root;
    bool search(string word, int idx, TrieNode* node){
        if(idx == word.size()) return node->isEnd;
        if(word[idx] == '.'){
            TrieNode* currNode = node;
            for(int i=0; i<26; ++i){
                if(currNode->children[i] && search(word, idx+1, currNode->children[i]))
                return true;
            }
            return false;
        }else{
            return node->children[word[idx]-'a'] && search(word, idx+1, node->children[word[idx]-'a']);
        }
        return false;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* temp = root;
        for(char ch: word){
            if(temp->children[ch-'a'] == NULL){
                temp->children[ch-'a'] = new TrieNode();
            }
            temp = temp->children[ch-'a'];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        return search(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */