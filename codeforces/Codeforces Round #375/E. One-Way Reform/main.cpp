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
const int MAXN = 233;
struct Node{
  int to, idx;
  bool extra = false;
};
vector<Node> edges[MAXN];

void add(int u, int v, bool extra) {
  edges[u].emplace_back();
  edges[v].emplace_back();
  edges[u].back().to = v;
  edges[u].back().idx = edges[v].size()-1;
  edges[u].back().extra = extra;
  edges[v].back().to = u;
  edges[v].back().idx = edges[u].size()-1;
  edges[v].back().extra = extra;
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      edges[i].clear();
    }
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      add(u, v, false);

    }
    vector<int> single;
    for (int i = 1; i <= n; i++) {
      if (edges[i].size() % 2 == 1) {
        single.push_back(i);
      }
    }
    for (int i = 0; i < single.size(); i += 2) {
      add(single[i], single[i+1], true);
    }
    vector<pll> ret;
    for (int i = 1; i <= n; i++) {
      int cur = i;
      while (!edges[cur].empty()) {
        while (!edges[cur].empty() && edges[cur].back().idx == -1) {
          edges[cur].pop_back();
        }
        if (!edges[cur].empty()) {
          int nxt = edges[cur].back().to;
          if (!edges[cur].back().extra) {
            ret.emplace_back(cur, nxt);
          }
          edges[nxt][edges[cur].back().idx].idx = -1;
          edges[cur].pop_back();
          cur = nxt;
        }
      }
    }
    assert(ret.size() == m);
    cout << n - single.size() << '\n';
    for (const auto& item : ret) {
      cout << item.first << ' ' << item.second << '\n';
    }
  }







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
