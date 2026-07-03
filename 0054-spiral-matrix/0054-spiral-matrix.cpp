class Solution {
public:
    vector<int>
    spiralOrder(vector<vector<int>>& mat) { // m=> total row , n=> total cols
        int m = mat.size(), n = mat[0].size();
        int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;
        vector<int> ans;

        while (srow <= erow && scol <= ecol) {
            for (int j = scol; j <= ecol; j++) { // top
                ans.push_back(mat[srow][j]);
            }
            for (int i = srow + 1; i <= erow; i++) { // right
                ans.push_back(mat[i][ecol]);
            }
            for (int j = ecol - 1; j >= scol; j--) { // bottom
                if (srow == erow) {
                    break;
                }
                ans.push_back(mat[erow][j]);
            }
            for (int i = erow - 1; i >= srow + 1; i--) { // left
                if (scol == ecol) {
                    break;
                }
                ans.push_back(mat[i][scol]);
            }
            srow++;
            erow--;
            scol++;
            ecol--;
        }
        return ans;
    }
};