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
const int MAXN = 2000 + 10;
string mat[MAXN];
bool vis[MAXN][MAXN];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int n, m;

pii check(int i, int j) {
  for (int x = -1; x <= 1; x += 2) {
    for (int y = -1; y <= 1; y += 2) {
      if (i+x < 0 || i+x >= n) continue;
      if (j+y < 0 || j+y >= m) continue;
      int cnt = 0;
      pii ret{-1, -1};
      if (mat[i+x][j] == '.') cnt++;
      else ret = {i+x, j};
      if (mat[i+x][j+y] == '.') cnt++;
      else ret = {i+x, j+y};
      if (mat[i][j+y] == '.') cnt++;
      else ret = {i, j+y};
      if (mat[i][j] == '.') cnt++;
      else ret = {i, j};
      if (cnt == 3) return ret;
    }
  }
  return {-1, -1};
}

void dfs(int i, int j) {
  vis[i][j] = true;
  mat[i][j] = '.';
  for (int k = 0; k < 4; k++) {
    int a = i+dx[k];
    int b = j+dy[k];
    if (a == -1 || a== n || b == -1 || b == m) continue;
    if (!vis[a][b] && mat[a][b] == '.') {
      dfs(a, b);
    }
    auto ret = check(a, b);
    if (ret.first == -1 || vis[ret.first][ret.second]) continue;
    dfs(ret.first, ret.second);
  }
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> mat[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j]) continue;
      if (mat[i][j] == '.') dfs(i, j);
      auto ret = check(i, j);
      if (ret.first == -1 || vis[ret.first][ret.second]) continue;
      dfs(ret.first, ret.second);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << mat[i] << '\n';
  }







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
