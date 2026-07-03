class Solution {
public:
    bool isPerfectSquare(int num) {

        double root = exp(log(num) / 2.0);

        long long x = round(root);

        return x * x == num;
    }
};