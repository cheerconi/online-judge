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
const int MAXN = 333;
int mat[MAXN][MAXN];
int dist[MAXN][MAXN], dp[MAXN][MAXN];
vector<pii> keys[MAXN*MAXN];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;

void solve_n2(int i) {
  for (const auto& a : keys[i-1]) {
    for (const auto& b : keys[i]) {
      int val = abs(a.first - b.first) + abs(a.second - b.second) + dist[a.first][a.second];
      if (dist[b.first][b.second] == -1 || dist[b.first][b.second] > val) {
        dist[b.first][b.second] = val;
      }
    }
  }
}

void solve_n(int i) {
  memset(dp, -1, sizeof(dp));
  typedef pair<int, pii> piii;
  priority_queue<piii, vector<piii>, greater<piii>> pq;
  for (const auto& a : keys[i-1]) {
    dp[a.first][a.second] = dist[a.first][a.second];
    pq.emplace(dist[a.first][a.second], a);
  }
  while (!pq.empty()) {
    auto item = pq.top(); pq.pop();
    int d = item.first;
    pii a = item.second;
    if (dp[a.first][a.second] < d) continue;
    for (int k = 0; k < 4; k++) {
      int i = a.first + dx[k];
      int j = a.second + dy[k];
      if (j < 0 || j >= m || i < 0 || i >= n) continue;
      if (dp[i][j] != -1 && dp[i][j] <= d+1) continue;
      dp[i][j] = d+1;
      pq.emplace(d+1, make_pair(i, j));
    }
  }
  for (const auto& b : keys[i]) {
    dist[b.first][b.second] = dp[b.first][b.second];
  }
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int p; cin >> n >> m >> p;
  memset(dist, -1, sizeof(dist));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
      keys[mat[i][j]].emplace_back(i, j);
      if (mat[i][j] == 1) {
        dist[i][j] = i+j;
      }
    }
  }

  for (int i = 2; i <= p; i++) {
    LL tmp1 = keys[i-1].size();
    tmp1 *= keys[i].size();
    if (tmp1 <= 1e7) solve_n2(i);
    else solve_n(i);

  }
  cout << dist[keys[p][0].first][keys[p][0].second] << '\n';







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
