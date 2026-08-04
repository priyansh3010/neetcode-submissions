class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> ogQueries = queries;
        sort(queries.begin(), queries.end());
        sort(intervals.begin(), intervals.end());

        int i = 0;
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);

        unordered_map<int, int> temp;
        for (int query : queries) {
            while (!minHeap.empty() && minHeap.top()[1] < query) minHeap.pop();
            while (i < intervals.size() && intervals[i][0] <= query) {
                int length = intervals[i][1] - intervals[i][0] + 1;
                if (intervals[i][1] >= query) minHeap.push({length, intervals[i][1]});
                i++;
            }

            if (!minHeap.empty()) {
                temp[query] = minHeap.top()[0];
            }
        }

        vector<int> res(ogQueries.size(), -1);
        for (int i = 0; i < ogQueries.size(); i++) {
            if (temp.find(ogQueries[i]) != temp.end()) res[i] = temp[ogQueries[i]];
        }

        return res;
    }
};
