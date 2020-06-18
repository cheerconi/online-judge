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
const int MAXN = 2000 + 10;
const int mod = 1e9 + 7;
const int inv2 = (mod+1) / 2;
vector<pii> edges[MAXN];
int dp[MAXN][MAXN], slope[MAXN];

struct Frac{
  LL x, y;
  Frac(LL x_, LL y_): x(x_), y(y_) {
    assert(y != 0);
    if (y < 0) {
      x = -x;
      y = -y;
    }
  }
  bool operator< (const Frac& other) const {
    return (LD)x*other.y < (LD)y*other.x;
  }
};




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
  // freopen("../output.txt", "w", stdout);
#endif
  int n, m, q; cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].emplace_back(v, w);
    edges[v].emplace_back(u, w);
    slope[u] = max(slope[u], w);
    slope[v] = max(slope[v], w);
  }
  LL ret = 0;
  memset(dp, -1, sizeof(dp));
  dp[0][1] = 0;
  int path = 1;
  for (;path <= min(q, n-1); path++) {
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
      if (dp[path-1][i] == -1) continue;
      dp[path][i] = max(dp[path][i], dp[path-1][i] + slope[i]);
      tmp = max(tmp, dp[path][i]);
      for (pii item : edges[i]) {
        dp[path][item.first] = max(dp[path][item.first], dp[path-1][i] + item.second);
        tmp = max(tmp, dp[path][item.first]);
      }
    }
    ret = (ret + tmp) % mod;
  }
  q -= path - 1;
  if (q == 0) {
    cout << ret << '\n';
    return 0;
  }
  vector<pii> cands;
  for (int i = 1; i <= n; i++) {
    cands.emplace_back(slope[i], dp[path-1][i]);
  }
  sort(cands.begin(), cands.end(), [](const pii& a, const pii& b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
  });
  cands.erase(
      unique(cands.begin(), cands.end(), [](const pii& a, const pii& b) {
        return a.first == b.first;}), cands.end());

  deque<pii> lines;
  deque<Frac> points;
  for (const pii& cand : cands) {
    while (!points.empty()) {
      Frac point(lines.back().second - cand.second, cand.first - lines.back().first);
      if (points.back() < point) break;
      points.pop_back();
      lines.pop_back();
    }
    lines.emplace_back(cand);
    if (lines.size() >= 2) {
      points.emplace_back(cand.second - lines[lines.size()-2].second,lines[lines.size()-2].first - cand.first);
    }
  }
  LL cur = 1;
  while (cur <= q) {
    while (!points.empty()) {
      if (points.front() < Frac(cur, 1)) {
        points.pop_front();
        lines.pop_front();
      } else break;
    }
    LL end = q;
    if (!points.empty()) {
      LL tmp = points.front().x / points.front().y;
      end = min((LL)q, tmp);
    }
    LL a = lines.front().first * cur + lines.front().second;
    LL b = lines.front().first * end + lines.front().second;
    ret = ((a+b) % mod * (end-cur+1)%mod * inv2 % mod + ret) % mod;
    cur = end + 1;
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
