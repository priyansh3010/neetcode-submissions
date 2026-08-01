class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> curr = triplets[0];
        for (int i = 1; i < triplets.size(); i++) {
            if (curr[0] > target[0] || curr[1] > target[1] || curr[2] > target[2]) {
                curr = triplets[i];
                continue;
            }
            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]) 
                continue;

            curr[0] = max(curr[0], triplets[i][0]);
            curr[1] = max(curr[1], triplets[i][1]);
            curr[2] = max(curr[2], triplets[i][2]);

            if (curr == target) return true;
        }        

        return curr == target;
    }
};
