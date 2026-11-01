class Solution {
public:
    int findComplement(int num) {
        int temp = num;
        int total_bits = 0;
        while (temp > 0) {//fins the number of bits
            total_bits++;
            temp = temp >> 1;//is equivalent to divide by 2 in decimal temp = temp/2
        }
        for (int bit = 0; bit < total_bits; bit++) {
            num = num ^ (1 << bit);
        }
        return num;
    }
};