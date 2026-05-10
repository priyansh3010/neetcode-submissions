class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size() - 1;

        int row = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (matrix[mid][0] <= target && matrix[mid][matrix[mid].size() - 1] >= target) {
                row = mid;
                break;
            }
            else if (matrix[mid][0] > target) high = mid - 1;
            else low = mid + 1;
        }

        int left = 0, right = matrix[row].size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] > target) right = mid - 1;
            else left = mid + 1;
        }

        return false;
    }
};
