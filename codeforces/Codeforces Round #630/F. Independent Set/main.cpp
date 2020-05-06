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
vi edges[MAXN];
LL dp[MAXN][3];

void solve(int cur, int par) {
  dp[cur][0] = 1;
  dp[cur][1] = 1;
  dp[cur][2] = 1;
  for (int nxt : edges[cur]) {
    if (nxt == par) continue;
    solve(nxt, cur);
    dp[cur][0] = dp[cur][0] *  ((2 * dp[nxt][0] + 2 * dp[nxt][1] - dp[nxt][2] + mod) % mod) % mod;
    dp[cur][1] = dp[cur][1] * ((2 * dp[nxt][0] + dp[nxt][1] - dp[nxt][2] + mod) % mod) % mod;
    dp[cur][2] = dp[cur][2] * ((dp[nxt][0] + dp[nxt][1] - dp[nxt][2] + mod) % mod) % mod;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, a, b; cin >> n;
  for (int i = 0; i < n-1; i++) {
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  solve(1, -1);
  LL ret = (dp[1][0] + dp[1][1] - dp[1][2] + mod - 1 + mod) % mod;
  cout << ret << endl;










/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
