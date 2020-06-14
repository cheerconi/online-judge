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
vi edges[MAXN];
LL cnt[2][MAXN], need[MAXN], a[MAXN], b[MAXN], c[MAXN];

void dfs(int cur, int par) {
  cnt[0][cur] = b[cur];
  cnt[1][cur] = c[cur];
  if (par > 0) a[cur] = min(a[cur], a[par]);
  need[cur] = (b[cur]!=c[cur]);
  for (int nxt : edges[cur]) {
    if (nxt == par) continue;
    dfs(nxt, cur);
    cnt[0][cur] += cnt[0][nxt];
    cnt[1][cur] += cnt[1][nxt];
    need[cur] += need[nxt];
  }
}

LL solve(int cur, int par) {
  LL ret = 0;
  LL unsolved = 0;
  if (b[cur] != c[cur]) unsolved++;
  for (int nxt : edges[cur]) {
    if (nxt == par) continue;
    ret += solve(nxt, cur);
    unsolved += need[nxt];
  }
  need[cur] = abs(cnt[0][cur] - cnt[1][cur]);
  assert(unsolved >= need[cur]);
  ret += (unsolved - need[cur]) * a[cur];
  return ret;
}


int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, u, v; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  for (int i = 0; i < n-1; i++) {
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  dfs(1, -1);
  LL ret =  solve(1, -1);
  if (need[1] != 0) ret = -1;
  cout << ret << '\n';







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
