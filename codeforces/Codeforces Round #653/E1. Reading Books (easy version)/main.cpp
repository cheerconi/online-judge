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






int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, k; cin >> n >> k;
  vector<int> dp[3];
  for (int i = 0; i < n; i++) {
    int t, a, b; cin >> t >> a >> b;
    if (a == 0 && b == 1) {
      dp[1].push_back(t);
    } else if (a == 1 && b == 0) {
      dp[0].push_back(t);
    } else if (a == 1 && b == 1) {
      dp[2].push_back(t);
    }
  }
  for (int i = 0; i < 3; i++) {
    sort(dp[i].begin(), dp[i].end());
    for (int j = 1; j < dp[i].size(); j++) {
      dp[i][j] += dp[i][j-1];
    }
  }
  int ret = INT_MAX;
  for (int i = 0; i <= min((int)dp[2].size(), k); i++) {
    int j = k - i;
    if (j > dp[1].size() || j > dp[0].size()) continue;
    int tmp = 0;
    if (j-1 >= 0) tmp += dp[1][j-1] + dp[0][j-1];
    if (i-1 >= 0) tmp += dp[2][i-1];
    ret = min(ret, tmp);
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
