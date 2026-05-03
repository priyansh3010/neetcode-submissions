class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<vector<int>, vector<vector<int>>, MinHeapCompare> minHeap;

        for (auto interval : intervals) {
            minHeap.push(interval);
        }

        vector<int> currInterval = minHeap.top();
        vector<vector<int>> result;
        while (!minHeap.empty()) {
            vector<int> currTop = minHeap.top();
            minHeap.pop();

            if (currTop[0] <= currInterval[1]) {
                currInterval[1] = max(currInterval[1], currTop[1]);
            }
            else {
                result.push_back(currInterval);
                currInterval = currTop;
            }
        }

        result.push_back(currInterval);
        return result;
    }

    struct MinHeapCompare {
        bool operator()(vector<int> a, vector<int> b) {
            return a[0] > b[0]; 
        }
    };
};
