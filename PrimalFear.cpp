#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e6 + 1;

// Step 1: Sieve of Eratosthenes
vector<bool> sieve(int n) {
    vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

// Step 2: Check if number contains digit 0
bool hasZero(int x) {
    while (x > 0) {
        if (x % 10 == 0) return true;
        x /= 10;
    }
    return false;
}

// Step 3: Check if all left-truncations are prime
bool isScaryPrime(int num, const vector<bool>& isPrime) {
    int divisor = 1;
    while (divisor <= num) divisor *= 10; // Get the next power of 10

    while (num > 0) {
        if (!isPrime[num]) return false;
        divisor /= 10;
        num = num % divisor; // Remove the leftmost digit
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> isPrime = sieve(MAXN);

    // Step 4: Precompute scary primes count up to each number
    vector<int> scaryCount(MAXN, 0);

    for (int i = 2; i < MAXN; ++i) {
        scaryCount[i] = scaryCount[i - 1];
        if (!isPrime[i] || hasZero(i)) continue;
        if (isScaryPrime(i, isPrime)) {
            scaryCount[i]++;
        }
    }

    // Step 5: Answer T queries in O(1)
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << scaryCount[N] << "\n";
    }

    return 0;
}
