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
const int MAXN = 333;
int mat[MAXN][MAXN];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;

pii query(int i, int j, int w) {
  int tot  = 0, nonzero = 0;
  for (int k = 0; k < 4; k++) {
    int a = dx[k] + i;
    int b = dy[k] + j;
    if (a >= n || a < 0 || b >= m || b < 0) continue;
    tot++;
    if (mat[a][b] > 0) nonzero++;
    else if (w > 0) {
      w--;
      mat[a][b] = 1;
    }
  }
  return {tot, nonzero};
}
bool solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == 0) continue;
      pii ret = query(i, j, 0);
      if (mat[i][j] > ret.first) return false;
      query(i, j, mat[i][j] - ret.second);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == 0) continue;
      int nonzero = query(i, j, 0).second;
      assert (nonzero >= mat[i][j]);
      mat[i][j] = nonzero;
    }
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
  int t; cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> mat[i][j];
      }
    }
    if (solve()) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << mat[i][j];
          if (j+1 != m) cout << ' ';
        }
        cout << '\n';
      }
    } else {
      cout << "NO\n";
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
