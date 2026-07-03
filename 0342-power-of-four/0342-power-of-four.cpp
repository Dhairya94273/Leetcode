class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;

        double x = log(n) / log(4); // log4(n) = log(n)/log(4)

        return abs(x - round(x)) < 1e-10;
    }
};