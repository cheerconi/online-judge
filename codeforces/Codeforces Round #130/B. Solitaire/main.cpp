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
bool dp[MAXN][MAXN][MAXN][MAXN];
string cards[MAXN];

bool check(int i, int j) {
  if (cards[i-1][0] == cards[j-1][0]) return true;
  return cards[i-1][1] == cards[j-1][1];
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cards[i];
  }
  for (int i = 1; i <= n; i++) {
    dp[0][i][0][0] = true;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (check(i, j)) dp[0][i][j][0] = true;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      for (int k = 1; k <= n; k++) {
        if (i == k || j == k) continue;
        if (check(k, i) && check(k, j)) dp[0][i][j][k] = true;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0][0][0] = dp[i-1][i][0][0];
    for (int j = i+1; j <= n; j++) {
      if (check(j, i)) dp[i][j][0][0] |= dp[i-1][j][0][0];
      if (i-2 >= 1 && check(i-2, j)) dp[i][j][0][0] |= dp[i-3][j][i-1][i];
    }
    for (int j = i+1; j <= n; j++) {
      for (int k = i+1; k <= n; k++) {
        if (j == k) continue;
        if (check(j, k)) dp[i][j][k][0] |= dp[i][k][0][0];
        if (i-1 >= 1 && check(i-1, k)) dp[i][j][k][0] |= dp[i-2][k][i][j];
      }
    }
    for (int a = i+1; a <= n; a++) {
      for (int b = i+1; b <= n; b++) {
        if (a == b) continue;
        for (int c = i+1; c <= n; c++) {
          if (c == a || c == b) continue;
          if (check(c, b)) dp[i][a][b][c] |= dp[i][a][c][0];
          if (check(i, c)) dp[i][a][b][c] |= dp[i-1][c][a][b];
        }
      }
    }
  }
  if (dp[n][0][0][0]) cout << "YES\n";
  else cout << "NO\n";






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
