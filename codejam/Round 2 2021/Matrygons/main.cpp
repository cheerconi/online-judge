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
const int MAXN = 1e6 + 10;
int dp[MAXN];

int solve(int i) {
  assert(i >= 2);
  if (dp[i] != 0) return dp[i];
  dp[i] = 1;
  for (LL j = 2; j*j <= i; j++) {
    if (i % j != 0) continue;
    int k = i / j;
    if (k-1 >= 2) {
      dp[i] = max(dp[i], 1 + solve(k-1));
    }
    if (k >= 2 && j-1 >= 2) {
      dp[i] = max(dp[i], 1 + solve(j-1));
    }
  }
  return dp[i];

}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int T; cin >> T;
  dp[2] = 1;
  for (int cs = 1; cs <= T; cs++) {
    int n; cin >> n;
    int ret = 1;
    for (LL i = 3; i*i <= n; i++) {
      if (n % i != 0) continue;
      int k = n / i;
      if (k-1 >= 2) {
        ret = max(ret, 1 + solve(k-1));
      }
      if (k >= 3 && i-1 >=2) {
        ret = max(ret, 1 + solve(i-1));
      }
    }
    cout << "Case #" << cs << ": " << ret << endl;


  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
