class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjacency(n + 1); // ignore 0th index

        for (auto const& time : times) 
            adjacency[time[0]].push_back({time[1], time[2]});

        unordered_set<int> visited;

        int time = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, k});

        while (!minHeap.empty()) {
            auto curr = minHeap.top(); minHeap.pop();

            if (visited.find(curr.second) != visited.end()) continue;
            visited.insert(curr.second);

            time = curr.first;

            for (auto const& edge : adjacency[curr.second]) {
                if (visited.find(edge.first) != visited.end()) continue;
                minHeap.push({time + edge.second, edge.first});
            }
        }

        return visited.size() == n ? time : -1;
    }
};
