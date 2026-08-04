class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minElement = *min_element(nums.begin(),nums.end());
        int maxElement = *max_element(nums.begin() , nums.end());

        vector<bool> exist(maxElement-minElement + 1);

        for(int i=0 ; i<nums.size() ; i++){
            exist[nums[i]-minElement] = true;
        }

        vector<int> ans;
        for(int i=0 ; i<maxElement-minElement ; i++){
            if(!exist[i]){
                ans.push_back(i+minElement);
            }
        }
        return ans;
    }
};