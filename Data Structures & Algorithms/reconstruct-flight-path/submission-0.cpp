class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for (auto& ticket : tickets) {
            adj[ticket[0]];
        }

        sort(tickets.begin(), tickets.end());
        for (auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }

        vector<string> result = {"JFK"};
        dfs(adj, "JFK", result, tickets.size() + 1);
        return result;
    }

    bool dfs(unordered_map<string, vector<string>>& adj, string curr, vector<string>& result, int targetSize) {
        if (result.size() == targetSize) return true;

        if (adj.find(curr) == adj.end()) return false;

        vector<string> temp = adj[curr];
        for (int i = 0; i < temp.size(); i++) {
            string v = temp[i];
            adj[curr].erase(adj[curr].begin() + i);
            result.push_back(v);
            if (dfs(adj, v, result, targetSize)) return true;
            adj[curr].insert(adj[curr].begin() + i, v);
            result.pop_back();
        }

        return false;
    }
};
