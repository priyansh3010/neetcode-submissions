class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;

        vector<int> result(temperatures.size());
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!s.empty() && temperatures[i] >= temperatures[s.top()]) s.pop();
            result[i] = s.empty() ? 0 : s.top() - i;
            s.push(i);
        }

        return result;
    }
};
