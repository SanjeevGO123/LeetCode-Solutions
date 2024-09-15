class TrieNode {
public:
    TrieNode* children[26];
    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
    }
    vector<int> search(const string& target, int start) {
        vector<int> result;
        TrieNode* node = root;
        for (int i = start; i < target.size(); ++i) {
            int idx = target[i] - 'a';
            if (node->children[idx] == nullptr)
                break;
            node = node->children[idx];
            result.push_back(i + 1);
        }
        return result;
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        int n = target.size();
        Trie trie;
        for (const string& word : words) {
            trie.insert(word);
        }

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == INT_MAX)
                continue;

            vector<int> matches = trie.search(target, i);
            for (int end : matches) {
                dp[end] = min(dp[end], dp[i] + 1);
            }
        }

        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};