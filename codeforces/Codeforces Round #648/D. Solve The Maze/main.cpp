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
bool vis[MAXN][MAXN];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;

bool solve() {
  int good = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      vis[i][j] = false;
      if (mat[i][j] == 'G') good++;
      if (mat[i][j] != 'B') continue;
      for (int k = 0; k < 4; k++) {
        int a = i + dx[k];
        int b = j + dy[k];
        if (a < 0 || a >= n) continue;
        if (b < 0 || b >= m) continue;
        if (mat[a][b] == 'G') return false;
        if (mat[a][b] == 'B') continue;
        mat[a][b] = '#';
      }
    }
  }
  if (mat[n-1][m-1] == '#') {
    return good == 0;
  }
  queue<pii> q;
  vis[n-1][m-1] = true;
  q.emplace(n-1, m-1);
  while (!q.empty()) {
    pii cur = q.front(); q.pop();
    for (int k = 0; k < 4; k++) {
      int a = cur.first + dx[k];
      int b = cur.second + dy[k];
      if (a < 0 || a >= n) continue;
      if (b < 0 || b >= m) continue;
      if (mat[a][b] == '#' || vis[a][b]) continue;
      vis[a][b] = true;
      if (mat[a][b] == 'G') good--;
      q.emplace(a, b);
    }
  }
  return good == 0;
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
      cin >> mat[i];
    }
    if (solve()) cout << "Yes\n";
    else cout << "No\n";
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
