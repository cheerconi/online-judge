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

int solve(int a, int b, int k, string s, const string& t) {
  for (char& c : s) {
    if (c == t[1] && a > 0) {
      c = t[0];
      a--;
      if (a == 0) break;
    }
  }
  for (int i = (int)s.size()-1; i >= 0; i--) {
    if (s[i] == t[0] && b > 0) {
      s[i] = t[1];
      b--;
      if (b == 0) break;
    }
  }
  assert(a == 0);
  assert(b == 0);
  vector<vector<int>> dp(2, vector<int>(s.size()));
  for (int i = (int)s.size()-1; i >= 0; i--) {
    if (s[i] == t[1]) dp[0][i] = 1;
    if (i+1 < s.size()) dp[0][i] += dp[0][i+1];
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == t[0]) dp[1][i] = 1;
    if (i-1 >= 0) dp[1][i] += dp[1][i-1];
  }
  int base = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == t[0]) {
      base += dp[0][i];
    }
  }
  vector<int> idx;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != t[0] && s[i] != t[1]) idx.push_back(i);
  }
  vector<int> ddp(idx.size());
  for (int i = (int)idx.size()-1; i >= 0; i--) {
    ddp[i] = dp[1][idx[i]];
    if (i+1 < idx.size()) ddp[i] += ddp[i+1];
  }
  int cur = 0, ret = 0;
  for (int i = 0; i <= min((int)idx.size(), k); i++) {
    if (i > 0) cur += dp[0][idx[i-1]];
    int j = k - i;
    j = min(j, (int)idx.size()-i);
    int tmp = cur + i * j + base;
    if (j > 0) tmp += ddp[ddp.size()-j];
    ret = max(ret, tmp);
  }
  return ret;





}

int solve(int k, const string& a, const string& b) {
  if (b[0] == b[1]) {
    int tot = 0;
    for (char c : a) {
      if (c == b[0]) tot++;
      else if (k > 0) {
        k--;
        tot++;
      }
    }
    return tot * (tot-1) / 2;
  }
  int ret = 0;
  int x = 0, y = 0;
  for (char c : a) {
    if (c == b[1]) x++;
    else if (c == b[0]) y++;
  }
  for (int i = 0; i <= x; i++) {
    if (i > k) break;
    for (int j = 0; j <= y; j++) {
      if (i+j > k) break;
      ret = max(ret, solve(i, j, k-i-j, a, b));
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
  int n, k; cin >> n >> k;
  string a, b; cin >> a >> b;
  cout << solve(k, a, b) << '\n';







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
