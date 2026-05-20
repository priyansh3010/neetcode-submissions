class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<vector<int>, long long int>, vector<pair<vector<int>, long long int>>, CustomMaxHeap> maxHeap;

        for (auto& point : points) {
            long long int x = point[0];
            long long int y = point[1];

            long long int distance = (x * x) + (y * y);

            if (maxHeap.size() < k) {
                pair<vector<int>, long long int> temp = {point, distance};
                maxHeap.push(temp);
            }
            else {
                if (maxHeap.top().second > distance) {
                    maxHeap.pop();
                    pair<vector<int>, long long int> temp = {point, distance};
                    maxHeap.push(temp);
                }
            }
        }

        vector<vector<int>> result;

        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().first);
            maxHeap.pop();
        }

        return result;
    }

    struct CustomMaxHeap {
        bool operator()(pair<vector<int>, long long int>& a, pair<vector<int>, long long int>& b) {
            return a.second < b.second;
        }
    };
};
