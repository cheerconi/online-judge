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
const int MAXN = 2e5 + 10;
vector<int> edges[MAXN];
int dist_a[MAXN], dist_b[MAXN], dist_c[MAXN];
LL ps[MAXN];

void solve(int i, int dist[]) {
  queue<int> q;
  q.push(i);
  dist[i] = 0;
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int nxt : edges[cur]) {
      if (dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
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
  int t, n, m, a, b, c, u, v; cin >> t;
  while (t--) {
    cin >> n >> m >> a >> b >> c;
    for (int i = 1; i <= n; i++) {
      edges[i].clear();
      dist_a[i] = -1;
      dist_b[i] = -1;
      dist_c[i] = -1;
    }
    for (int i = 1; i <= m; i++) {
      cin >> ps[i];
    }
    sort(ps+1, ps+m+1);
    for (int i = 1; i <= m; i++) {
      ps[i] += ps[i-1];
    }

    for (int i = 0; i < m; i++) {
      cin >> u >> v;
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    solve(a, dist_a);
    solve(b, dist_b);
    solve(c, dist_c);
    LL ret = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
      int x = dist_a[i];
      int y = dist_c[i];
      int z = dist_b[i];
      if (x+y+z > m) continue;
      ret = min(ret, ps[z] + ps[x+y+z]);
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
