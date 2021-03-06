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
const int mod = 998244353;
const int MAXN = 333;
int dp[MAXN][MAXN][MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  string s; cin >> s;
  int k; cin >> k;
  vector<int> nums;
  int cur = 0;
  for (char c : s) {
    if (c == '0') {
      nums.push_back(cur);
      cur = 0;
    } else {
      cur++;
    }
  }
  if (cur != 0) nums.push_back(cur);
  int n = nums.size();
  int m = s.size();
  dp[n][0][0] = 1;
  for (int i = n-1; i >= 0; i--) {
    for (int a = 0; a <= m; a++) {
      int tmp = 0;
      for (int b = a; b >= 0; b--) {
        tmp = (tmp + dp[i+1][a][b]) % mod;
        dp[i][a][b] = (tmp + dp[i][a][b]) % mod;
        if (dp[i+1][a][b] == 0) continue;
        for (int c = 1; c <= nums[i]; c++) {
          dp[i][a+c][b+c] = (dp[i][a+c][b+c] + dp[i+1][a][b]) % mod;
        }
      }
    }
  }
  LL ret = 0;
  for (int i = 0; i <= min(k, m); i++) {
    ret = (ret + dp[0][i][0]) % mod;
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
