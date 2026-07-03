class Solution {
public:
    void getAllSubsets(vector<int>& ans, vector<int>& nums, int i, vector<vector<int>>& allSubsets) {

        if (i == nums.size()) {
            allSubsets.push_back({ans});
            return;
        }

        // Include
        ans.push_back(nums[i]);
        getAllSubsets(ans, nums, i + 1, allSubsets);

        // Backtrack
        ans.pop_back();

        // Exclude
        getAllSubsets(ans, nums, i + 1, allSubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> allSubsets;
        vector<int> ans;

        getAllSubsets(ans, nums, 0, allSubsets);

        return allSubsets;
    }
};