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
struct Node{
  int i, j;
  LL val;
};
Node nodes[10000];
bool used[10000];
vi edges[10000];
int tot;

const int MAXN = 40;
LL tri[MAXN][MAXN];


vector<pii> ret;

bool cmp(int i, int j) {
  return nodes[i].val > nodes[j].val;
}

bool dfs(int idx, LL cur, int step) {
  if (step < 0 || idx < 0 || idx >= tot) return false;
  if (cur == 0) return true;
  for (int nxt : edges[idx]) {
    if (nodes[nxt].val > cur || used[nxt]) continue;
    used[nxt] = true;
    ret.emplace_back(nodes[nxt].i, nodes[nxt].j);
    if (dfs(nxt, cur-nodes[nxt].val, step-1)) return true;
    ret.pop_back();
    used[nxt] = false;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  for (int i = 0; i < MAXN; i++) {
    for (int j = 0; j < i+1; j++) {
      if (j == 0 || j == i) tri[i][j] = 1;
      else tri[i][j] = tri[i-1][j] + tri[i-1][j-1];
      if (tri[i][j] < 1e9) {
        nodes[tot].i = i;
        nodes[tot].j = j;
        nodes[tot].val = tri[i][j];
        tot++;
      }
    }
  }
  for (int i = 0; i < tot; i++) {
    for (int j = i+1; j < tot; j++) {
      int a = nodes[i].i - nodes[j].i;
      int b = nodes[i].j - nodes[j].j;
      if (abs(a) >= 2 || abs(b) >= 2) continue;
      if ((abs(a) == 1 && a == b) || a == 0 || b == 0) {
        edges[i].push_back(j);
        edges[j].push_back(i);
      }
    }
  }
  for (int i = 0; i < tot; i++) {
    sort(edges[i].begin(), edges[i].end(), cmp);
  }

  int T; cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    LL n; cin >> n;
    ret.clear();
    memset(used, false, sizeof(used));
    ret.emplace_back(0, 0);
    used[0] = true;
    assert(dfs(0, n-1, 500));
    cout << "Case #" << cs << ":\n";
    for (const auto& item : ret) {
      cout << item.first+1 << ' ' << item.second+1 << '\n';
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
