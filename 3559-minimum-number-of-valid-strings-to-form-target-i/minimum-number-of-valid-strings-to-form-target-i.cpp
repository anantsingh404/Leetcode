struct TrieNode {
    bool isWord = false;
    unordered_map<char, TrieNode*> children;
};

class Solution {
public:
    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c))
                node->children[c] = new TrieNode();
                node->isWord=true;
            node = node->children[c];
           
        }
        node->isWord = true;
    }

    int minValidStrings(vector<string>& words, string t) {
        int n = t.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        TrieNode* root = new TrieNode();
        for (string& word : words) insert(root, word);

        for (int i = 0; i < n; ++i) {
            if (dp[i] == INT_MAX) continue;
            TrieNode* node = root;
            for (int j = i; j < n; ++j) {
                char c = t[j];
                if (!node->children.count(c)) break;
                node = node->children[c];
                if (node->isWord)
                    dp[j + 1] = min(dp[j + 1], dp[i] + 1);
            }
        }

        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};
