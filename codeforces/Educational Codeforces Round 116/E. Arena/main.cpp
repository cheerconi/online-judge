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
const int MAXN = 500 + 10;
LL fact[MAXN], inv[MAXN];
LL dp[MAXN][MAXN];

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
  int n, x; cin >> n >> x;
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i][1] = 1;
    fact[i] = fact[i-1] * i % mod;
  }
  dp[1][1] = 0;
  for (int j = 1; j <= x; j++) {
    dp[0][j] = 1;
  }
  inv[n] = power(fact[n], mod-2);
  for (int i = n-1; i >= 0; i--) {
    inv[i] = inv[i+1] * (i+1) % mod;
  }
  for (int j = 2; j <= x; j++) {
    for (int i = 2; i <= n; i++) {
      if (j-i+1 <= 0) {
        dp[i][j] = power(j,i);
        continue;
      }
      for (int rem = 0; rem <= i; rem++) {
        LL tmp = combine(i, rem) * power(i-1, i-rem) % mod;
        dp[i][j] = (dp[i][j] + tmp * dp[rem][j-i+1]) % mod;
      }
    }
  }
  cout << dp[n][x] << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
