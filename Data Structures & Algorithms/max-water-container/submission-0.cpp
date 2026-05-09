class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxWater = 0;

        for (int left = 0; left < heights.size(); left++) {
            for (int right = heights.size() - 1; right > left; right--) {
                int currWater = min(heights[left], heights[right]) * (right - left);

                maxWater = max(maxWater, currWater);
            }
        }

        return maxWater;
    }
};
