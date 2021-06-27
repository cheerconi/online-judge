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
string mat[MAXN];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool solve(int n, int m) {
  queue<pii> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] != '.') q.emplace(i, j);
    }
  }
  if (q.empty()) {
    mat[0][0] = 'W';
    q.emplace(0, 0);
  }
  while (!q.empty()) {
    auto item = q.front(); q.pop();
    for (int k = 0; k < 4; k++) {
      int x = item.first + dx[k];
      int y = item.second + dy[k];
      if (x < 0 || x >= n || y < 0 || y >= m) continue;
      if (mat[x][y] == mat[item.first][item.second]) return false;
      if (mat[x][y] == '.') {
        mat[x][y] = mat[item.first][item.second] == 'W' ? 'R' : 'W';
        q.emplace(x, y);
      }
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
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> mat[i];
    }
    if (solve(n, m)) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        cout << mat[i] << '\n';
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
