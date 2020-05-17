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
int nums[MAXN], idx[MAXN], data[MAXN][10];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, p, k;
  cin >> n >> p >> k;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    idx[i] = i;
  }
  sort(idx, idx + n, [](int i, int j) {return nums[i] > nums[j];});
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < p; j++) {
      cin >> data[i][j];
    }
  }
  int mask = 1<<p;
  vector<LL> dp(mask, -1);
  dp[0] = 0;
  for (int ii = 0; ii < n; ii++) {
    int i = idx[ii];
    vector<LL> nxt(mask, -1);
    for (int j = 0; j < mask; j++) {
      if (dp[j] == -1) continue;
      int cnt = __builtin_popcount(j);
      LL tmp = dp[j];
      assert(ii - cnt >= 0);
      if (ii - cnt < k) tmp += nums[i];
      nxt[j] = max(nxt[j], tmp);
      for (int u = 0; u < p; u++) {
        int mu = 1<<u;
        if (mu & j) continue;
        nxt[j|mu] = max(nxt[j|mu], dp[j] + data[i][u]);
      }
    }
    dp = move(nxt);
  }
  cout << dp[mask-1] << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
