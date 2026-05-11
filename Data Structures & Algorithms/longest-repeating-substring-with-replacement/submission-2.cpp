class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        vector<int> freq(26, 0);

        int actualK = k;
        int maxChar = s[0] - 'A';
        int maxFreq = 0;
        int maxCount = 0;

        while (right < s.size()) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            if ((right - left + 1) - maxFreq > k) {
                while (left < right && (right - left + 1) - maxFreq > k) {
                    freq[s[left] - 'A']--;
                    left++;
                }

                maxFreq = -1;
                for (int i = 0; i < 26; i++) maxFreq = max(maxFreq, freq[i]);
            }

            maxCount = max(maxCount, right - left + 1);
            right++;
        }

        return maxCount;
    }
};
