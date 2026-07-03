class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int freq1 = 0, freq2 = 0;
        int candidate1 = 0, candidate2 = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == candidate1) {
                freq1++; 
            } else if (nums[i] == candidate2) {
                freq2++;
            } else if (freq1 == 0) {
                candidate1 = nums[i];
                freq1 = 1;
            } else if (freq2 == 0) {
                candidate2 = nums[i];
                freq2 = 1;
            } else {
                freq1--;
                freq2--;
            }
        }

        freq1 = 0;
        freq2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == candidate1) {
                freq1++;
            } else if (nums[i] == candidate2) {
                freq2++;
            }
        }

        vector<int> ans;

        if (freq1 > nums.size() / 3) {
            ans.push_back(candidate1);
        }

        if (freq2 > nums.size() / 3) {
            ans.push_back(candidate2);
        }

        return ans;
    }
};