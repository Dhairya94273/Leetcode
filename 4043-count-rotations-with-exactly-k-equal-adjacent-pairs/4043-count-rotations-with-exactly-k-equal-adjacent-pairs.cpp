class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        
        int total = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == s[(i + 1) % n]) {
                total++;
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            bool boundaryEqual = (s[i] == s[(i + 1) % n]);
            int score = total - (boundaryEqual ? 1 : 0);
            if (score == k) {
                ans++;
            }
        }

        return ans;
    }
};