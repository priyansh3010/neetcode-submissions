class Solution {
    vector<string> result;
public:
    void generate(string& currCombo, int opened, int closed, int n) {
        if (opened == closed && opened == n) {
            result.push_back(currCombo);
            return;
        }

        if (opened < n) {
            currCombo.push_back('(');
            generate(currCombo, opened + 1, closed, n);
            currCombo.pop_back();
        }
        if (closed < opened) {
            currCombo.push_back(')');
            generate(currCombo, opened, closed + 1, n);
            currCombo.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string currCombo = "";

        generate(currCombo, 0, 0, n);
        return result;
    }
};
