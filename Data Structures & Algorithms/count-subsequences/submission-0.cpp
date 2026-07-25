class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size()) return 0;
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));

        return dfs(dp, s, t, 0, 0);
    }

    int dfs(vector<vector<int>>& dp, string& s, string& t, int i, int j) {
        if (j == t.size()) return 1;
        if (i == s.size()) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) dp[i][j] = dfs(dp, s, t, i + 1, j + 1) + dfs(dp, s, t, i + 1, j);
        else dp[i][j] = dfs(dp, s, t, i + 1, j);

        return dp[i][j];
    }
};
