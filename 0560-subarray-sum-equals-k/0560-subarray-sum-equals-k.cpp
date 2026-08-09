class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        if(n==0) return 0;
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        unordered_map<int, int> freq;
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (prefixSum[j] == k) {
                count++;
            }
            int val = prefixSum[j] - k;
            if (freq.find(val) != freq.end()) {
                count += freq[val];
            }

            freq[prefixSum[j]]++;
        }
        return count;
    }
};