class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        Trie trie;
        for (string word : wordDict) {
            trie.insert(word);
        }

        unordered_map<int, vector<string>> dp;

        for (int startIdx = s.size(); startIdx >= 0; startIdx--) {

            vector<string> validSentences;

            TrieNode* currentNode = trie.root;

            for (int endIdx = startIdx; endIdx < s.size(); endIdx++) {
                char c = s[endIdx];
                int index = c - 'a';

                if (!currentNode->children[index]) {
                    break;
                }

                currentNode = currentNode->children[index];
                
                if (currentNode->isEnd) {
                    string currentWord =
                        s.substr(startIdx, endIdx - startIdx + 1);

                    if (endIdx == s.size() - 1) {
                        validSentences.push_back(currentWord);
                    } else {

                        for (string sentence : dp[endIdx + 1]) {
                            validSentences.push_back(currentWord + " " +
                                                     sentence);
                        }
                    }
                }
            }

            dp[startIdx] = validSentences;
        }

        return dp[0];
    }
};