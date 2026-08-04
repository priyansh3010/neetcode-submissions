class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i + 1; j < matrix[i].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int row = 0; row < matrix.size(); row++) {
            int left = 0, right = matrix[row].size() - 1;

            while (left < right) {
                swap(matrix[row][left], matrix[row][right]);
                left++; right--;
            }
        }
    }
};
