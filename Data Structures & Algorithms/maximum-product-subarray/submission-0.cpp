class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnd = nums[0];
        int minEnd = nums[0];
        int maxProduct = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];
            int candMax = max({x, maxEnd * x, minEnd * x});
            int candMin = min({x, maxEnd * x, minEnd * x});

            maxEnd = candMax;
            minEnd = candMin;

            maxProduct = max(maxEnd, maxProduct);    
        }

        return maxProduct;
    }
};
