class Solution {
public:
    struct MinHeapCompare {
        bool operator()(Interval a, Interval b) {
            return a.start > b.start;
        }
    };

    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<Interval, vector<Interval>, MinHeapCompare> minHeap;

        for (auto interval : intervals) minHeap.push(interval);

        vector<int> rooms;
        while (!minHeap.empty()) {
            Interval currInterval = minHeap.top();
            minHeap.pop();
            if (rooms.size() == 0) rooms.push_back(currInterval.end);
            else {
                bool roomFound = false;
                for (int i = 0; i < rooms.size(); i++) {
                    if (rooms[i] <= currInterval.start) {
                        roomFound = true;
                        rooms[i] = currInterval.end;
                        break;
                    }
                }
                if (!roomFound) rooms.push_back(currInterval.end);
            }
        }

        return rooms.size();
    }
};