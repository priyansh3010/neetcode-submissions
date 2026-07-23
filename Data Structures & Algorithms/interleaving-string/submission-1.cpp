class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        vector<vector<bool>> dp(s1.size(), vector<bool>(s2.size(), false));
        vector<vector<bool>> visited(s1.size(), vector<bool>(s2.size(), false));

        return dfs(dp, visited, s1, s2, s3, 0, 0, 0);   
    }

    int dfs(vector<vector<bool>>& dp, vector<vector<bool>>& visited, string& s1, string& s2, string& s3, int i, int j, int k) {
        if (k == s3.size()) return true;

        if (i < s1.size() && j < s2.size() && visited[i][j]) return dp[i][j];

        if (i < s1.size() && j < s2.size()) visited[i][j] = true;

        if (i < s1.size() && s1[i] == s3[k]) if (dfs(dp, visited, s1, s2, s3, i + 1, j, k + 1)) return true;

        if (j < s2.size() && s2[j] == s3[k]) return dfs(dp, visited, s1, s2, s3, i, j + 1, k + 1);

        return false;
    }
};
