class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& A) {
        sort(A.begin(), A.end());

        int diff = A[1] - A[0];

        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i - 1] != diff)
                return false;
        }

        return true;
    }
};