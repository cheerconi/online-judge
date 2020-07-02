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
#define leftnode (node<<1)
#define rightnode ((node<<1)|1)
#define getmid ((left+right)>>1)

const int MAXN = 400000 + 10;
int cnt[MAXN], idx[MAXN], tree[MAXN<<2];
vi edges[MAXN];
bool ret[MAXN];
int n, tot;

void update(int node, int left, int right, int i, int val) {
  if (left == right) {
    tree[node] = val;
    return;
  }
  int mid = getmid;
  if (i <= mid) update(leftnode, left, mid, i, val);
  else update(rightnode, mid+1, right, i, val);
  tree[node] = max(tree[leftnode], tree[rightnode]);
}

int query(int node, int left, int right, int i, int j) {
  if (j < left || right < i || i > j) return 0;
  if (i <= left && right <= j) return tree[node];
  int mid = getmid;
  int ret = 0;
  ret = max(ret, query(leftnode, left, mid, i, j));
  ret = max(ret, query(rightnode, mid+1, right, i, j));
  return ret;
}

void dfs(int cur, int par) {
  cnt[cur]++;
  idx[cur] = ++tot;
  for (int nxt : edges[cur]) {
    if (nxt == par) continue;
    dfs(nxt, cur);
    cnt[cur] += cnt[nxt];
  }
  if (cnt[cur] <= n/2) update(1, 1, n, idx[cur], cnt[cur]);
}

void solve(int cur, int par) {
  bool flag = true;
  if (n - cnt[cur] > n/2) {
    flag = false;
    int tmp = query(1, 1, n, 1, idx[cur]-1);
    tmp = max(tmp, query(1, 1, n, idx[cur]+cnt[cur], n));
    if (n-cnt[cur] - tmp <= n/2) flag = true;
  }
  update(1, 1, n, idx[cur], n-cnt[cur] <= n/2 ? n-cnt[cur] : 0);
  for (int nxt : edges[cur]) {
    if (nxt == par) continue;
    if (cnt[nxt] > n/2) {
      flag = false;
      int tmp = query(1, 1, n, idx[nxt], idx[nxt]+cnt[nxt]-1);
      if (cnt[nxt] - tmp <= n/2) flag = true;
    }
    solve(nxt, cur);
  }
  ret[cur] = flag;
  update(1, 1, n, idx[cur], cnt[cur] <= n/2 ? cnt[cur]: 0);
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  dfs(1, 0);
  solve(1, 0);
  for (int i = 1; i <= n; i++) {
    cout << ret[i];
    if (i == n) cout << '\n';
    else cout << ' ';
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
