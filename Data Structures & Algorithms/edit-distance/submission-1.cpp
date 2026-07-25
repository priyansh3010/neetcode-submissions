class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));

        return dfs(dp, word1, word2, 0, 0);
    }

    int dfs(vector<vector<int>>& dp, string& word1, string& word2, int i, int j) {
        if (j == word2.size()) return word1.size() - i; // delete remaining word1 chars
        if (i == word1.size()) return word2.size() - j; // insert remaining word2 chars

        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j]) return dp[i][j] = dfs(dp, word1, word2, i + 1, j + 1);
        else return dp[i][j] = min({dfs(dp, word1, word2, i, j + 1),
                                    dfs(dp, word1, word2, i + 1, j + 1),
                                    dfs(dp, word1, word2, i + 1, j)}) + 1;
    }
};
