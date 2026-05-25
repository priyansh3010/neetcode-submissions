class Solution {
    vector<vector<string>> result;
    vector<string> currCombo;
    string curr;
public:
    vector<vector<string>> partition(string s) {
        curr = "";
        generate(s, 0);

        return result;
    }

    void generate(string& s, int index) {
        if (index == s.size()) {
            result.push_back(currCombo);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            curr = s.substr(index, i - index + 1);
            if (checkForPalindrome(curr)) {
                currCombo.push_back(curr);
                generate(s, i + 1);
                currCombo.pop_back();
            }
        }
    }

    bool checkForPalindrome(string& s) {
        int left = 0; int right = s.size() - 1;

        while (left < right) if (s[left++] != s[right--]) return false;
        return true;
    }
};
