class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> maxTracker;

        int left = 0; int right = 0;

        for (int i = 0; i < k; i++) {
            maxTracker[nums[i]]++;
            right++;
        }

        vector<int> result;
        while (right < nums.size()) {
            int currMax = maxTracker.rbegin()->first;
            result.push_back(currMax);

            if (maxTracker[nums[left]] == 1) maxTracker.erase(nums[left]);
            else maxTracker[nums[left]]--;
            left++;

            maxTracker[nums[right]]++;
            right++;
        }
        int currMax = maxTracker.rbegin()->first;
        result.push_back(currMax);

        return result;
    }
};
