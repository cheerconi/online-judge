#include <iostream>
#include <climits>
#include <memory.h>
#include <random>
#include <ctime>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
#ifdef LOCAL
    #define DEBUG(x) { cerr << "# " << #x << ": " << x << endl;}
#else
    #define DEBUG(x)
#endif
mt19937_64 mt(time(0));
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
const int MAXN = 1e6 + 10;
const int mod = 998244353;
LL fact[MAXN], inv[MAXN], pow3[MAXN], inv3[MAXN];

LL power(LL base, LL p) {
    base = base % mod;
    LL ret = 1;
    while (p) {
        if (p & 1) ret = ret * base % mod;
        p >>= 1;
        base = base * base % mod;
    }
    return ret;
}

void make_table() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
    inv[MAXN-1] = power(fact[MAXN-1], mod-2);
    for (int i = MAXN-2; i >= 0; i--) {
        inv[i] = inv[i+1] * (i+1) % mod;
    }
    pow3[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pow3[i] = pow3[i-1] * 3 % mod;
    }
    inv3[MAXN-1] = power(pow3[MAXN-1], mod-2);
    for (int i = MAXN-2; i >= 0; i--) {
        inv3[i] = inv3[i+1] * 3 % mod;
    }
}

LL combine(int n, int k) {
    LL ret = fact[n] * inv[k] % mod;
    ret = ret * inv[n-k] % mod;
    return ret;
}





/*-------------------------------------coding area end------------------------------------------*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
    #ifdef LOCAL
        freopen("../test.txt", "r", stdin);
//        freopen("../outppowut.txt", "w", stdout);
    #endif
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
    LL n; cin >> n;
    make_table();
    LL ret = 0;
    for (int j = 1; j <= n; j++) {
        LL tmp = 2LL * combine(n, j) % mod * power(3, n*(n-j)) % mod * power(3, j) % mod;
        if (j % 2 == 0) tmp = mod - tmp;
        ret = (ret + tmp) % mod;
    }
    for (int i = 1; i <= n; i++) {
        LL cur = combine(n, i) % mod * power(3, n*n-n*i+1) % mod;
        if (i % 2 == 0)  cur = mod - cur;
        LL tmp = 1 - inv3[n-i];
        if (tmp < 0) tmp += mod;
        tmp = power(tmp, n) - 1;
        if (tmp < 0) tmp += mod;
        tmp = cur * tmp % mod;
        ret = (ret + tmp) % mod;
    }
    cout << ret << endl;




/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
