class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, MaxHeapCompare> maxHeap;

        unordered_map<char, int> freq;
        for (char& task : tasks) freq[task]++;

        for (const auto& [task, freq] : freq) {
            pair<char, int> temp = {task, freq};
            maxHeap.push(temp);
        }

        queue<pair<pair<char, int>, int>> q;
        int count = 0;
        while (!maxHeap.empty() || !q.empty()) {
            pair<char, int> currTask = {'a', -1};
            if (!maxHeap.empty()) {
                currTask = maxHeap.top();
                maxHeap.pop();
                currTask.second--;
            }

            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<pair<char, int>, int> temp = q.front();
                q.pop();
                temp.second--;
                if (temp.second <= 0) maxHeap.push(temp.first);
                else q.push(temp);
            }
            if (currTask.second > 0) {
                pair<pair<char, int>, int> temp = {currTask, n};
                q.push(temp);
            }

            count++;
        }

        return count;
    }

    struct MaxHeapCompare {
        bool operator() (pair<char, int>& a, pair<char, int>& b) {
            return a.second < b.second;
        }
    };
};
