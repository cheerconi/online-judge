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
const int mod = 1e9 + 7;
const int MAXN = 777;
LL dp[MAXN][MAXN][3][3];
bool used[MAXN][MAXN];
int p[MAXN];

void solve(int i, int j) {
  if (used[i][j]) return;
  used[i][j] = true;
  if (i+1 == j) {
    dp[i][j][0][1] = 1;
    dp[i][j][0][2] = 1;
    dp[i][j][1][0] = 1;
    dp[i][j][2][0] = 1;
    return;
  }
  if (p[i] == j) {
    solve(i+1, j-1);
    for (int u = 0; u < 3; u++) {
      for (int v = 0; v < 3; v++) {
        if (u != 0 && v != 0) continue;
        if (u == 0 && v == 0) continue;
        for (int a = 0; a < 3; a++) {
          if (u != 0 && u == a) continue;
          for (int b = 0; b < 3; b++) {
            if (v != 0 && v == b) continue;
            dp[i][j][u][v] = (dp[i][j][u][v] + dp[i+1][j-1][a][b]) % mod;
          }
        }
      }
    }
    return;
  }
  solve(i, p[i]);
  solve(p[i]+1, j);
  for (int u = 0; u < 3; u++) {
    for (int v = 0; v < 3; v++) {
      for (int a = 0; a < 3; a++) {
        if (v != 0 && v == a) continue;
        for (int b = 0; b < 3; b++) {
          dp[i][j][u][b] = (dp[i][j][u][b] + dp[i][p[i]][u][v] * dp[p[i]+1][j][a][b] % mod) % mod;
        }
      }
    }
  }
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  string s; cin >> s;
  stack<int> st;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') st.push(i);
    else {
      int val = st.top(); st.pop();
      p[val] = i;
      p[i] = val;
    }
  }
  solve(0, n-1);
  LL ret = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ret = (ret + dp[0][n-1][i][j]) % mod;
    }
  }
  cout << ret << '\n';




/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
