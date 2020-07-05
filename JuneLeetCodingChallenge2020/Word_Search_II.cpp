//https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/543/week-5-june-29th-june-30th/3376/

struct TrieNode {
    TrieNode* characters[26];
    string w;
};
class Solution {
private: 
    TrieNode* root;
    
    TrieNode* getNode () {
        TrieNode* root = new TrieNode;
        
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
        temp -> w = word;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> sol;
        root = getNode();
        int i, j;
        
        for(i = 0; i < words.size(); i++)
            insert(words[i]);
        
        for(i = 0; i < board.size(); i++) {
            for(j = 0; j < board[0].size(); j++) {
                DFS(board, i, j, root, sol);
            }
        }
        
        // vector<string> ans(sol.begin(), sol.end());
        // for(auto itr : sol)
        //     cout << itr << endl;
        return sol;
    }
    
    void DFS(vector<vector<char>> board, int i, int j, TrieNode* root, vector<string>& sol) {
        char c = board[i][j];
        if(c == '*' || root -> characters[c - 'a'] == NULL)
            return;
        
        root = root -> characters[c - 'a'];
        if((root -> w).size() > 0) {
            // cout << "found" << endl;
            sol.push_back(root -> w);
            root -> w = "";
        }
            
        
        board[i][j] = '*';
        
        if(i > 0) DFS(board, i - 1, j, root, sol);
        if(j > 0) DFS(board, i, j - 1, root, sol);
        if(i < board.size() - 1) DFS(board, i + 1, j, root, sol);
        if(j < board[0].size() - 1) DFS(board, i, j + 1, root, sol);
    }
};