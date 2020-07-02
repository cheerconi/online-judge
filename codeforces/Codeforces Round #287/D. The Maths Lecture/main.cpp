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
const int MAXN = 1234;
int mod;
int dp[MAXN][MAXN][2];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, k;
  cin >> n >> k >> mod;
  dp[0][0][0] = 1;
  LL base = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < k; j++) {
      for (int u = 0; u < 10; u++) {
        if (i == n && u == 0) continue;
        int tmp = (base * u % k + j) % k;
        dp[i][tmp][1] = (dp[i][tmp][1] + dp[i-1][j][1]) % mod;
        if (tmp == 0 && u != 0) {
          dp[i][tmp][1] = (dp[i][tmp][1] + dp[i-1][j][0]) % mod;
        } else {
          dp[i][tmp][0] = (dp[i][tmp][0] + dp[i-1][j][0]) % mod;
        }
      }
    }
    base = base * 10 % k;
  }
  LL ret = 0;
  for (int i = 0; i < k; i++) {
    ret = (ret + dp[n][i][1]) % mod;
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
