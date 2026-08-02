class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        int i = 0;
        bool added = false;
        while (i < intervals.size()) {
            if (intervals[i][1] < newInterval[0]) res.push_back(intervals[i]);
            else if (added && intervals[i][0] > newInterval[1]) res.push_back(intervals[i]);
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);

                while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
                    newInterval[1] = max(intervals[i][1], newInterval[1]);
                    i++;
                }

                res.push_back(newInterval);
                added = true;
                continue;
            }
            i++;
        }

        if (!added) res.push_back(newInterval);

        return res;
    }
};