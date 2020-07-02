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
const int MAXN = 55;
int dp[MAXN][MAXN], tag[MAXN][MAXN];
LL fact[MAXN], inv[MAXN];

LL power(LL base, LL p) {
  base = base % mod;
  LL ret = 1;
  while (p) {
    if (p&1) ret = ret * base % mod;
    base = base * base % mod;
    p >>= 1;
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
  int n, k; cin >> n >> k;
  k /= 50;
  int a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    int val; cin >> val;
    if (val == 50) a++;
    else b++;
  }
  fact[0] = 1;
  int m = max(a, b);
  for (int i = 1; i <= m; i++) {
    fact[i] = fact[i-1] * i % mod;
  }
  inv[m] = power(fact[m], mod-2);
  for (int i = m-1; i >= 0; i--) {
    inv[i] = inv[i+1] * (i+1) % mod;
  }

  memset(tag, -1, sizeof(tag));
  dp[a][b] = 1;
  tag[a][b] = 0;
  queue<pii> q;
  q.emplace(a, b);
  while (!q.empty()) {
    pii cur = q.front(); q.pop();
    if (cur.first + cur.second*2 <= k) {
      if (tag[0][0] == -1 || tag[0][0] == tag[cur.first][cur.second]+1) {
        dp[0][0] = (dp[0][0] + dp[cur.first][cur.second]) % mod;
        tag[0][0] = tag[cur.first][cur.second] + 1;
      }
      continue;
    }
    for (int i = 0; i <= a; i++) {
      for (int j = 0; j <= b; j++) {
        if (tag[i][j] != -1 && tag[i][j] != tag[cur.first][cur.second] + 1) continue;
        for (int u = 0; u <= cur.first; u++) {
          for (int v = 0; v <= cur.second; v++) {
            if (u+2*v > k || u+v == 0) continue;
            int tmpx = i - (cur.first - u);
            int tmpy = j - (cur.second - v);
            if (tmpx < 0 || tmpy < 0 || tmpx+tmpy == 0 || tmpx+tmpy*2 > k) continue;
            LL coeff = combine(cur.first, u) * combine(cur.second, v) % mod;
            coeff = coeff * combine(a - (cur.first - u), tmpx) % mod;
            coeff = coeff * combine(b - (cur.second - v), tmpy) % mod;
            dp[i][j] = (dp[i][j] + dp[cur.first][cur.second] * coeff % mod) % mod;
            if (tag[i][j] == -1) {
              tag[i][j] = tag[cur.first][cur.second]+1;
              q.emplace(i, j);
            }
          }
        }
      }
    }
  }
  if (tag[0][0] == -1) {
    cout << "-1\n0\n";
    return 0;
  }
  cout << tag[0][0]*2 - 1 << '\n';
  LL ret = dp[0][0];
  cout << ret << '\n';












/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
