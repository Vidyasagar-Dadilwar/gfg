class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if (right < 2) return {-1, -1}; 
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false; 

        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> primes;
        for (int i = max(left, 2); i <= right; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
        if (primes.size() < 2) return {-1, -1}; 
        int minDiff = INT_MAX;
        vector<int> result = {-1, -1};

        for (size_t i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result = {primes[i - 1], primes[i]};
            }
        }

        return result;
    }
};