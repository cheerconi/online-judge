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
const int MAXN = 1e5 + 10;
const int M = 17;
vi edges[MAXN];
int anc[MAXN][M], level[MAXN];

void build(int cur, int par) {
  level[cur] = level[par] + 1;
  int tmp = par;
  for (int  i = 0; i < M; i++) {
    anc[cur][i] = tmp;
    tmp = anc[tmp][i];
  }
  for (int nxt : edges[cur]) {
    if (nxt == par) continue;
    build(nxt, cur);
  }
}

int query(int x, int y) {
  if (level[x] > level[y]) swap(x, y);
  int ret = level[y] - level[x];
  for (int i = M-1; i >= 0 && level[x] != level[y]; i--) {
    int diff = 1 << i;
    if (level[x] + diff <= level[y]) {
      y = anc[y][i];
    }
  }
  assert (level[x] == level[y]);
  for (int i = M-1; i >= 0 && x != y; i--) {
    if (anc[x][i] != anc[y][i]) {
      ret += 1<<(i+1);
      x = anc[x][i];
      y = anc[y][i];
    }
  }
  if (x != y) ret += 2;
  return ret;
}

bool solve(int x, int y, int a, int b, int k) {
  int ret = query(a, b);
  if (ret <= k && (k-ret)%2 == 0) return true;
  ret = query(a, x) + query(y, b) + 1;
  if (ret <= k && (k-ret)%2 == 0) return true;
  ret = query(a, y) + query(x, b) + 1;
  return ret <= k && (k - ret) % 2 == 0;
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int a, b;
  for (int i = 0; i < n-1; i++) {
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  build(1, 0);
  int q; cin >> q;
  int x, y, k;
  while(q--) {
    cin >> x >> y >> a >> b >> k;
    if (solve(x, y, a, b, k)) cout << "YES\n";
    else cout << "NO\n";


  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
