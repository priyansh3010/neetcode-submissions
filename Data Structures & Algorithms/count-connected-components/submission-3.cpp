class Solution {
    int count;
    vector<vector<int>> sortedEdges;
public:
    void dfs(vector<vector<int>> sortedEdges, vector<int>& explored, int edge) {
        if (explored[edge] == 1 || explored[edge] == 2) return;

        explored[edge] = 1;
        for (int e : sortedEdges[edge]) dfs(sortedEdges, explored, e);
        explored[edge] = 2;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> sortedEdges(n);
        count = 0;
        vector<int> explored(n, 0);

        for (auto edge : edges) {
            sortedEdges[edge[0]].push_back(edge[1]);
            sortedEdges[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < edges.size(); i++) {
            if (explored[edges[i][1]] == 2) continue;

            dfs(sortedEdges, explored, edges[i][1]);
            count++;
        }

        for (int edge : explored) if (edge == 0) count++;
        return count;
    }
};
