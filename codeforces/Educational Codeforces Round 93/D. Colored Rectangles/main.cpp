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
const int MAXN = 233;
int dp[MAXN][MAXN][MAXN];
int as[MAXN], bs[MAXN], cs[MAXN];

int solve(int i, int j, int k) {
  if (dp[i][j][k] != -1) return dp[i][j][k];
  if (i >= 1 && j >= 1) {
    int tmp = solve(i-1, j-1, k);
    if (tmp != -2) dp[i][j][k] = max(dp[i][j][k], tmp + as[i-1] * bs[j-1]);
  }
  if (i >= 1 && k >= 1) {
    int tmp = solve(i-1, j, k-1);
    if (tmp != -2) dp[i][j][k] = max(dp[i][j][k], tmp  + as[i-1] * cs[k-1]);
  }
  if (j >= 1 && k >= 1) {
    int tmp = solve(i, j-1, k-1);
    if (tmp != -2) dp[i][j][k] = max(dp[i][j][k], tmp  + bs[j-1] * cs[k-1]);
  }
  if (dp[i][j][k] == -1) dp[i][j][k] = -2;
  return dp[i][j][k];
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int a, b, c;
  cin >> a >> b >> c;

  for (int i = 0; i < a; i++) cin >> as[i];
  for (int i = 0; i < b; i++) cin >> bs[i];
  for (int i = 0; i < c; i++) cin >> cs[i];
  sort(as, as + a, greater<int>());
  sort(bs, bs + b, greater<int>());
  sort(cs, cs + c, greater<int>());
  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = 0;
  int ret = 0;
  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= b; j++) {
      for (int k = 0; k <= c; k++) {
        ret = max(ret, solve(i, j, k));
      }
    }
  }
  cout << ret << endl;







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
