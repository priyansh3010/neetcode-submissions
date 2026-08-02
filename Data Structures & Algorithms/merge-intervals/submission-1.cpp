class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        vector<int> currInterval = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (currInterval[1] < intervals[i][0]) {
                res.push_back(currInterval);
                currInterval = intervals[i];
            }
            else currInterval[1] = max(currInterval[1], intervals[i][1]);
        }
        res.push_back(currInterval);

        return res;
    }
};