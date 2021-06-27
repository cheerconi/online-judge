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
const int MAXN = 1e5 + 10;
int a[MAXN], b[MAXN], t[MAXN], dp[MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int r, n; cin >> r >> n;
  memset(dp, -1, sizeof(dp));
  a[0] = 1;
  b[0] = 1;
  t[0] = 0;
  dp[0] = 0;
  int k = 0;
  int ma = 0;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> a[i] >> b[i];
    for (int j = i-1; j >= 0; j--) {
      if (dp[j] == -1) continue;
      if (t[i] - t[j] >= (r-1)*2) {
        while (k < j) {
          k++;
          ma = max(ma, dp[k]);
        }
        dp[i] = max(dp[i], ma + 1);
        break;
      }
      if (abs(a[i]-a[j]) + abs(b[i]-b[j]) <= t[i]-t[j]) {
        dp[i] = max(dp[i], 1 + dp[j]);
      }
    }
  }
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    ret = max(ret, dp[i]);
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
