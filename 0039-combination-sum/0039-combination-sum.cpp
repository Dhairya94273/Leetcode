class Solution {
public:
    set<vector<int>>s;
    void sum(vector<int> &arr, int i, vector<int> &combination, vector<vector<int>> &ans, int target) {
        if(i == arr.size() || target < 0){
            return;
        }
        if(target == 0){
            if(s.find(combination) == s.end()){
                ans.push_back(combination);
                s.insert(combination);
            }
            return;
        }
        combination.push_back(arr[i]);
        sum(arr, i + 1, combination, ans, target - arr[i]); // one time include call
         sum(arr, i, combination, ans, target - arr[i]); // multipal include call therefore i remain same

        combination .pop_back(); // backtrack to remove an last element for exclude
        sum(arr, i + 1, combination, ans, target);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        sum(arr, 0, combination, ans, target);
        return ans;
    }
};