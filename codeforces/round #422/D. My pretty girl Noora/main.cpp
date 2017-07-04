#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
static const int MOD = 1000000007;

int main() {
//    freopen("test.txt", "r", stdin);
    LL base, left, right;
    cin >> base >> left >> right;
    vector<LL> primes;
    vector<bool> isprime(right+1, true);
    vector<LL> func(right+1, -1);
    for (LL i = 2; i <= right; i++) {
        if (isprime[i]) {
            func[i] = ((i*(i-1)) >> 1) % MOD;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p*i > right) break;
            isprime[p*i] = false;
            func[p*i] = (func[p]*i + func[i]) % MOD;
            if (i % p == 0) break;
        }

    }
    LL cur = 1;
    LL ret = 0;
    for (int i = left; i <= right; i++) {
        ret = (ret + cur * func[i]) % MOD;
        cur = cur * base % MOD;
    }
    cout << ret << endl;
}