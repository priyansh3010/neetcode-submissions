class Solution {
public:
    vector<int> partitionLabels(string s) {
        /*
        start = {x: 0, y: 1, z: 5, b: 6, i: 10, s: 11, l: 12}
        end   = {x: 3, y: 4, z: 7, b: 9, i: 10, s: 11, l: 12}
        */

        unordered_map<char, int> start;
        unordered_map<char, int> end;
        vector<char> order;

        for (int i = 0; i < s.size(); i++) {
            if (start.find(s[i]) == start.end()) {
                start[s[i]] = i;
                end[s[i]] = i;
                order.push_back(s[i]);
            }
            else end[s[i]] = i;
        }

        vector<int> res;
        int left = 0, right = 1;        

        int maxEnd = end[order[left]];
        while (right <= order.size()) {
            if (right < order.size() && maxEnd > start[order[right]]) {
                maxEnd = max(maxEnd, end[order[right]]);
                right++;
            }
            else {
                res.push_back(maxEnd - start[order[left]] + 1);
                while (right <= order.size() && maxEnd >= end[order[left]]) left = right++;
                maxEnd = left < order.size() ? end[order[left]] : -1;
            }
        }

        return res;
    }
};
