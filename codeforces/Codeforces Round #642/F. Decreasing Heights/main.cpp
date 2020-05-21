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
const int MAXN = 101;
LL mat[MAXN][MAXN], dp[MAXN][MAXN];
int n, m;

LL solve(LL s) {
  memset(dp, -1, sizeof(dp));
  dp[0][1] = 0;
  dp[1][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      LL need = mat[i][j] - (s + i + j - 2);
      if (need < 0) continue;
      if (dp[i-1][j] != -1) {
        dp[i][j] = dp[i-1][j] + need;
      }
      if (dp[i][j-1] != -1 && (dp[i][j] == -1 || dp[i][j] > need+dp[i][j-1])) {
        dp[i][j] = dp[i][j-1] + need;
      }
    }
  }
  return dp[n][m];
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while(t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> mat[i][j];
      }
    }
    LL ret = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        LL tmp = solve(mat[i][j] - i - j + 2);
        if (tmp != -1) ret = min(ret, tmp);
      }
    }
    cout << ret << '\n';

  }







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
