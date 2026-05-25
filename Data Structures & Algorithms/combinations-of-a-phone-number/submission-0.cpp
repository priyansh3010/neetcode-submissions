class Solution {
    vector<string> keypad = {
        {"abc"},
        {"def"},
        {"ghi"},
        {"jkl"},
        {"mno"},
        {"pqrs"},
        {"tuv"},
        {"wxyz"}
    };
    vector<string> result;
    string curr;
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        curr = "";

        helper(digits, 0);
        return result;
    }

    void helper(string& digits, int index) {
        if (index == digits.size()) {
            result.push_back(curr);
            return;
        }

        int num = digits[index] - '0';
        for (char c : keypad[num - 2]) {
            curr.push_back(c);
            helper(digits, index + 1);
            curr.pop_back();
        }
    }
};
