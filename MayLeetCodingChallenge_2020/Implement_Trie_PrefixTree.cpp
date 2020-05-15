//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3329/

struct TrieNode {
    TrieNode* characters[26];
    bool isEnd;
};
class Trie {
public:
    /** Initialize your data structure here. */
    
    TrieNode* root;
    Trie() {
        root = getNode();
    }
    
    TrieNode* getNode () {
        TrieNode* root = new TrieNode;
        root -> isEnd = false;
        
        for(int i = 0; i < 26; i++) {
            root -> characters[i] = NULL;
        }
        return root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* temp = root;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if(temp -> characters[index] == NULL)
                temp -> characters[index] = getNode();
            temp = temp -> characters[index];
        }
        temp -> isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* temp = root;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if(temp -> characters[index] == NULL)
                return false;
            temp = temp -> characters[index];
        }
        if(temp -> isEnd)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        TrieNode* temp = root;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if(temp -> characters[index] == NULL)
                return false;
            temp = temp -> characters[index];
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