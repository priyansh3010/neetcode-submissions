class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));

        return search(dp, text1, text2, 0, 0);
    }

    int search(vector<vector<int>>& dp, string& text1, string& text2, int i1, int i2) {
        if (i1 == text1.size() || i2 == text2.size()) return 0;

        if (dp[i1][i2] > 0) return dp[i1][i2];

        if (text1[i1] == text2[i2]) dp[i1][i2] = search(dp, text1, text2, i1 + 1, i2 + 1) + 1;
        else dp[i1][i2] = max(search(dp, text1, text2, i1 + 1, i2), search(dp, text1, text2, i1, i2 + 1));

        return dp[i1][i2];
    }
};
