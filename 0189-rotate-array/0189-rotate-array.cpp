class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) {
            return;
        }

        k = k % n; // if my k is larger then my array size then we just take % so that it can be smaller than array size
        if (k == 0) {//if we don't rotate the array then return same array
            return;
        }

        reverse(nums.begin(), nums.end()); // reverse the array

        reverse(nums.begin(), nums.begin() + k); // reverse the first k element

        reverse(nums.begin() + k, nums.end()); // reverse the remaining element
    }
};