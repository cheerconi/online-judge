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
const int MAXN = 1e6 + 10;
LL fact[MAXN], inv[MAXN];

LL power(LL base, int p) {
  LL ret = 1;
  base = base % mod;
  while (p) {
    if (p&1) ret = ret * base % mod;
    p >>= 1;
    base = base * base % mod;
  }
  return ret;
}

LL combine(int n, int k) {
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
  int n; cin >> n;
  fact[0] = 1;
  for (int i = 1; i <= n+1; i++) {
    fact[i] = fact[i-1] * i % mod;
  }
  inv[n+1] = power(fact[n+1], mod-2);
  for (int i = n; i >= 0; i--) {
    inv[i] = inv[i+1] * (i+1) % mod;
  }
  LL ret = 0;
  for (int i = 0; i < n; i++) {
    int m = n - i;
    if (m%2 == 1) continue;
    if (m < i) break;
    LL tmp = combine(m+1, i);
    if (i >= 2) {
      tmp = (tmp - combine(m-1, i-2) + mod) % mod;
    }
    ret = (ret +  tmp * 2 % mod * fact[m] % mod) % mod;
  }
  cout << ret << '\n';








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
