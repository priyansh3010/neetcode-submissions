class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;

        int n = heights.size();
        int maxArea = 0;
        for (int i = 0; i <= n; i++) {
            int currHeight = i == n ? 0 : heights[i];

            while (!s.empty() && heights[s.top()] > currHeight) {
                int h = heights[s.top()];
                s.pop();

                int left = s.empty() ? -1 : s.top();

                int width = i - left - 1;
                maxArea = max(maxArea, h * width);
            }

            s.push(i);
        }

        return maxArea;
    }
};
