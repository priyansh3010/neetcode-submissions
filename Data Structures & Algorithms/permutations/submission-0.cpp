class Solution {
    vector<vector<int>> result;
public:
    void generatePermutes(vector<int>& nums, int index, vector<int>& temp, unordered_set<int>& tracker) {
        if (index == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (tracker.find(nums[i]) != tracker.end()) continue;

            temp.push_back(nums[i]);
            tracker.insert(nums[i]);
            generatePermutes(nums, index + 1, temp, tracker);
            temp.pop_back();
            tracker.erase(nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        unordered_set<int> tracker;
        generatePermutes(nums, 0, temp, tracker);

        return result;
    }
};
