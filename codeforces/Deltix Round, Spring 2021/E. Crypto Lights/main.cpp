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
const int mod = 1e9 + 7;
const int MAXN = 1e5 + 10;
LL fact[MAXN], inv[MAXN];

LL power(LL base, int p) {
  LL ret = 1;
  base = base % mod;
  while (p) {
    if (p&1) ret = ret * base % mod;
    base = base * base % mod;
    p >>= 1;
  }
  return ret;
}

LL combine(int n, int k) {
  if (k < 0 || k > n || n <= 0) return 0;
  LL ret = fact[n] * inv[k] % mod;
  return ret * inv[n-k] % mod;
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int T; cin >> T;
  fact[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fact[i] = fact[i-1] * i % mod;
  }
  inv[MAXN-1] = power(fact[MAXN-1], mod-2);
  for (int i = MAXN-2; i >= 0; i--) {
    inv[i] = inv[i+1] * (i+1) % mod;
  }
  while (T--) {
    int n, k; cin >> n >> k;
    LL ret = 0;
    LL dp = fact[n];
    for (int i = 2; i <= n; i++) {
      if (dp == 0) break;
      int tot = n - (i-1)*(k-1);
      LL tmp = combine(tot, i) * fact[i] % mod * fact[n-i] % mod;
      ret = (ret +  (dp - tmp + mod) % mod * i % mod) % mod;
      dp = tmp;
    }
    cout << ret * inv[n] % mod << '\n';


  }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
