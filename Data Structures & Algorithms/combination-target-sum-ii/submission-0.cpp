class Solution {
    vector<vector<int>> result;
public:
    void generate(vector<int>& candidates, vector<int>& curr, int target, int currSum, int index, unordered_set<int>& dupChecker) {
        if (currSum >= target || index == candidates.size()) {
            if (currSum == target) result.push_back(curr);
            return; 
        }

        if (dupChecker.find(index) == dupChecker.end()) {
            currSum += candidates[index];
            curr.push_back(candidates[index]);
            dupChecker.insert(index);

            generate(candidates, curr, target, currSum, index + 1, dupChecker);

            currSum -= candidates[index];
            curr.pop_back();
            dupChecker.erase(index);
            
            int explored = candidates[index];
            while (index + 1 < candidates.size() && candidates[index + 1] == explored) index++;
        }

        generate(candidates, curr, target, currSum, index + 1, dupChecker);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        unordered_set<int> tracker;

        generate(candidates, curr, target, 0, 0, tracker);
        return result;
    }
};
