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
const int MAXN = 62;
LL dp[MAXN][MAXN];
LL combine(int n, int k) {
  assert(n >= k);
  if (n-k < k) return combine(n, n-k);
  if (dp[n][k] != 0) return dp[n][k];
  if (k == 0) return dp[n][k] = 1;
  if (k == 1) return dp[n][k] = n;
  if (k == 2) return dp[n][k] = n * (n-1) / 2;
  return dp[n][k] = combine(n-1, k-1) + combine(n-1, k);
}

string solve(int a, int b, LL k) {
  if (k == 1) {
    string s(a, 'a');
    s += string(b, 'b');
    return s;
  }
  assert (a > 0 && b > 0);
  LL tmp = combine(a+b-1, a-1);
  if (tmp >= k) return "a" + solve(a-1, b, k);
  return "b" + solve(a, b-1, k-tmp);
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int a, b;
  LL k;
  cin >> a >> b >> k;
  cout << solve(a, b, k) << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
