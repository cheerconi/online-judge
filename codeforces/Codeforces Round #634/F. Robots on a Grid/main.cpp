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
vector<string> mat, color;
vector<vector<pii>> dp;
vector<vector<bool>> ret;
void go(int &i, int &j) {
  if (mat[i][j] == 'L') j--;
  else if (mat[i][j] == 'R') j++;
  else if (mat[i][j] == 'U') i--;
  else i++;
}

void solve(int i, int j) {
  vector<pii> pos;
  while (dp[i][j].first == -1) {
    pos.emplace_back(i, j);
    dp[i][j] = {-2, -2};
    go(i, j);
  }
  int tot = 0;
  int m = mat[0].size();
  pii tmp;
  if (dp[i][j].first == -2) {
    dp[i][j] = {i*m + j, tot++};
    while (dp[pos.back().first][pos.back().second].first == -2) {
      tmp = pos.back(); pos.pop_back();
      dp[tmp.first][tmp.second] = {i*m+j, tot++};
    }
    ret[i*m+j] = vector<bool>(tot);
    assert(!pos.empty());
    pos.pop_back();
  }
  int cur = dp[i][j].second;
  tot = ret[dp[i][j].first].size();
  assert(tot >= 2);
  while (!pos.empty()) {
    tmp = pos.back(); pos.pop_back();
    cur++;
    if (cur == tot) cur = 0;
    assert(dp[tmp.first][tmp.second].first == -2);
    dp[tmp.first][tmp.second] = {dp[i][j].first, cur};
  }
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
    color.resize(n);
    mat.resize(n);
    dp.resize(n);
    ret = vector<vector<bool>>(n*m);
    for (int i = 0; i < n; i++) {
      cin >> color[i];
      dp[i] = vector<pii>(m, {-1, -1});
    }
    for (int i = 0; i < n; i++) {
      cin >> mat[i];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (dp[i][j].first == -1) {
          solve(i, j);
        }
      }
    }
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (color[i][j] == '1') continue;
        if (!ret[dp[i][j].first][dp[i][j].second]) {
          ret[dp[i][j].first][dp[i][j].second] = true;
          b++;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!ret[dp[i][j].first][dp[i][j].second]) {
          ret[dp[i][j].first][dp[i][j].second] = true;
          a++;
        }
      }
    }
    cout << a + b << ' ' << b << '\n';
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
