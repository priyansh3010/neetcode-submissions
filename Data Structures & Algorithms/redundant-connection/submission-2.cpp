class Solution {
    vector<int> result;
    bool inLoop = false;
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] == x) return x;
        return find(parent, parent[x]);
    }

    void unite(vector<int>& parent, int x, int y) {
        parent[find(parent, x)] = find(parent, y);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size() + 1);
        for (int i = 0; i <= edges.size(); i++) parent[i] = i;

        vector<int> result;
        for (auto edge : edges) {
            if (find(parent, edge[0]) == find(parent, edge[1])) {
                result = edge;
                continue;
            }
            unite(parent, edge[0], edge[1]);
        }        

        return result;
    }
};
