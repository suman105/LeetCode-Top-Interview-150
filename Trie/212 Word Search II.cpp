class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    string word;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
        word = "";
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Build the Trie
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            insertWord(root, word);
        }

        // Result set to store found words
        unordered_set<string> result;

        // Traverse the board
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }

        // Convert the set to a vector
        vector<string> res(result.begin(), result.end());
        return res;
    }

private:
    // Insert a word into the Trie
    void insertWord(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
        node->word = word;
    }

    // DFS to search for words
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, unordered_set<string>& result) {
        // Boundary checks
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#') {
            return;
        }

        char ch = board[i][j];
        int index = ch - 'a';

        // Check if the current character exists in the Trie
        if (node->children[index] == nullptr) {
            return;
        }

        node = node->children[index];

        // If a word is found, add it to the result
        if (node->isEnd) {
            result.insert(node->word);
            node->isEnd = false; // Avoid duplicates
        }

        // Mark the current cell as visited
        board[i][j] = '#';

        // Explore neighboring cells
        dfs(board, i + 1, j, node, result);
        dfs(board, i - 1, j, node, result);
        dfs(board, i, j + 1, node, result);
        dfs(board, i, j - 1, node, result);

        // Backtrack: restore the original character
        board[i][j] = ch;
    }
};
