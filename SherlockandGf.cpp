#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> color(n + 2);
    vector<bool> isPrime(n + 2, true);
    isPrime[0] = isPrime[1] = false;

    // Sieve to mark primes
    for (int i = 2; i * i <= n + 1; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n + 1; j += i)
                isPrime[j] = false;
        }
    }

    // Assign colors
    int maxColor = (n <= 2) ? 1 : 2;
    for (int i = 2; i <= n + 1; i++) {
        color[i] = isPrime[i] ? 1 : 2;
    }

    cout << maxColor << "\n";
    for (int i = 2; i <= n + 1; i++) {
        cout << color[i] << " ";
    }
    cout << "\n";
    return 0;
}
