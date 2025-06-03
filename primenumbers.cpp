#include <iostream>
#include <vector>
using namespace std;

vector<bool> sieve(int n){
    vector<bool> primes(n+1, true);
    primes[0] = primes[1] = false;

    for(int i = 2; i * 1LL * i <= n; ++i){
        if(primes[i]){
            for(long long j = 1LL * i * i; j <= n; j += i){
                primes[j] = false;
            }
        }
    }
    return primes;
}

int main(){
    int n = 1e8;
    vector<bool> isPrime = sieve(n);

    int count = 0;
    for(int i = 2; i < n; ++i){
        if(isPrime[i]){
            ++count;
            if(count % 100 == 1){ // 1st, 101st, 201st, ...
                cout << i << "\n";
            }
        }
    }

    return 0;
}
