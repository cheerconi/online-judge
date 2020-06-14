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
vi edges[MAXN];
pii dp[MAXN];

vector<int> solve(int i) {
  queue<int> q;
  dp[i] = {0, 0};
  q.push(i);
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int nxt : edges[cur]) {
      if (nxt == dp[cur].second) continue;
      if (dp[nxt].first == -1) {
        dp[nxt].first = dp[cur].first + 1;
        dp[nxt].second = cur;
        q.push(nxt);
        continue;
      }
      vector<int> x, y;
      while (dp[cur].first > dp[nxt].first) {
        x.push_back(cur);
        cur = dp[cur].second;
      }
      while (dp[cur].first < dp[nxt].first) {
        y.push_back(nxt);
        nxt = dp[nxt].second;
      }
      while (cur != nxt) {
        x.push_back(cur);
        y.push_back(nxt);
        cur = dp[cur].second;
        nxt = dp[nxt].second;
      }
      x.push_back(cur);
      reverse(y.begin(), y.end());
      x.insert(x.end(), y.begin(), y.end());
      assert(x.size() >= 3);
      return x;
    }
  }
  return {};
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
  // freopen("../output.txt", "w", stdout);
#endif
  int n, m, k; cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = {-1, -1};
  }
  auto ret = solve(1);
  if (!ret.empty()) {
    if (ret.size() <= k) {
      cout << 2 << '\n' << ret.size() << '\n';
      for (int j = 0; j < ret.size(); j++) {
        cout << ret[j];
        if (j+1 == ret.size()) cout << '\n';
        else cout << ' ';
      }
    } else {
      cout << 1 << '\n';
      for (int j = 0; j < (k+1)/2; j++) {
        cout << ret[j*2];
        if (j+1 == (k+1)/2) cout << '\n';
        else cout << ' ';
      }
    }
    return 0;
  }
  vi x[2];
  for (int i = 1; i <= n; i++) {
    x[dp[i].first % 2].push_back(i);
  }
  if (x[0].size() < x[1].size()) swap(x[0], x[1]);
  cout << 1 << '\n';
  for (int j = 0; j < (k+1)/2; j++) {
    cout << x[0][j];
    if (j+1 == (k+1)/2) cout << '\n';
    else cout << ' ';
  }








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
