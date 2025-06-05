#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 1e7 + 1;

vector<bool> sieve(int n) {
    vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * 1LL * i < n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> isPrime = sieve(MAXN);
    vector<int> isValidPrime(MAXN, 0);

    // Precompute all valid primes of the form x^2 + y^4
    for (int x = 1; x * x < MAXN; ++x) {
        for (int y = 1; ; ++y) {
            long long val = 1LL * x * x + 1LL * y * y * y * y;
            if (val >= MAXN) break;
            if (isPrime[val])
                isValidPrime[val] = 1;
        }
    }

    // Build prefix sum of valid primes
    vector<int> prefix(MAXN, 0);
    for (int i = 1; i < MAXN; ++i)
        prefix[i] = prefix[i - 1] + isValidPrime[i];

    // Handle test cases
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << prefix[n] << "\n";#include<iostream>
        #include<vector>
        using namespace std;
        const int maxN=1e7+1;
        vector<bool> sieve(int n){
            vector<bool> primes(n+1,true);
            primes[0]=primes[1]=false;
            for(int i=2;i<=n;i++){
                if(primes[i]){
                    for(int j=i*i;j<=n;j+=i){
                        primes[j]=false;
                    }
                }
            }
            return primes;
        }
        int main(){
            vector<bool> isprime=sieve(1e7+1);
            vector<int> validprime(1e7+1,0);
            for(int x=1;x*x<maxN;x++){
                for(int y=1;;++y){
                    long long val=1LL*x*x+1LL*y*y*y*y;
                    if(val>=maxN)break;
                    if(isprime[val])
                    validprime[val]=1;
                }
            }
            vector<int> prefix(maxN,0);
            for(int i=1;i<maxN;i++)
            prefix[i]=prefix[i-1]+validprime[i];
            int t;
            cin>>t;
            while(t--){
                int n;
                cin>>n;
                cout<<prefix[n]<<"\n";
            }
            return 0;
        }
    }

    return 0;
}
