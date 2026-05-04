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

        for (int i = 0; i < n; i++) {
            if (explored[i] == 2) continue;

            dfs(sortedEdges, explored,i);
            count++;
        }
        return count;
    }
};
