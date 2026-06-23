class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> dists(n, INT_MAX - 1);
        vector<bool> visited(n, false);

        int result = 0;
        int edges = 0;

        int nextNode = 0;
        while (edges < n - 1) {
            visited[nextNode] = true;
            auto currNode = points[nextNode];
            nextNode = -1;

            for (int i = 0; i < n; i++) {
                if (visited[i]) continue;

                int calc = abs(currNode[0] - points[i][0]) + abs(currNode[1] - points[i][1]);

                dists[i] = min(dists[i], calc);
                if (nextNode == -1 || dists[i] < dists[nextNode]) nextNode = i;
            }
            
            result += dists[nextNode];
            edges++;
        }

        return result;
    }
};
