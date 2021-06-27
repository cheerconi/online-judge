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
const int MAXN = 1000 + 10;
int a[MAXN], b[MAXN], c[MAXN], dist[MAXN][MAXN], cnt[MAXN], ret[MAXN];
vi edges[MAXN];
bool done[MAXN];

void solve(int x, int n) {
  memset(dist, -1, sizeof(dist));
  memset(done, false, sizeof(done));
  priority_queue<vi, vector<vi>, greater<vi>> pq;
  dist[x][0] = 0;
  pq.push({0, 0, x});
  while (!pq.empty()) {
    vi cur = pq.top(); pq.pop();
    if (dist[cur[2]][cur[1]] < cur[0]) continue;
    if (done[cur[2]]) continue;
    if (cur[1] == 0) done[cur[2]] = true;
    for (int idx : edges[cur[2]]) {
      int nxt = a[idx] == cur[2]? b[idx] : a[idx];

      if (cur[1] == 0) {
        if (dist[nxt][idx] == -1 || dist[nxt][idx] > cur[0]) {
          pq.push({cur[0], idx, nxt});
          dist[nxt][idx] = cur[0];
        }
      }
      if (dist[nxt][cur[1]] == -1 || dist[nxt][cur[1]] > cur[0]+c[idx]) {
        pq.push({cur[0] + c[idx], cur[1], nxt});
        dist[nxt][cur[1]] = cur[0] + c[idx];
      }
    }
  }
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m, k; cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
    edges[a[i]].push_back(i);
    edges[b[i]].push_back(i);
  }
  vector<pii> xy;
  for (int i = 0; i < k; i++) {
    int x, y; cin >> x >> y;
    if (x == y) continue;
    x--;
    y--;
    xy.emplace_back(x, y);
  }
  while (!xy.empty()) {
    memset(cnt, 0, sizeof(cnt));
    int ma = 0;
    for (const auto& item : xy) {
      cnt[item.first]++;
      if (cnt[ma] < cnt[item.first]) ma = item.first;
      cnt[item.second]++;
      if (cnt[ma] < cnt[item.second]) ma = item.second;
    }
    solve(ma, n);
    for (int i = 0; i < xy.size(); i++) {
      if (xy[i].first == ma) {
        for (int j = 1; j <= m; j++) {
          if (dist[xy[i].second][j] == -1) dist[xy[i].second][j] = dist[xy[i].second][0];
          ret[j] += dist[xy[i].second][j];
        }
        swap(xy[i], xy.back());
        xy.pop_back();
        i--;
      } else if (xy[i].second == ma) {
        for (int j = 1; j <= m; j++) {
          if (dist[xy[i].first][j] == -1) dist[xy[i].first][j] = dist[xy[i].first][0];
          ret[j] += dist[xy[i].first][j];
        }
        swap(xy[i], xy.back());
        xy.pop_back();
        i--;
      }
    }
  }
  int res = INT_MAX;
  for (int i = 1; i <= m; i++) {
    res = min(res, ret[i]);
  }
  cout << res << '\n';









/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
