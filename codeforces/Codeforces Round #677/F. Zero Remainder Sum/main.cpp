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
const int MAXN = 77;
int dp[MAXN][MAXN][MAXN][MAXN];
int ret[MAXN][MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  memset(dp, -1, sizeof(dp));
  memset(ret, -1, sizeof(ret));
  int n, m, k; cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    dp[i][0][0][0] = 0;
    for (int j = 0; j < m; j++) {
      int num; cin >> num;
      for (int u = 0; u < k; u++) {
        for (int v = 0; v <= j; v++) {
          if (dp[i][j][u][v] == -1) continue;
          dp[i][j+1][u][v] = max(dp[i][j+1][u][v], dp[i][j][u][v]);
          int new_u = (u + num) % k;
          dp[i][j+1][new_u][v+1] = max(dp[i][j+1][new_u][v+1], dp[i][j][u][v] + num);
        }
      }
    }
  }
  ret[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      if (ret[i][j] == -1) continue;
      for (int u = 0; u < k; u++) {
        for (int v = 0; v <= m/2; v++) {
          if (dp[i][m][u][v] == -1) continue;
          ret[i+1][(u+j)%k] = max(ret[i+1][(u+j)%k], ret[i][j] + dp[i][m][u][v]);
        }
      }
    }
  }
  cout << ret[n][0] << '\n';







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
