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
const int MAXN = 123;
LL dp[MAXN][MAXN];
pii mat[MAXN][MAXN];
int n, m;

LL solve(int i, int j) {
  if (i > j) return 0;
  if (dp[i][j] == -1) {
    for (int k = i; k <= j; k++) {
      LL cnt = 0;
      for (int u = 1; u <= n; u++) {
        if (i <= mat[u][k].first && mat[u][k].second <= j) cnt++;
      }
      dp[i][j] = max(solve(i, k-1) + cnt * cnt + solve(k+1, j), dp[i][j]);
    }
  }
  return dp[i][j];
}


int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int k; cin >> k;
    while (k--) {
      int a, b; cin >> a >> b;
      for (int j = a; j <= b; j++) {
        mat[i][j] = {a, b};
      }

    }
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(1, m) << '\n';








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
