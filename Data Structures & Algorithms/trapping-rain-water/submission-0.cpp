class Solution {
public:
    int trap(vector<int>& height) {

        vector<int> leftMaxes(height.size());
        vector<int> rightMaxes(height.size());

        int temp = 0;
        for (int i = 0; i < height.size(); i++) {
            leftMaxes[i] = temp;
            temp = max(temp, height[i]);
        }
        temp = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            rightMaxes[i] = temp;
            temp = max(temp, height[i]);
        }

        int total = 0;
        for (int i = 0; i < height.size(); i++) {
            int curr = min(leftMaxes[i], rightMaxes[i]) - height[i];
            if (curr > 0) total += curr;
        }

        return total;
    }
};
