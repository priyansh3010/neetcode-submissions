class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Freq(26);

        for (char c : s1) {
            s1Freq[c - 'a']++;
        }

        int left = 0; int right = 0;
        vector<int> s2Freq(26);

        for (int i = 0; i < min(s1.size(), s2.size()); i++) {
            s2Freq[s2[i] - 'a']++;
            right++;
        }

        int n = s1.size();

        while (right < s2.size()) {
            if (s1Freq == s2Freq) return true;

            s2Freq[s2[left] - 'a']--;
            left++;
            
            s2Freq[s2[right] - 'a']++;
            right++;
        }

        return s1Freq == s2Freq;
    }
};
