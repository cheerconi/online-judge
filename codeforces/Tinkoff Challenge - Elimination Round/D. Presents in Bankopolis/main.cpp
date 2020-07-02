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
const int MAXN = 88;
int dist[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[i][j] = INT_MAX;
    }
  }
  int m; cin >> m;
  while (m--) {
    int a, b, c; cin >> a >> b >> c;
    dist[a][b] = min(dist[a][b], c);
  }
  for (int nodes = 1; nodes <= k; nodes++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (nodes == 1) dp[nodes][i][j] = 0;
         else dp[nodes][i][j] = INT_MAX;
      }
    }
  }
  for (int nodes = 2; nodes <= k; nodes++) {
    for (int i = 1; i <= n; i++) {
      for (int j = i+1; j <= n; j++) {
        for (int u = i+1; u <= j; u++) {
          dp[nodes][i][j] = min((LL)dp[nodes][i][j], (LL)dp[nodes-1][u][j] + dist[i][u]);
          dp[nodes][i][j] = min((LL)dp[nodes][i][j], (LL)dp[nodes-1][u][i+1] + dist[i][u]);
        }
      }
      for (int j = i-1; j >= 1; j--) {
        for (int u = i-1; u >= j; u--) {
          dp[nodes][i][j] = min((LL)dp[nodes][i][j], (LL)dp[nodes-1][u][j] + dist[i][u]);
          dp[nodes][i][j] = min((LL)dp[nodes][i][j], (LL)dp[nodes-1][u][i-1] + dist[i][u]);
        }
      }
    }
  }
  int ret = INT_MAX;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ret = min(ret, dp[k][i][j]);
    }
  }
  if (ret == INT_MAX) ret = -1;
  cout << ret << '\n';




/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
