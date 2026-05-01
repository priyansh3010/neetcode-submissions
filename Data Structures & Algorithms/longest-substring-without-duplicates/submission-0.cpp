class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charTracker;
        int left = 0; 
        int right = 0;

        int maxLen = 0;
        while (right < s.size()) {
            while (charTracker.find(s[right]) != charTracker.end()) {
                charTracker.erase(s[left]);
                left++;
            }
            charTracker.insert(s[right]);
            right++;

            maxLen = max(maxLen, right - left);
        }

        return maxLen;
    }
};
