class Solution {
    string res;
    bool loop;
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;

        for (char c = 'a'; c <= 'z'; c++) adj[c] = {};

        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];
            int i1 = 0, i2 = 0;

            while (i1 < w1.size() && i2 < w2.size() && w1[i1] == w2[i2]) {
                i1++; i2++;
            }

            if (i1 == w1.size()) continue;
            if (i2 == w2.size()) return "";
            adj[w1[i1]].push_back(w2[i2]);
        }

        vector<bool> visited(26, false);
        vector<bool> inPath(26, false);

        unordered_set<char> allChars;
        for (string word : words) for (char c : word) allChars.insert(c);

        for (char c = 'a'; c <= 'z'; c++) {
            if (allChars.find(c) == allChars.end()) continue;
            if (visited[c - 'a']) continue;

            loop = false;
            dfs(adj, c, visited, inPath);

            if (loop) return "";
        }

        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(unordered_map<char, vector<char>>& adj, char curr, vector<bool>& visited, vector<bool>& inPath) {
        inPath[curr - 'a'] = true;
        for (char c : adj[curr]) {
            if (visited[c - 'a']) continue;
            if (inPath[c - 'a']) loop = true;
            if (loop) break;

            dfs(adj, c, visited, inPath);
        }
        inPath[curr - 'a'] = false;
        visited[curr - 'a'] = true;
        if (!loop) res += curr;
    }
};
