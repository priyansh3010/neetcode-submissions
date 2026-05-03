class Solution {
public:
    struct MinHeapCompare {
        bool operator()(vector<int> a, vector<int> b) {
            if (a[0] != b[0]) return a[0] > b[0];
            else return a[1] > b[1];
        }
    };


    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        priority_queue<vector<int>, vector<vector<int>>, MinHeapCompare> minHeap;

        for (auto interval : intervals) minHeap.push(interval);

        vector<int> currInterval = minHeap.top();
        minHeap.pop();
        int removalCount = 0;
        while (!minHeap.empty()) {
            vector<int> currTop = minHeap.top();
            minHeap.pop();
            if (currTop[0] < currInterval[1]) {
                removalCount++;

                if (currTop[1] < currInterval[1]) {
                    currInterval = currTop;
                }
            } 
            else currInterval = currTop;
        }

        return removalCount;
    }
};
