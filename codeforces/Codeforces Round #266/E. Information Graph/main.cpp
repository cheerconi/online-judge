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
const int MAXM = 18;
int par[MAXN][MAXM], level[MAXN];
int t[MAXN], x[MAXN], y[MAXN];
int uf[MAXN];
vector<pii> qs[MAXN];

int find(int i) {
  if (uf[i] == i) return i;
  return uf[i]=find(uf[i]);
}
void add(int i, int j) {
  int a = find(i);
  int b = find(j);
  uf[a] = b;
}

void dfs(int i) {
  if (level[i] != 0) return;
  if (i == 0) {
    level[i] = 1;
    return;
  }
  dfs(par[i][0]);
  level[i] = level[par[i][0]] + 1;
}

bool solve(int i, int j) {
  int a = find(i);
  int b = find(j);
  if (a != b) return false;
  int diff = level[i] - level[j];
  while (diff > 0) {
    for (int k = MAXM-1; k >= 0; k--) {
      if (diff - (1<<k) >= 0) {
        i = par[i][k];
        diff -= 1<<k;
      }
    }
  }
  return !(diff < 0 || i != j);
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m; cin >> n >> m;
  int idx = 1;
  for (int i = 0; i < m; i++) {
    cin >> t[i];
    if (t[i] == 1) {
      cin >> x[i] >> y[i];
      assert(x[i] != y[i]);
      par[x[i]][0] = y[i];
    } else if (t[i] == 2) {
      cin >> x[i];
      y[i] = idx;
      idx++;
    } else {
      cin >> x[i] >> y[i];
      qs[y[i]].emplace_back(x[i], i);
    }
  }
  for (int i = 1; i < MAXM; i++) {
    for (int j = 1; j <= n; j++) {
      par[j][i] = par[par[j][i-1]][i-1];
    }
  }
  for (int i = 1; i <= n; i++) {
    dfs(i);
    uf[i] = i;
  }
  for (int i = 0; i < m; i++) {
    if (t[i] == 1) add(x[i], y[i]);
    else if (t[i] == 2) {
      for (pii q : qs[y[i]]) {
        if (solve(x[i], q.first)) x[q.second] = 1;
        else x[q.second] = 0;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (t[i] != 3) continue;
    if (x[i]) cout << "YES\n";
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
