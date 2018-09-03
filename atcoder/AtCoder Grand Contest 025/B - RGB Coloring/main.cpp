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
const int mod = 998244353;
const int MAXN = 3e5 + 10;
LL pw[MAXN], inv[MAXN], fact[MAXN];
LL pwer(LL base, int p) {
    LL ret = 1;
    while (p) {
        if (p&1) ret = ret * base % mod;
        p >>= 1;
        base = base * base % mod;
    }
    return ret;
}

LL combine(int n, int k) {
    LL ret = fact[n];
    ret = ret * inv[k] % mod;
    ret = ret * inv[n-k] % mod;
    return ret;
}
LL combine(int n, int a, int b) {
    LL ret = fact[n];
    ret = ret * inv[a] % mod;
    ret = ret * inv[b] % mod;
    ret = ret * inv[n-a-b] % mod;
    return ret;
}



/*-------------------------------------coding area end------------------------------------------*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
    #ifdef LOCAL
        freopen("../test.txt", "r", stdin);
//        freopen("../output.txt", "w", stdout);
    #endif
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
    LL n, a, b, k;
    cin >> n >> a >> b >> k;
    LL ret = 0;
    pw[0] = fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i-1] * i % mod;
        pw[i] = pw[i-1] * 2 % mod;
    }
    inv[MAXN-1] = pwer(fact[MAXN-1], mod-2);
    for (int i = MAXN - 2; i >= 0; i--) {
        inv[i] = inv[i+1] * (i+1) % mod;
    }
    if (a == b) {
        if (k % a != 0) {
            cout << 0 << endl;
            return 0;
        }
        LL tot = k / a;
        for (int i = 0; i <= n && 2*i <= tot; i++) {
            if (tot - i > n) continue;
            LL tmp = combine(n, i, tot-2*i) * pw[tot-2*i] % mod;
            ret = (ret + tmp) % mod;
        }
        cout << ret << endl;
        return 0;

    }
    for (LL x = 0; x <= 2*n; x++) {
        LL delta = x * a - k;
        if (delta % (a-b) != 0) continue;
        LL d = delta / (a-b);
        if (d > n || d < 0) continue;
        LL c = x - d;
        if (c > n || c < 0) continue;
        LL tmp = (combine(n, c) * combine(n, d)) % mod;
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
