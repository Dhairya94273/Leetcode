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
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx - 1]) {
            idx++;
        }
        // Exclude
        getAllSubsets(ans, nums, idx, allSubsets);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> allSubsets;
        vector<int> ans;

        getAllSubsets(ans, nums, 0, allSubsets);

        return allSubsets;
    }
};