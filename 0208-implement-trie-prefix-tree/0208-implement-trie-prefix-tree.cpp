class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        for(int i=0; i<26; i++){
            children[i] = nullptr;
            isEnd = false;
        }
    }
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(node->children[ch - 'a'] == nullptr){
                node->children[ch - 'a'] = new TrieNode();
            }
            node = node->children[ch - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(node->children[ch - 'a'] == nullptr){
                return false;
            }
            node = node->children[ch - 'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i=0; i<prefix.size(); i++){
            char ch = prefix[i];
            if(node->children[ch - 'a'] == nullptr){
                return false;
            }
            node = node->children[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */