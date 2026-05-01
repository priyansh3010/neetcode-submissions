class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;

        int answer = 0;
        while (right < prices.size()) {
            if (prices[right] < prices[left]) {
                left = right;
            }
            else answer = max(answer, prices[right] - prices[left]);
            right++;
        }

        return max(answer, 0);
    }
};
