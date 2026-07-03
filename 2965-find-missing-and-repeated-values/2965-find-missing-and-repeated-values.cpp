class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        int n = grid.size();
        unordered_set<int> s;
        int a,b;

        int actual_sum = 0 , grid_sum  = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid_sum += grid[i][j];
                if (s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }
        actual_sum = (n*n) * ((n*n) + 1) / 2;
        b = actual_sum  + a - grid_sum;
        ans.push_back(b);
        return ans;
    }
};