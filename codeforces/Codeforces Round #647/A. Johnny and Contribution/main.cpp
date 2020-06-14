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
const int MAXN = 5e5 + 10;
vi edges[MAXN];
int t[MAXN], idx[MAXN];

bool solve(int n) {
  sort(idx + 1, idx + 1 + n, [](int i, int j) { return t[i] < t[j]; });
  for (int i = n; i >= 1; i--) {
    int cur = idx[i];
    int cnt = 0;
    vector<bool> used(t[cur], false);
    for (int nxt : edges[cur]) {
      if (t[nxt] == t[cur]) return false;
      if (t[nxt] < t[cur] && !used[t[nxt]]) {
        used[t[nxt]] = true;
        cnt++;
      }
    }
    if (cnt != t[cur]-1) return false;
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
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    idx[i] = i;
  }
  if (solve(n)) {
    for (int i = 1; i <= n; i++) {
      cout << idx[i];
      if (i == n) cout << '\n';
      else cout << ' ';
    }
  } else {
    cout << "-1\n";
  }








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
