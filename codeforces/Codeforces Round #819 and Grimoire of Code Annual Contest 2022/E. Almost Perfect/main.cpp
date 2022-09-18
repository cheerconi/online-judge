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
const int mod = 998244353;
const int MAXN = 3e5 + 10;
LL dp[MAXN], fact[MAXN], inv[MAXN], p[MAXN], f[MAXN];

LL power(LL base, int p) {
    LL val = 1;
    base = base % mod;
    while (p) {
        if (p&1) val = val * base % mod;
        base = base * base % mod;
        p >>= 1;
    }
    return val;
}

LL combine(int n, int k) {
    return fact[n] * inv[k] % mod * inv[n-k] % mod;
}

LL solve(int n) {
    LL val = 0;
    for (int i = 0; i <= n; i += 4) {
        int j = i/2;
        int m = n - i + j;
        LL tmp = combine(m, j) * p[i/4] % mod;
        if (j-1 >= 1) tmp = tmp * f[j-1] % mod;
        tmp = tmp * dp[n-i] % mod;
        val = (tmp + val) % mod;
    }
    return val;
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        dp[i] = (dp[i-1] + dp[i-2] * (i-1) % mod) % mod;
    }
    fact[0] = 1;
    p[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i-1] * i % mod;
        p[i] = p[i-1] * 2 % mod;
    }
    f[1] = 1;
    for (int i = 3; i < MAXN; i += 2) {
        f[i] = f[i-2] * i % mod;
    }
    inv[MAXN-1] = power(fact[MAXN-1], mod-2);
    for (int i = MAXN-2; i >= 0; i--) {
        inv[i] = inv[i+1] * (i+1) % mod;
    }
    int t; cin >> t;
    int n;
    while (t--) {
        cin >> n;
        cout << solve(n) << endl;
    }




/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
