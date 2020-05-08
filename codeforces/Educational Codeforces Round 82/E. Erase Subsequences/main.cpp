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
const int MAXN = 412;
int dp[MAXN][MAXN];

bool solve(const string& s, const string& t, int k) {
  memset(dp, -1, sizeof(dp));
  dp[0][0] = k;
  int m = t.size();
  for (int i = 1; i <= s.size(); i++) {
    char c = s[i-1];
    for (int j = 0; j <= i; j++) {
      dp[i][j] = dp[i-1][j];
      if (j > 0 && j <= k && c == t[j-1] && dp[i-1][j-1] != -1) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
      if (dp[i-1][j] != -1 && dp[i-1][j] < m && c == t[dp[i-1][j]]) dp[i][j] = max(dp[i][j], dp[i-1][j]+1);
    }
  }
  return dp[s.size()][k] == m;
}

bool solve(const string& s, const string& t) {
  for (int i = 1; i <= t.size(); i++) {
    if (solve(s, t, i)) return true;
  }
  return false;
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int T; cin >> T;
  while(T--) {
    string s, t; cin >> s >> t;
    if (solve(s, t)) cout << "YES\n";
    else cout << "NO\n";

  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
