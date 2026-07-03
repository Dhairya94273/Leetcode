class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);

        if(n > 0) isPrime[0] = false;
        if(n > 1) isPrime[1] = false;

        for(int i = 2;  i < sqrt(n); i++) { // prime numbers are contain between 2 to √n 
            if(isPrime[i] == true) {
                for(int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int count = 0;

        for(int i = 2; i < n; i++) {
            if(isPrime[i] == true)
                count++;
        }

        return count;
    }
};