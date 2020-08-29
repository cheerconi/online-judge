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
int dp[MAXN][MAXN][2];
int n, m;

LL solve(char c) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 2; k++) {
        if (mat[i][j] == c) dp[i][j][k] = 1;
        else dp[i][j][k] = 0;
      }
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dp[i][j][0] == 0) continue;
      dp[i][j][0] += dp[i-1][j][0];
    }
  }
  for (int i = n-2; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (dp[i][j][1] == 0) continue;
      dp[i][j][1] += dp[i+1][j][1];
    }
  }
  LL ret = 0;
  for (int i = 0; i < n; i++) {
    vector<pii> tmp;
    if (dp[i][0][0] > 0) tmp.emplace_back(1, 0);
    else tmp.emplace_back(0, 0);
    for (int j = 1; j <= m; j++) {
      int len = min(dp[i][j][0], dp[i][j][1]);
      if (j == m) len = 0;
      while (!tmp.empty()) {
        if (len + j - tmp.back().second <= tmp.back().first) tmp.pop_back();
        else break;
      }
      if (tmp.empty() || (tmp.back().first+j-tmp.back().second > len)) tmp.emplace_back(len, j);
    }
    for (int j = m-1; j >= 0; j--) {
      if (j >= tmp.back().second) {
        LL tot = tmp.back().first + j - tmp.back().second;
        ret += tot;
        continue;
      }
      while (tmp.size() >= 2 && tmp[tmp.size()-2].second >= j) tmp.pop_back();
      if (tmp.size() == 1) {
        LL tot = tmp.back().first + tmp.back().second - j;
        ret += tot;
        continue;
      }
      int sz = tmp.size();
      LL tot = min(tmp.back().first + tmp.back().second - j, tmp[sz-2].first + j - tmp[sz-2].second);
      ret += tot;
    }
  }
  return ret;

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
  LL ret = 0;
  for (char c  = 'a'; c <= 'z'; c++) {
    ret += solve(c);
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
