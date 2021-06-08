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
int g_dp[2][MAXN][MAXN];
string mat[MAXN];
int n, m;

void solve(int dp[][MAXN], int s, int delta) {
  for (int j = 0; j < m; j++) {
    dp[s][j] = 1;
  }
  for (int k = 0; k < 26; k++) {
    char c = k + 'a';
    for (int i = s + delta; i >= 0 && i < n; i += delta) {
      vector<pii> ranges;
      for (int j = 0; j < m; j++) {
        if (mat[i][j] != c) continue;
        if (!ranges.empty() && ranges.back().second == j-1) {
          ranges.back().second = j;
        } else {
          ranges.emplace_back(j, j);
        }
      }
      int u = 0;
      for (int j = 0; j < m; j++) {
        if (mat[i][j] != c) continue;
        dp[i][j] = 1;
        if (mat[i - delta][j] != c) continue;
        while (u < ranges.size()) {
          if (ranges[u].first <= j && j <= ranges[u].second) break;
          u++;
        }
        assert(u < ranges.size());
        int tmp1 = dp[i - delta][j] + 1;
        int tmp2 = ranges[u].second - j + 1;
        int tmp3 = j - ranges[u].first + 1;
        tmp1 = min(tmp1, tmp2);
        tmp1 = min(tmp1, tmp3);
        dp[i][j] = tmp1;
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
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> mat[i];
  }
  solve(g_dp[0], 0, 1);
  solve(g_dp[1], n-1, -1);
  LL ret = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      LL tmp = min(g_dp[0][i][j], g_dp[1][i][j]);
      ret += tmp;
    }
  }
  cout << ret << endl;










/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
