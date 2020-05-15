//https://leetcode.com/problems/add-and-search-word-data-structure-design/description/

struct TrieNode {
    TrieNode* chars[26];
    bool isEnd;
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    WordDictionary() {
       root = getNode(); 
    }
    
    TrieNode* getNode () {
        TrieNode* root = new TrieNode;
        root -> isEnd = false;
        
        for(int i = 0; i < 26; i++) {
            root -> chars[i] = NULL;
        }
        return root;
    }
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* temp = root;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if(temp -> chars[index] == NULL)
                temp -> chars[index] = getNode();
            temp = temp -> chars[index];
        }
        temp -> isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchHelper(word, root, 0); 
    }
    
    bool searchHelper(string word, TrieNode* temp, int pos) { 
        if(pos == word.size()) {
            if(temp -> isEnd)
                return true;
            return false;
        }
        bool found = false;
        if(word[pos] == '.') { 
            for(int i = 0; i < 26; i++) {
                if(temp -> chars[i] != NULL) {
                    found = searchHelper (word, temp -> chars[i], pos + 1);
                    if(found)
                        break;
                }
            }
        } else {
            int index = word[pos] - 'a';
            if (temp -> chars[index] != NULL) 
                found = searchHelper (word, temp -> chars[index], pos + 1);
        }
        return found;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */