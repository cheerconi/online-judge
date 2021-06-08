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
const int MAXN = 50;
vector<int> nums;
LL dp[MAXN][MAXN];
LL fact[MAXN], inv[MAXN];

LL power(LL base, int p) {
  base = base % mod;
  LL ret = 1;
  while (p) {
    if (p & 1) ret = ret * base % mod;
    p >>= 1;
    base = base * base % mod;
  }
  return ret;
}

LL combine(int n, int k) {
  LL ret = fact[n] * inv[k] % mod;
  return ret * inv[n-k] % mod;
}

LL solve(int i, int j, int base) {
  if (i > j) return 1;
  if (nums[i] - base != 1) return 0;
  if (i == j) return 1;
  int n = j - i + 1;
  vector<int> ones;
  for (int k = i; k <= j; k++) {
    if (nums[k] - base <= 0) return 0;
    if (nums[k]-base == 1) {
      ones.push_back(k-i);
    }
  }
  LL ret = solve(ones.back()+i+1, j, base+1);
  for (int k = 0; k+1 < ones.size() && ret > 0; k++) {
    ret = ret * solve(ones[k]+i+1, ones[k+1]+i-1, base+1) % mod;
  }
  if (ret == 0) return 0;
  memset(dp, 0, sizeof(dp));
//  ones.push_back(n);
  int m = ones.size();

  for (int k = 0; k+1 < m; k++) {
    int need = ones[k+1] - ones[k] - 1;
    int used = ones[k];
    for (int x = ones[k+1]; x <= n; x++) {
      LL coeff =0 ;
      if (x-1-used >= 0) coeff = combine(x-1-used, need);
      if (k == 0) {
        dp[k][x] = coeff;
        continue;
      }
      for (int y = ones[k]; y < x; y++) {
        if (dp[k-1][y] == 0) continue;
        dp[k][x] = (dp[k][x] + dp[k-1][y] * coeff);
      }
    }
  }
  for (int y = ones[m-1]; y < n; y++) {
    dp[m-1][n] = (dp[m-1][n]  + dp[m-2][y]) % mod;
  }
  LL cur = 0;
  for (int k = 1; k <= n; k++) {
    cur = (cur + dp[m-1][k]) % mod;
  }
  return ret * cur % mod;
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
  int T; cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    int n; cin >> n;
    nums.clear();
    for (int i = 0; i < n; i++) {
      int val; cin >> val;
      nums.push_back(val);
    }
    cout << "Case #" << cs << ": "  << solve(0, n-1, 0) << endl;
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
