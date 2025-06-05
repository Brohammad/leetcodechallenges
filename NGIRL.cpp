#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Generate all primes up to max_limit using sieve of Eratosthenes
vector<int> sievePrimes(int max_limit) {
    vector<bool> isPrime(max_limit + 1, true);
    isPrime[0] = false; isPrime[1] = false;
    for (int i = 2; i * i <= max_limit; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= max_limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= max_limit; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    int max_limit = 100000; // sqrt(10^10)
    vector<int> primes = sievePrimes(max_limit);

    while (T--) {
        long long N, K;
        cin >> N >> K;

        int total_choices = 0;
        int liked_gifts = 0;

        for (int p : primes) {
            long long square = 1LL * p * p;
            if (square > N) break;
            total_choices++;
            if (square > K) liked_gifts++;
        }

        cout << total_choices << " " << liked_gifts << "\n";
    }

    return 0;
}
