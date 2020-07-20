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
int a[MAXN], b[MAXN], degree[MAXN], ret[MAXN];
vi edges[MAXN];

bool solve(int n) {
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (degree[i] == 0) q.push(i);
  }
  int tot = 0;
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    ret[cur] = tot++;
    for (int nxt : edges[cur]) {
      degree[nxt]--;
      if (degree[nxt] == 0) q.push(nxt);
    }
  }
  return tot == n;
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
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      edges[i].clear();
      degree[i] = 0;
    }
    for (int i = 0; i < m; i++) {
      int c; cin >> c >> a[i] >> b[i];
      if (c == 1) {
        edges[a[i]].push_back(b[i]);
        degree[b[i]]++;
      }
    }
    if (solve(n)) {
      cout << "YES\n";
      for (int i = 0; i < m; i++) {
        if (ret[a[i]] > ret[b[i]]) swap(a[i], b[i]);
        cout << a[i] << ' ' << b[i] << '\n';
      }

    } else {
      cout << "NO\n";
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
