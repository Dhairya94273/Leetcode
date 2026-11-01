class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int max = *max_element(nums.begin() , nums.end());
        int min = *min_element(nums.begin() , nums.end());

        int score = max - min - 2 * k;

        if(score < 0){
            return 0;
        }

        return score;
    }
};