class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> hashMap;

        int largest = -1;
        for (int i = 0; i < s.size(); i++) {
            if (hashMap.find(s[i]) == hashMap.end()) hashMap[s[i]] = i;
            else largest = max(i - hashMap[s[i]] - 1, largest);
        }

        return largest;
    }
};