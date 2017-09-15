#include <iostream>
#include <map>
#include <limits.h>
typedef long long LL;
using namespace std;
LL x, y;
map<LL, int> primes;
const LL inf = 0x7fffffffffffffff;
void factor() {
    LL n = x;
    for (LL i = 2; i*i <= n ; i++) {
        while (n % i == 0) {
            primes[i]++;
            n = n / i;
        }
    }
    if (n != 1) primes[n]++;

}
LL gcd(LL a, LL b) {
    if (b > a) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a%b);
}
void del(LL a) {
    for (LL i = 2; i*i <= a; i++) {
        while (a % i == 0) {
            primes[i]--;
            a = a/ i;
            if (primes[i] == 0) primes.erase(i);
        }
    }
    if (a != 1) primes[a]--;
    if (primes[a] == 0) primes.erase(a);
}

LL solve() {
    if (y == 0) return 0;
    LL tmp = gcd(x, y);
    x = x / tmp;
    y = y / tmp;
    del(tmp);
    LL cnt = inf;
    for (auto it : primes) {
        cnt = min(cnt, y % it.first);
    }
    if (cnt == inf) return y;
    y = y - cnt;
    return cnt + solve();

}

int main() {
//    freopen("test.txt", "r", stdin);
    cin >> x >> y;
    factor();
    cout << solve() << endl;


    return 0;
}