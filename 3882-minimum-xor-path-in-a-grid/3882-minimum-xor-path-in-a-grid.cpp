class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int K = 1024;

        vector<vector<bitset<K>>> dp(
            m, vector<bitset<K>>(n)
        );

        dp[0][0].set(grid[0][0]);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;

                bitset<K> cur;

                if (i > 0) {
                    for (int x = 0; x < K; x++) {
                        if (dp[i - 1][j][x])
                            cur.set(x ^ grid[i][j]);
                    }
                }

                if (j > 0) {
                    for (int x = 0; x < K; x++) {
                        if (dp[i][j - 1][x])
                            cur.set(x ^ grid[i][j]);
                    }
                }

                dp[i][j] = cur;
            }
        }

        for (int x = 0; x < K; x++) {
            if (dp[m - 1][n - 1][x])
                return x;
        }

        return -1;
    }
};