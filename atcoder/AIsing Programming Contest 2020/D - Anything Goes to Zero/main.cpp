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
const int MAXN = 2e5 + 10;
int f[MAXN];
int dp[MAXN][2];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  string s; cin >> s;
  int m = 0;
  for (char c : s) {
    if (c == '1') m++;
  }
  for (int i = 1; i <= m; i++) {
    int tmp = i % __builtin_popcount(i);
    f[i] = f[tmp] + 1;
  }
  if (m-1 > 0) {
    int cur = 1;
    for (int i = n-1; i >= 0; i--) {
      dp[i][0] = cur % (m-1);
      cur = dp[i][0] * 2;
    }
  }
  int cur = 1;
  for (int i = n-1; i >= 0; i--) {
    dp[i][1] = cur % (m+1);
    cur = dp[i][1] * 2;
  }
  int a[2] = {0};
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      if (m-1 > 0) a[0] = (a[0] + dp[i][0]) % (m-1);
      a[1] = (a[1] + dp[i][1]) % (m+1);
    }
  }
  for (int i = 0; i < n; i++) {
    int ret;
    if (s[i] == '0') {
      ret =  f[(a[1] + dp[i][1]) % (m+1)] + 1;
    } else {
      if (m-1 == 0) ret = 0;
      else {
        ret = f[(a[0] - dp[i][0] + (m-1)) % (m-1)] + 1;
      }
    }
    cout << ret << '\n';
  }









/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
