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
int tree[MAXN], cnt[MAXN], node2idx[MAXN];
vi edges[MAXN], depth2nodes[MAXN];
int n, idx;

void dfs(int cur, int d) {
  node2idx[cur] = idx++;
  cnt[cur] = 1;
  depth2nodes[d].push_back(cur);
  for (int nxt : edges[cur]) {
    dfs(nxt, d+1);
    cnt[cur] += cnt[nxt];
  }
}

int lowbit(int i) {
  return i & (-i);
}

void add(int i, int val) {
  while (i <= n) {
    tree[i] += val;
    i += lowbit(i);
  }
}

int query(int i) {
  int ret = 0;
  while (i > 0) {
    ret += tree[i];
    i -= lowbit(i);
  }
  return ret;
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int par; cin >> par;
    edges[par].push_back(i);
  }
  idx = 1;
  dfs(1, 0);
  assert(idx == n+1);

  int q; cin >> q;
  vector<vi> qs;
  for (int i = 0; i < q; i++) {
    int u, d; cin >> u >> d;
    qs.push_back({d, u, i});
  }
  sort(qs.begin(), qs.end());
  int d = n+1;
  vector<int> ret(q);
  for (const auto& item : qs) {
    if (item[0] != d) {
      for (int node : depth2nodes[d]) {
        add(node2idx[node], -1);
      }
      d = item[0];
      for (int node : depth2nodes[d]) {
        add(node2idx[node], 1);
      }
    }
    int i = node2idx[item[1]] - 1;
    int j = i + cnt[item[1]];
    ret[item[2]] = query(j) - query(i);
  }
  for (int i = 0; i < q; i++) {
    cout << ret[i] << '\n';
  }








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
