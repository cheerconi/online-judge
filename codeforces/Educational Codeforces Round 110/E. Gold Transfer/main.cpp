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
const int MAXN = 3e5 + 10;
const int MAXB = 20;
int par[MAXN][20], a[MAXN], c[MAXN];
int node[MAXN];




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  memset(par, -1, sizeof(par));
  par[0][0] = 0;
  int q; cin >> q;
  cin >> a[0] >> c[0];
  for (int i = 1; i <= q; i++) {
    int cmd; cin >> cmd;
    if (cmd == 1) {
      cin >> par[i][0] >> a[i] >> c[i];
      for (int j = 1; j < MAXB; j++) {
        int tmp = par[i][j-1];
        if (tmp == -1) break;
        par[i][j] = par[tmp][j-1];
      }
    } else {
      int v, w; cin >> v >> w;
      LL x = 0, y = 0;
      while (w > 0 && a[v] > 0) {
        int cur = v;
        for (int j = MAXB-1; j >= 0; j--) {
          if (par[cur][j] == -1) continue;
          if (a[par[cur][j]] == 0) continue;
          cur = par[cur][j];
        }
        LL tmp = min(a[cur], w);
        x += tmp;
        y += c[cur] * tmp;
        a[cur] -= tmp;
        w -= tmp;
      }
      cout << x << ' ' << y << endl;
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
