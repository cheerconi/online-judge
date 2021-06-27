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
const int MAXN = 4e5 + 10;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vi edges[MAXN], redges[MAXN];
vi nodes;
int scc[MAXN];
bool used[MAXN];

void add_edge(int i, int j) {
  edges[i].push_back(j);
  redges[j].push_back(i);
}

void dfs1(int i) {
  used[i] = true;
  for (int j : edges[i]) {
    if (!used[j]) dfs1(j);
  }
  nodes.push_back(i);
}

void dfs2(int i, int id) {
  used[i] = true;
  scc[i] = id;
  for (int j : redges[i]) {
    if (!used[j]) dfs2(j, id);
  }
}

void get_scc(int n) {
  for (int i = 0; i < n; i++) {
    if (!used[i]) dfs1(i);
  }
  memset(used, false, sizeof(used));
  int id = 1;
  for (int i = n-1; i >= 0; i--) {
    if (!used[nodes[i]]) dfs2(nodes[i], id++);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m; cin >> n >> m;
  vector<vi> idx(n, vi(m, -1));
  int tot = 0;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == '#') {
        idx[i][j] = tot++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (idx[i][j] == -1) continue;
      for (int k = 0; k < 4; k++) {
        int x = dx[k] + i;
        int y = dy[k] + j;
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (idx[x][y] == -1) continue;
        add_edge(idx[i][j], idx[x][y]);
      }
    }
  }
  for (int j = 0; j < m; j++) {
    int pre = -1;
    for (int i = 0; i < n; i++) {
      if (pre != -1) {
        if (j-1 >= 0 && idx[i][j-1] != -1) add_edge(pre, idx[i][j-1]);
        if (j+1 < m && idx[i][j+1] != -1) add_edge(pre, idx[i][j+1]);
        if (idx[i][j] != -1) add_edge(pre, idx[i][j]);
      }
      if (idx[i][j] != -1) pre = idx[i][j];
    }
  }
  get_scc(tot);
  int ma = 0;
  for (int i = 0; i < tot; i++) {
    ma = max(ma, scc[i]);
  }
  vector<bool> degree(ma+1);
  for (int i = 0; i < tot; i++) {
    for (int j : edges[i]) {
      if (scc[i] == scc[j]) continue;
      degree[scc[j]]= true;
    }
  }
  int ret = 0;
  for (int i = 1; i <= ma; i++) {
    if (!degree[i]) ret++;
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
