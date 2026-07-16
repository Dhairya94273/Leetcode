class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        int n = nums.size();
        vector<int> prefixGcd(n);

        int mx = 0;

        // Step 1: Construct prefixGcd
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }

        // Step 2: Sort prefixGcd
        sort(prefixGcd.begin(), prefixGcd.end());

        // Step 3: Pair smallest with largest and sum their gcd
        long long ans = 0;

        int i = 0, j = n - 1;

        while (i < j) {
            ans += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }

        return ans;
    }
};