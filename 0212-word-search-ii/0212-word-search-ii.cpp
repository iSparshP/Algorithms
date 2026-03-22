class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {};
        string word = "";
    };

    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                if (!node->children[c - 'a']) {
                    node->children[c - 'a'] = new TrieNode();
                }
                node = node->children[c - 'a'];
            }
            node->word = word;
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node,
             vector<string>& ans) {
        char c = board[i][j];

        if (c == '#' || !node->children[c - 'a'])
            return;

        node = node->children[c - 'a'];

        if (node->word != "") {
            ans.push_back(node->word);
            node->word = "";
        }

        board[i][j] = '#';

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && nj >= 0 && ni < board.size() &&
                nj < board[0].size()) {
                dfs(board, ni, nj, node, ans);
            }
        }

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> ans;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, ans);
            }
        }

        return ans;
    }
};