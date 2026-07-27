class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum=0;
        int n=x;
        while(n>0){
            int temp = n%10;
            n/=10;
            sum+=temp;
        }
        if(x % sum == 0){
            return sum;
        }
        return -1;
    }
};