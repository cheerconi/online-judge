/*
ID: txingml
PROG: castle
LANG: C++
*/
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
const int MAXN = 55;
int mat[MAXN][MAXN];
vi edges[MAXN*MAXN];
int idd[MAXN*MAXN], cnt[MAXN*MAXN];
int n, m;

void add(int i, int j, int a, int b) {
  assert(i >= 0 && i < n);
  assert(j >= 0 && j < m);
  assert(a >= 0 && a < n);
  assert(b >= 0 && b < m);
  int x = i * m + j;
  int y = a * m + b;
  edges[x].push_back(y);
}

int dfs(int i, int idx) {
  int ret = 1;
  idd[i] = idx;
  for (int nxt : edges[i]) {
    if (idd[nxt] != 0) continue;
   ret += dfs(nxt, idx);
  }
  return ret;
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
  freopen("castle.in", "r", stdin);
  freopen("castle.out", "w", stdout);
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
      if ((mat[i][j] & 1) == 0) add(i, j-1, i, j);
      if ((mat[i][j] & 2) == 0) add(i-1, j, i, j);
      if ((mat[i][j] & 4) == 0) add(i, j+1, i, j);
      if ((mat[i][j] & 8) == 0) add(i+1, j, i, j);
    }
  }
  int idx = 0;
  int ma = 0;
  for (int i = 0; i < m*n; i++) {
    if (idd[i] != 0) continue;
    idx++;
    cnt[idx] = dfs(i, idx);
    ma = max(ma, cnt[idx]);
  }
  int ma2 = 0, u, v;
  char c;
  for (int j = 0; j < m; j++) {
    for (int i = n-1; i >= 0; i--) {
      int x = i * m + j;
      if ((mat[i][j] & 2) && i-1 >= 0) {
        int y = (i-1)*m + j;
        if (idd[x] != idd[y] && cnt[idd[x]] + cnt[idd[y]] > ma2) {
          ma2 = cnt[idd[x]] + cnt[idd[y]];
          u = i;
          v = j;
          c = 'N';
        }
      }
      if ((mat[i][j] & 4) && j+1 < m) {
        int y = i*m + j + 1;
        if (idd[x] != idd[y] && cnt[idd[x]] + cnt[idd[y]] > ma2) {
          ma2 = cnt[idd[x]] + cnt[idd[y]];
          u = i;
          v = j;
          c = 'E';
        }
      }
    }
  }
  cout << idx << '\n' << ma << '\n' << ma2 << '\n' << u+1 << ' ' << v+1 << ' ' << c << '\n';


/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
