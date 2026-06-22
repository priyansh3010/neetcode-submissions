class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, deque<string>> adj;
        for (auto& ticket : tickets) 
            adj[ticket[0]].push_back(ticket[1]);
        
        for (auto& [src, dests] : adj) 
            sort(dests.rbegin(), dests.rend());
        
        vector<string> result;
        dfs("JFK", adj, result);
        reverse(result.begin(), result.end());
        return result;
    }

    void dfs(string src, unordered_map<string, deque<string>>& adj, vector<string>& result) {
        while (!adj[src].empty()) {
            string dst = adj[src].back();
            adj[src].pop_back();
            dfs(dst, adj, result);
        }
        result.push_back(src);
    }
};
