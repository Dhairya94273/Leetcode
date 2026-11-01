class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int, int> freq;

        // Count frequency
        for (int x : nums) {
            freq[x]++;
        }

        vector<int> ans;

        // Keep taking one occurrence of every distinct value
        while (!freq.empty()) {
            vector<int> remove;

            for (auto& p : freq) {
                ans.push_back(p.first);
                p.second--;

                if (p.second == 0) {
                    remove.push_back(p.first);
                }
            }

            // Remove values whose frequency became 0
            for (int x : remove) {
                freq.erase(x);
            }
        }

        return ans;
    }
};