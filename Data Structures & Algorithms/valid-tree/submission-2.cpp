class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> vertices(n);

        for (auto const& edge : edges) {
            vertices[edge[0]].push_back(edge[1]);
            vertices[edge[1]].push_back(edge[0]);
        }
        
        vector<int> state(n, 0); // 0 - unvisted, 1 - visitng, 2 - visited with no loops

        bool looped = false;
        state[0] = 1;
        dfs(vertices, 0, -1, state, looped);

        if (looped) return false;

        for (int i = 0; i < n; i++) 
            if (state[i] != 2) return false;

        return true;
    }

    void dfs(vector<vector<int>>& vertices, int currEdge, int parent, vector<int>& state, bool& looped) {
        for(auto const& vertex : vertices[currEdge]) {
            if (vertex == parent || state[vertex] == 2) continue;
            if (state[vertex] == 1) {
                looped = true;
                return;
            }

            state[vertex] = 1;
            dfs(vertices, vertex, currEdge, state, looped);
        }

        state[currEdge] = 2;
    }
};
