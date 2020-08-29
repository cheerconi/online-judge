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
const int MAXN = 3000 + 10;
LL mat[MAXN][MAXN];
LL dp[4][MAXN][MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int a, b, c; cin >> a >> b >> c;
    mat[a][b] = c;
  }
  memset(dp, -1, sizeof(dp));
  dp[0][1][1] = 0;
  if (mat[1][1] > 0) dp[1][1][1] = mat[1][1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int u = 0; u < 4; u++) {
        if (dp[u][i][j] == -1) continue;
        if (j+1 <= m) {
          dp[u][i][j+1] = max(dp[u][i][j+1], dp[u][i][j]);
          if (mat[i][j+1] > 0 && u < 3) dp[u+1][i][j+1] = max(dp[u+1][i][j+1], dp[u][i][j] + mat[i][j+1]);
        }
        if (i+1 <= n) {
          dp[0][i+1][j] = max(dp[0][i+1][j], dp[u][i][j]);
          if (mat[i+1][j] > 0) dp[1][i+1][j] = max(dp[1][i+1][j], dp[u][i][j] + mat[i+1][j]);
        }
      }
    }
  }
  LL ret = 0;
  for (int u = 0; u < 4; u++) {
    ret = max(ret, dp[u][n][m]);
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
