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
const int MAXN = 2e4 + 10;
vector<pii> edges[MAXN];
int used[MAXN], id, match[MAXN], mi;

bool dfs(int i, int d) {
  used[i] = id;
  for (const auto& item : edges[i]) {
    if (item.first > d) break;
    int j = item.second;
    int w = match[j];
    if (w == -1 || (used[w] < id && dfs(w, d))) {
      match[i] = j;
      match[j] = i;
      return true;
    }
  }
  return false;
}

bool solve(int n, int d) {
  if (d < mi) return false;
  fill(match, match+n+1, -1);
  for (int i = 1; i <= n; i++) {
    if (match[i] == -1) {
      id++;
      if (!dfs(i, d)) return false;
    }
  }
  return true;
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m; cin >> n >> m;
  vector<int> ws;
  ws.reserve(m);
  while (m--) {
    int a, b, c; cin >> a >> b >> c;
    edges[a].emplace_back(c, b+n);
    edges[b+n].emplace_back(c, a);
    ws.push_back(c);
  }
  n = n*2;
  for (int i = 1; i <= n; i++) {
    sort(edges[i].begin(), edges[i].end());
    if (edges[i].empty()) {
      cout << "-1\n";
      return 0;
    }
    mi = max(mi, edges[i][0].first);
  }
  sort(ws.begin(), ws.end());
  ws.resize(unique(ws.begin(), ws.end()) - ws.begin());
  int a = 0, b = (int)ws.size() - 1;
  if (!solve(n, ws[b])) {
    cout << "-1\n";
    return 0;
  }
  while (a < b) {
    int mid = (a+b) >> 1;
    if (solve(n, ws[mid])) b = mid;
    else a = mid+1;
  }
  cout << ws[a] << '\n';






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
