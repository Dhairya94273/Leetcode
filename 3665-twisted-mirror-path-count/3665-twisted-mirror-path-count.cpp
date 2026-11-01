class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int MOD = 1e9 + 7;

        // memo[r][c][dir]
        // -2 = not calculated
        // -1 = invalid
        // otherwise = destination cell encoded as r*n+c
        vector<vector<array<int, 2>>> memo(
            m, vector<array<int, 2>>(n, {-2, -2})
        );

        // dir = 0 : Right
        // dir = 1 : Down
        function<int(int, int, int)> resolve =
        [&](int r, int c, int dir) -> int {

            // Out of bounds
            if (r >= m || c >= n)
                return -1;

            // Already calculated
            if (memo[r][c][dir] != -2)
                return memo[r][c][dir];

            // Empty cell: valid destination
            if (grid[r][c] == 0)
                return memo[r][c][dir] = r * n + c;

            // Mirror: reflect and continue
            if (dir == 0) {
                // Right -> Down
                return memo[r][c][dir] =
                    resolve(r + 1, c, 1);
            }
            else {
                // Down -> Right
                return memo[r][c][dir] =
                    resolve(r, c + 1, 0);
            }
        };

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;

        // Process cells in row-major order
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dp[i][j] == 0)
                    continue;

                // Try moving RIGHT
                int right = resolve(i, j + 1, 0);

                if (right != -1) {
                    int r = right / n;
                    int c = right % n;

                    dp[r][c] = (dp[r][c] + dp[i][j]) % MOD;
                }

                // Try moving DOWN
                int down = resolve(i + 1, j, 1);

                if (down != -1) {
                    int r = down / n;
                    int c = down % n;

                    dp[r][c] = (dp[r][c] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};