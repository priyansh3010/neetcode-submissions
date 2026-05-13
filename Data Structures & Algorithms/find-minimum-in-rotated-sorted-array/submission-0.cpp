class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        int lowest = nums[0];
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[right]) right = mid - 1;
            else left = mid + 1;
            lowest = min(lowest, nums[mid]);
        }

        // [3,2,1]

        return lowest;
    }
};
