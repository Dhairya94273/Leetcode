class Solution {
public:
    int gcd(int a, int b) {

        while (a > 0 && b > 0) {
            if (a > b)
                a %= b;
            else
                b %= a;
        }

        return (a == 0) ? b : a;
    }

    long long maxPairStrength(vector<int>& nums) {

        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {

            for (int j = i + 1; j < nums.size(); j++) {

                int g = gcd(nums[i], nums[j]);

                long long strength =
                    (1LL * nums[i] * nums[j]) / (1LL * g * g);

                ans = max(ans, strength);
            }
        }

        return ans;
    }
};