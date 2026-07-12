class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 1) return s[0] == '0' ? 0 : 1;
        
        vector<int> dp(s.size() + 1, 0);

        dp[0] = 1;
        dp[1] = s[0] != '0' ? 1 : 0;

        for (int i = 2; i <= s.size(); i++) {
            if (s[i - 1] != '0') 
                dp[i] += dp[i - 1];

            int twoDigitNum = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (s[i - 2] != '0' && twoDigitNum >= 10 && twoDigitNum <= 26) 
                dp[i] += dp[i - 2];
        }

        return dp[s.size()];
    }
};
