class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> vertices(n);

        for (auto const& edge : edges) {
            vertices[edge[0]].push_back(edge[1]);
            vertices[edge[1]].push_back(edge[0]);
        }

        int count = 0;
        // [[1], [0, 2], [1], [4], [3]]
        vector<int> state(n, 0); // 0 - unvisted, 1 - visitng in current dfs, 2 - visited
        for (int i = 0; i < n; i++) {
            if (state[i] == 2) continue; 

            state[i] = 1;
            dfs(vertices, i, -1, state);

            count++;
        }

        return count;
    }

    void dfs(vector<vector<int>>& vertices, int currEdge, int parent, vector<int>& state) {
        for (int vertex : vertices[currEdge]) {
            if (vertex == parent) continue;
            if (state[vertex] == 1 || state[vertex] == 2) continue;

            state[vertex] = 1;
            dfs(vertices, vertex, currEdge, state);
        }

        state[currEdge] = 2;
    }
};
