class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp (s.size() + 1, false);
        dp[s.size()] = true;

        for (int i = s.size() - 1; i >= 0; i--) {
            for (string word : wordDict) {
                if (i + word.size() <= s.size() && s.substr(i, word.size()) == word)
                    dp[i] = dp[i + word.size()];
                if (dp[i]) break; 
            }
        }

        return dp[0];
    }
};
