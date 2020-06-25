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
const int mod = 1e9 + 7;
LL fact[MAXN], cnt[MAXN], dp[MAXN], factor[MAXN], inv[MAXN];

int gcd(int a, int b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b%a, a);
}

int power(LL base, int p) {
  LL ret = 1;
  base = base % mod;
  while (p) {
    if (p&1) ret = ret * base % mod;
    base = base * base % mod;
    p >>= 1;
  }
  return ret;
}

int combine(int n, int k) {
  LL ret = factor[n] * inv[n-k] % mod;
  return ret * inv[k] % mod;

}

void dfs(int i, int cur, const vector<int>& ps) {
  if (i == ps.size()) {
    cnt[cur]++;
    return;
  }
  dfs(i+1, cur, ps);
  dfs(i+1, cur*ps[i], ps);
}

bool solve(int k) {
  memset(dp, 0, sizeof(dp));
  for (int i = MAXN-1; i >= 1; i--) {
    if (cnt[i] < k) continue;
    dp[i] = combine(cnt[i], k);
    for (LL j = 2; j*i < MAXN; j++) {
      dp[i] = (dp[i] - dp[j*i] + mod) % mod;
    }
  }
  return dp[1] != 0;
}






int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  for (int i = 2; i < MAXN; i++) {
    if (fact[i] != 0) continue;
    for (int j = i+i; j < MAXN; j += i) {
      fact[j] = i;
    }
  }
  factor[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    factor[i] = factor[i-1] * i % mod;
  }
  inv[MAXN-1] = power(factor[MAXN-1], mod-2);
  for (int i = MAXN-2; i >= 0; i--) {
    inv[i] = inv[i+1] * (i+1) % mod;
  }
  int n; cin >> n;
  int tot = 0;
  for (int i = 0; i < n; i++) {
    int val; cin >> val;
    tot = gcd(tot, val);
    vector<int> ps;
    while (fact[val] != 0) {
      if (ps.empty() || ps.back() != fact[val]) {
        ps.push_back(fact[val]);
      }
      val = val / fact[val];
    }
    if (val > 1 && (ps.empty() || ps.back() != val)) ps.push_back(val);
    dfs(0, 1, ps);
  }
  if (tot != 1) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 1; i <= 10; i++) {
    if (solve(i)) {
      cout << i << endl;
      break;
    }
  }








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
