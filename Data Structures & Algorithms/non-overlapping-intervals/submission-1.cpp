class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int i = 1;
        int res = 0;
        vector<int> currInterval = intervals[0];
        
        while (i < intervals.size()) {
            if (currInterval[1] > intervals[i][0]) {
                res++;

                if (currInterval[1] > intervals[i][1]) currInterval = intervals[i];
            }
            else currInterval = intervals[i];
            i++;
        }

        return res;
    }
};