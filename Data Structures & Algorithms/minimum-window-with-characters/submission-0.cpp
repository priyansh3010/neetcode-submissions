class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tFreq;

        for (char c : t) tFreq[c]++;

        int have = 0;
        int need = tFreq.size();

        int left = 0;
        int right = 0;

        unordered_map<char, int> sFreq;

        int minLeft = 0, minRight = -1; 
        while (right < s.size()) {
            if (tFreq.find(s[right]) == tFreq.end()) {
                right++;
                continue;
            }

            sFreq[s[right]]++;
            if (sFreq[s[right]] == tFreq[s[right]])
                have++;
            
            while (have == need && left <= right) {
                if (minRight == -1 || right - left + 1 < minRight - minLeft + 1) {
                    minLeft = left;
                    minRight = right;
                }

                if (tFreq.count(s[left])) {
                    sFreq[s[left]]--;
                    if (sFreq[s[left]] < tFreq[s[left]]) have--;
                }
                left++;
            }

            right++;
        }

        return minRight == -1 ? "" : s.substr(minLeft, minRight - minLeft + 1);
    }
};
