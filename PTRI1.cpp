#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e8 + 5;
vector<bool> isprime(MAXN, true);
unordered_map<int, pair<int, int>> prime_pos;

void build_prime_triangle() {
    isprime[0] = isprime[1] = false;
    for (int i = 2; 1LL * i * i < MAXN; ++i) {
        if (isprime[i]) {
            for (int j = i * i; j < MAXN; j += i)
                isprime[j] = false;
        }
    }

    int row = 1, idx = 0;
    for (int num = 2; num < MAXN; ++num) {
        if (!isprime[num]) continue;
        idx++;
        int r = (int)((sqrt(8 * idx + 1) - 1) / 2);  // inverse of n(n+1)/2
        while (r * (r + 1) / 2 < idx) r++;
        int col = idx - r * (r - 1) / 2;
        prime_pos[num] = {r, col};
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    build_prime_triangle();

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (prime_pos.count(n))
            cout << prime_pos[n].first << " " << prime_pos[n].second << "\n";
        else
            cout << "-1\n";
    }

    return 0;
}
