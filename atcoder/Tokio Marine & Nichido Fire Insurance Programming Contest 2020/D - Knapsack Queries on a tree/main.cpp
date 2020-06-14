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
const int MAXM = (1<<18) + 10;
int dp[567][MAXN];
int v[MAXM], w[MAXM];
vector<pii> cur;

int solve(int i, int m) {
  if (i <= m) return i;
  int n = cur.size();
  for (int j = 0; j < n; j++) {
    cur.emplace_back(cur[j].first+w[i], cur[j].second + v[i]);
  }
  return solve(i/2, m);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> w[i];
  }
  int m = min(n, 1<<9);
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < MAXN; j++) {
      dp[i][j] = dp[i/2][j];
      if (j-w[i] >= 0) dp[i][j] = max(dp[i][j], dp[i/2][j-w[i]] + v[i]);
    }
  }
  int q; cin >> q;
  while (q--) {
    int node, weight;
    cin >> node >> weight;
    cur.clear();
    cur.emplace_back(0, 0);
    node = solve(node, m);
    int ret = 0;
    for (const auto& item : cur) {
      if (item.first > weight) continue;
      ret = max(item.second + dp[node][weight-item.first], ret);
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
