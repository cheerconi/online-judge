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
string mat[MAXN];
int n, m;
int graph[MAXN][MAXN];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vi edges[MAXN*MAXN];
int dist[MAXN*MAXN];

void dfs(int i, int j, int id) {
  graph[i][j] = id;
  for (int k = 0; k < 4; k++) {
    int ii = i + dx[k];
    int jj = j + dy[k];
    if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
    if (mat[ii][jj] == '#' || graph[ii][jj] != 0) continue;
    dfs(ii, jj, id);
  }


}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  cin >> n >> m;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  a--; b--; c--; d--;
  for (int i = 0; i < n; i++) {
    cin >> mat[i];
  }
  int id = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (graph[i][j] != 0) continue;
      if (mat[i][j] == '#') graph[i][j] = -1;
      else dfs(i, j, id++);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (graph[i][j] <= 0) continue;
      for (int u = -2; u <= 2; u++) {
        if (i+u < 0 || i+u >= n) continue;
        for (int v = -2; v <= 2; v++) {
          if (j+v < 0 || j+v >= m) continue;
          if (graph[i+u][j+v] <= 0 || graph[i+u][j+v] == graph[i][j]) continue;
          edges[graph[i][j]].push_back(graph[i+u][j+v]);
          edges[graph[i+u][j+v]].push_back(graph[i][j]);
        }
      }
    }
  }
  memset(dist, -1, sizeof(dist));
  queue<int> q;
  q.push(graph[a][b]);
  dist[graph[a][b]] = 0;
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int nxt : edges[cur]) {
      if (dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    }
  }
  cout << dist[graph[c][d]] << '\n';












/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
