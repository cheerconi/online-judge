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
vector<vi> in[MAXN], out[MAXN];

void dfs1(int cur, int par) {
  for (int nxt : edges[cur]) {
    if (nxt == par) continue;
    dfs1(nxt, cur);
    assert(!in[nxt].empty());
    in[cur].push_back({in[nxt][0][0]+1, nxt, in[nxt][0][2]});
    sort(in[cur].begin(), in[cur].end(), greater<vi>());
    if (in[cur].size() > 3) in[cur].resize(3);
  }
  if (in[cur].empty()) {
    in[cur].push_back({0, cur, cur});
  }
}

void dfs2(int cur, int par) {
  if (par > 0) {
    for (const auto& item : in[par]) {
      if (item[1] == cur) continue;
      out[cur].push_back({item[0]+1, item[1], item[2]});
      break;
    }
    if (!out[par].empty()) {
      assert(out[par].size() == 1);
      const auto& item = out[par].front();
      out[cur].push_back({item[0]+1, item[1], item[2]});
    }
    sort(out[cur].begin(), out[cur].end(), greater<vi>());
    if (out[cur].size() > 1) out[cur].resize(1);
  }
  for (int nxt : edges[cur]) {
    if (nxt == par) continue;
    dfs2(nxt, cur);
  }
}


int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  for (int i = 0; i < n-1; i++) {
    int a, b; cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  int root = 1;
  while (root <= n && edges[root].size() == 1) root++;
  dfs1(root, -1);
  dfs2(root, -1);
  int ret = 0, x = 0, y = 0, z = 0;
  for (int i = 1; i <= n; i++) {
    vector<vi> items;
    for (const auto& item : in[i]) {
      items.push_back(item);
    }
    for (const auto& item : out[i]) {
      items.push_back(item);
    }
    sort(items.begin(), items.end(), greater<vi>());
    if (items.size() >= 3) {
      int tmp = items[0][0] + items[1][0] + items[2][0];
      if (tmp > ret) {
        ret = tmp;
        x = items[0][2];
        y = items[1][2];
        z = items[2][2];
      }
    } else if (items.size() == 2 && items.back()[0] != 0) {
      int tmp = items[0][0] + items[1][0];
      if (tmp > ret) {
        ret = tmp;
        x = items[0][2];
        y = items[1][2];
        z = i;
      }

    }
  }
  cout << ret << '\n' << x << ' ' << y << ' ' << z << '\n';








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
