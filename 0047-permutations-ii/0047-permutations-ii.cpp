class Solution {
public:
    void getPermutations(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back({nums});
            return;
        }
        unordered_set<int> s;
        for (int i = idx; i < nums.size(); i++) {
            if(s.count(nums[i])){
                continue;
            }
            s.insert(nums[i]);
            swap(nums[idx], nums[i]);
            getPermutations(nums, idx + 1, ans);
            swap(nums[idx], nums[i]); // backtracking
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        getPermutations(nums, 0, ans);
        return ans;
    }
};
