class Solution {
public:
    int sumBase(int n, int k) {
        int sum = 0;
        if(n == k){
            return 1;
        }
        if(k>n){
            return n;
        }
        while(n>0){
            int rem = n%k;
            n= n/k;
            sum = sum + rem;
        }   
        return sum;
    }
};