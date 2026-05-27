class Solution {
    vector<string> currState;
    vector<string> visited;
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = 0; j < n; j++) temp.push_back('.');
            currState.push_back(temp);
            visited.push_back(temp);
        }

        backtrack(n, 0);
        return res;
    }

    void backtrack(int& n, int row) {
        if (row == n) {
            res.push_back(currState);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (!isAttacked(n, row, col)) {
                currState[row][col] = 'Q';
                backtrack(n, row + 1);
                currState[row][col] = '.';
            }
        }
    }

    bool isAttacked(int& n, int row, int col) {
        // check for vertical attacks
        for (int i = 0; i < row; i++) if (currState[i][col] == 'Q') return true;

        // check for diagnonal attacks
        int i = row - 1, j = col - 1;
        while (i >= 0 && j >= 0) if (currState[i--][j--] == 'Q') return true;
        
        i = row - 1, j = col + 1;
        while (i >= 0 && j < n) if (currState[i--][j++] == 'Q') return true;

        return false;
    }
};
