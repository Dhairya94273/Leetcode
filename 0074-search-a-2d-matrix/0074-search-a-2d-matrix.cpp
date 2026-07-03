class Solution {
public:
    bool searchinRow(vector<vector<int>>& mat, int target, int row) { //O(logn)
        int cols = mat[0].size();
        int st = 0, end = cols - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (target == mat[row][mid]) {
                return true;
            } else if (target >= mat[row][mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) { //O(logm)
        // Binery Search on Row
        int rows = mat.size(), cols = mat[0].size();
        int startrow = 0, endrow = rows - 1;

        while (startrow <= endrow) {
            int midrow = startrow + (endrow - startrow) / 2;

            if (target >= mat[midrow][0] && target <= mat[midrow][cols - 1]) {
                // found the row => Binary Search on this row
                return searchinRow(mat, target, midrow);

            } else if (target >= mat[midrow][cols - 1]) {
                // down => right
                startrow = midrow + 1;
            } else {
                // up => left
                endrow = midrow - 1;
            }
        }
        return false;
    }
};