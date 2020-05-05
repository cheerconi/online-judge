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
const int MAXN = 400000 + 123;

LL fact[MAXN], inv[MAXN];

LL power(LL base, LL p) {
  LL ret = 1;
  base = base % mod;
  while (p) {
    if (p&1) ret = base * ret % mod;
    p >>= 1;
    base = base * base % mod;
  }
  return ret;
}

LL combine(LL n, LL k) {
  LL ret = fact[n] * inv[k] % mod * inv[n-k] % mod;
  return ret;
}

LL solve(LL n, LL k) {
  if (k > n-1) return 0;
  LL b = n - k;
  LL ret = 0;
  for (int j = 0; j <= b; j++) {
    LL tmp =  combine(b, j) * power(b-j, n) % mod;
    if (j % 2 == 1) tmp = (mod - tmp) % mod;
    ret = (ret + tmp) % mod;
  }
  ret = ret  % mod;
  ret = ret * combine(n, b) % mod;
  if (b != n) ret = ret * 2 % mod;
  return ret;
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  LL n, k; cin >> n >> k;
  fact[0] = 1;
  for (LL i = 1; i <= 2*n; i++) {
    fact[i] = fact[i-1] * i % mod;
  }
  inv[2*n] = power(fact[2*n], mod-2);
  for (LL i = 2*n-1; i >= 0; i--) {
    inv[i] = inv[i+1] * (i+1) % mod;
  }
  cout << solve(n, k) << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
