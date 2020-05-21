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
const int MAXN = 5000 + 10;
vi edges[MAXN];
int ret[MAXN], bag[MAXN];
bool used[MAXN], rev[MAXN];

pii dfs(int cur, int num) {
  used[cur] = true;
  ret[cur] = num;
  int one = 0;
  int zero = 0;
  if (num == 0) zero++;
  else one++;
  for (int nxt : edges[cur]) {
    if (used[nxt]) {
      if (ret[nxt] != 1 - num) return {-1, -1};
    } else {
      auto tmp = dfs(nxt, 1 - num);
      if (tmp.first == -1) return tmp;
      zero += tmp.first;
      one += tmp.second;
    }
  }
  return {zero, one};
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m; cin >> n >> m;
  int a, b, c; cin >> a >> b >> c;
  int u, v;
  for (int i = 0; i < m; i++) {
     cin >> u >> v;
     edges[u].push_back(v);
     edges[v].push_back(u);
  }
  fill(bag, bag+n+1, INT_MIN);
  bag[0] = 0;
  int base = 0;
  for (int i = 1; i <= n; i++) {
    if (used[i]) continue;
    auto tmp = dfs(i, 0);
    if (tmp.first == -1) {
      cout << "NO\n";
      return 0;
    }

    int val = min(tmp.first, tmp.second);
    base += val;
    val = max(tmp.first, tmp.second) - val;
    if (val == 0) continue;
    if (tmp.first > tmp.second) {
      rev[i] = true;
    }
    for (int j = n-val; j >= 0; j--) {
      if (bag[j+val] != INT_MIN || bag[j] == INT_MIN) continue;
      bag[j+val] = i;
    }
  }
  b -= base;
  if (b < 0 || bag[b] == INT_MIN) {
    cout << "NO\n";
    return 0;
  }
  memset(used, false, sizeof(used));
  for (int i = 1; i <= n; i++) {
    if (rev[i]) dfs(i, 1);
  }
  memset(used, false, sizeof(used));
  while (b > 0) {
    auto tmp = dfs(bag[b], 1 - ret[bag[b]]);
    assert(tmp.first > tmp.second);
    b -= tmp.first - tmp.second;
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    if (ret[i] == 0) {
      ret[i] = 2;
    } else {
      if (a > 0) {
        ret[i] = 1;
        a--;
      } else {
        assert (c > 0);
        ret[i] = 3;
        c--;
      }
    }
  }
  assert (a == 0 && b == 0 && c == 0);
  for (int i = 1; i <= n; i++) {
    cout << ret[i];
  }
  cout << '\n';







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
