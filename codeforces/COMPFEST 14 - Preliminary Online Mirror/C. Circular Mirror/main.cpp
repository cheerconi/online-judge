#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <memory.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long double LD;
typedef long long LL;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#ifdef LOCAL
#define DEBUG(x) { cerr << "# " << #x << ": " << x << endl;}
#else
#define DEBUG(x)
#endif
mt19937_64 mt(time(0));
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/
const int MAXN = 3e5 + 10;
const int mod = 998244353;
LL d[MAXN], fact[MAXN], inv[MAXN];

LL power(LL base, int p) {
    LL ret = 1;
    while (p) {
        if (p&1) ret = ret * base % mod;
        base = base * base % mod;
        p >>= 1;
    }
    return ret;
}

LL combine(int n, int k) {
    return fact[n] * inv[k] % mod * inv[n-k] % mod;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
    inv[MAXN-1] = power(fact[MAXN-1], mod-2);
    for (int i = MAXN-2; i >= 0; i--) {
        inv[i] = inv[i+1] * (i+1) % mod;
    }

    LL n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        d[i] += d[i-1];
    }
    int cnt = 0;
    if (d[n] % 2 == 0) {
        LL half = d[n]/2;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (d[i] >= half) break;
            while (j < n && d[j]-d[i] < half) {
                j++;
            }
            if (j < n && d[j]-d[i] == half) {
                cnt++;
            }
        }
    }
    LL ret = 0;
    for (int i = 0; i <= cnt && i <= m; i++) {
        LL tmp = combine(cnt, i) * combine(m, i) % mod;
        tmp = tmp * fact[i] % mod;
        if (cnt - i > 0) {
            if (m-i <= 1) continue;
            tmp = tmp * power((m-i) * (m-i-1) % mod, cnt-i) % mod;
        }
        if (n-cnt*2 > 0) {
            if (m-i == 0) break;
            tmp = tmp * power(m-i, n-cnt*2) % mod;
        }
        ret = (ret + tmp) % mod;
    }
    cout << ret << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
