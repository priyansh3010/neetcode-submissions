class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProducts(nums.size());
        vector<int> rightProducts(nums.size());

        // update right products
        int calculate = 1;
        for (int i = 0; i < nums.size(); i++) {
            rightProducts[i] = calculate;
            calculate *= nums[i];
        }

        // update left products
        calculate = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            leftProducts[i] = calculate;
            calculate *= nums[i];
        }

        vector<int> answer(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            answer[i] = leftProducts[i] * rightProducts[i];
        }

        return answer;
    }
};
