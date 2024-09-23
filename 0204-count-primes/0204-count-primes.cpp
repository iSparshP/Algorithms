class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;  // There are no primes less than 2
        int count = 0;
        vector<bool> check(n, true);  // Initialize size n
        check[0] = false;
        check[1] = false;
        
        for (int i = 2; i < n; i++) {
            if (check[i]) {
                count++;
                if ((long long)i * i < n) {  // Avoid overflow by checking the range
                    for (int j = i * i; j < n; j += i) {
                        check[j] = false;
                    }
                }
            }
        }
        return count;
    }
};
