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
const int MAXN = 500 + 10;
int dp[MAXN][MAXN], nums[MAXN], ret[MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    dp[i][i] = nums[i];
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 0; i+len <= n; i++) {
      int j = i+len-1;
      for (int k = i; k < j; k++) {
        if (dp[i][k] == 0 || dp[k+1][j] == 0) continue;
        if (dp[i][k] != dp[k+1][j]) continue;
        int tmp = dp[i][k]+1;
        assert (dp[i][j] == 0 || dp[i][j] == tmp);
        dp[i][j] = tmp;
      }
    }
  }
  ret[0] = 1;
  for (int i = 1; i < n; i++) {
    ret[i] = i+1;
    if (dp[0][i] != 0) ret[i] = 1;
    for (int j = 1; j <= i; j++) {
      if (dp[j][i] == 0) continue;
      ret[i] = min(1 + ret[j-1], ret[i]);
    }
  }
  cout << ret[n-1] << endl;









/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
