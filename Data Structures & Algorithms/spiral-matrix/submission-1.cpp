class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        int left = -1, right = matrix[0].size() - 1;
        int top = 0, bottom = matrix.size() - 1;

        while (true) {
            left++;
            if (left > right) break;
            for (int i = left; i <= right; i++) res.push_back(matrix[top][i]);
            top++;
            if (top > bottom) break;
            for (int i = top; i <= bottom; i++) res.push_back(matrix[i][right]);
            right--;
            if (left > right) break;
            for (int i = right; i >= left; i--) res.push_back(matrix[bottom][i]);
            bottom--;
            if (top > bottom) break;
            for(int i = bottom; i >= top; i--) res.push_back(matrix[i][left]);
        }

        return res;
    }
};
