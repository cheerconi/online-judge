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
const int MAXN = 300 + 10;
const LL bound = 1e12;
vi edges[MAXN], recipes[MAXN];
set<int> type2recipe[MAXN];
LL dist[MAXN][MAXN];
struct Item{
  int i, j;
  LL val;
};





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int T; cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    memset(dist, -1, sizeof(dist));
    int n, m, s, r;
    cin >> n >> m >> s >> r;
    for (int i = 0; i < MAXN; i++) {
      edges[i].clear();
      recipes[i].clear();
      type2recipe[i].clear();
    }
    for (int i = 0; i < m; i++) {
      int u, v; cin >> u >> v;
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    queue<Item> q;
    for (int i = 1; i <= n; i++) {
      int tot; cin >> tot;
      while (tot--) {
        int val; cin >> val;
        dist[i][val] = 0;
        q.push({i, val, 0});
      }
    }
    for (int i = 1; i <= r; i++) {
      int tot; cin >> tot;
      int val;
      while (tot--) {
        cin >> val;
        recipes[i].push_back(val);
      }
      cin >> val;
      recipes[i].push_back(val);
      for (int j = 0; j+1 < recipes[i].size(); j++) {
        type2recipe[recipes[i][j]].insert(i);
      }
    }
    while (!q.empty()) {
      Item item = q.front(); q.pop();
      if (dist[item.i][item.j] != -1 && dist[item.i][item.j] < item.val) continue;
      for (int nxt : edges[item.i]) {
        if (dist[nxt][item.j] == -1 || dist[nxt][item.j] > item.val+1) {
          dist[nxt][item.j] = item.val + 1;
          q.push({nxt, item.j, item.val+1});
        }
      }
      for (int i : type2recipe[item.j]) {
        LL tmp = 0;
        for (int j = 0; j+1 < recipes[i].size(); j++) {
          if (dist[item.i][recipes[i][j]] == -1) {
            tmp = -1;
            break;
          }
          tmp += dist[item.i][recipes[i][j]];
          if (tmp >= bound) {
            tmp = -1;
            break;
          }
        }
        if (tmp == -1) continue;
        if (dist[item.i][recipes[i].back()] == -1 || dist[item.i][recipes[i].back()] > tmp) {
          dist[item.i][recipes[i].back()] = tmp;
          q.push({item.i, recipes[i].back(), tmp});
        }
      }
    }
    LL ret = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
      if (dist[i][1] != -1) {
        ret = min(ret, dist[i][1]);
      }
    }
    if (ret == LLONG_MAX) ret = -1;
    cout << "Case #" << cs << ": " << ret << '\n';
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
