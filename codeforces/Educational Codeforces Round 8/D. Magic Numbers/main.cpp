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
const int MAXN = 2000 + 10;
LL dp[MAXN][MAXN];
int m, d, coeff[MAXN];
string a, b;
LL ret;

void solve(int i, bool lower, bool upper, bool flag, LL cur, int rem) {
  if (i == a.size()) {
    if (rem == 0) ret = (ret + cur) % mod;
    return;
  }
  if (!lower && !upper) {
    ret = (ret + dp[i][(m-rem)%m]) % mod;
    return;
  }
  int x = 0, y = 9;
  if (lower) x = a[i] - '0';
  if (upper) y = b[i] - '0';
  for (int j = x; j <= y; j++) {
    if (flag && j != d) continue;
    if (!flag && j == d) continue;
    if (i == 0 && j == 0) continue;
    solve(i+1, lower&&(j == a[i]-'0'), upper&&(j==b[i]-'0'), !flag, cur, (rem + j*coeff[i])%m);
  }
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  cin >> m >> d;
  cin >> a >> b;
  int n = a.size();
  dp[n][0] = 1;
  bool flag = (n % 2 == 0);
  coeff[n-1] = 1;
  for (int i = n-1; i >= 0; i--) {
    if (i != n-1) coeff[i] = coeff[i+1] * 10 % m;
    int x = 0, y = 9;
    if (flag) {
      x = d;
      y = d;
    }
    for (int j = x; j <= y; j++) {
      if (!flag && j == d) continue;
      for (int k = 0; k < m; k++) {
        int tmp = (j * coeff[i] + k) % m;
        dp[i][tmp] = (dp[i][tmp] + dp[i+1][k]) % mod;
      }
    }
    flag = !flag;
  }
  solve(0, true, true, false, 1, 0);
  cout << ret << endl;







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
