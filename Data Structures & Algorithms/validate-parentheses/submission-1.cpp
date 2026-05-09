class Solution {
public:
    bool isValid(string s) {
        stack<char> tracker;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') tracker.push(c);
            else {
                if (c == ')') {
                    if (tracker.size() == 0 || tracker.top() != '(') return false;
                    tracker.pop();
                }
                else if (c == '}') {
                    if (tracker.size() == 0 || tracker.top() != '{') return false;
                    tracker.pop();
                }
                else if (c == ']') {
                    if (tracker.size() == 0 || tracker.top() != '[') return false;
                    tracker.pop();
                }
            }
        }

        return tracker.size() == 0;
    }
};
