class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col) {
        int n = board.size();
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void nQuene(vector<string>& board, int row, int n,
                vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back({board});
            return;
        }
        for (int j = 0; j < n; j++) {
            if (isSafe(board, row, j)) {
                board[row][j] = 'Q';
                nQuene(board, row + 1, n, ans);
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        nQuene(board, 0, n, ans);
        return ans;
    }
    int totalNQueens(int n) {
        vector<vector<string>> ans = solveNQueens(n);
        return ans.size();
    }
};