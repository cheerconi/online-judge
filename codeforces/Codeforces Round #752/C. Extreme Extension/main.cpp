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
typedef pair<LL, int> pli;
const int MAXN = 1e5 + 10;
const int MAXM = 640;
const int mod = 998244353;
int nums[MAXN];
LL dp[2][MAXM][3];
int len[2];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }
    LL ret = 0;
    int idx = 0;
    len[0] = 0;
    len[1] = 0;
    for (int i = n-1; i >= 0; i--) {
      for (int j = 0; j < len[idx]; j++) {
        LL value = dp[idx][j][0];
        LL cnt = dp[idx][j][1];
        LL cost = dp[idx][j][2];
        ret = (ret + cost) % mod;
        int pieces = nums[i] / value;
        if (nums[i] % value != 0) pieces++;
        LL new_value = nums[i] / pieces;
        LL new_cost = (cost + cnt * (pieces-1)) % mod;
        if (len[1^idx] == 0 || dp[1^idx][len[1^idx]-1][0] != new_value) {
          dp[1^idx][len[1^idx]][0] = new_value;
          dp[1^idx][len[1^idx]][1] = cnt;
          dp[1^idx][len[1^idx]][2] = new_cost;
          len[1^idx]++;
        } else {
          dp[1^idx][len[1^idx]-1][1] += cnt;
          dp[1^idx][len[1^idx]-1][2] = (dp[1^idx][len[1^idx]-1][2] + new_cost) % mod;
        }
      }
      if (len[1^idx] == 0 || dp[1^idx][len[1^idx]-1][0] != nums[i]) {
        dp[1^idx][len[1^idx]][0] = nums[i];
        dp[1^idx][len[1^idx]][1] = 1;
        dp[1^idx][len[1^idx]][2] = 0;
        len[1^idx]++;
      } else {
        dp[1^idx][len[1^idx]-1][1]++;
      }
      idx = 1^idx;
      assert(len[1^idx] <= MAXM);
      len[1^idx] = 0;
    }
    for (int i = 0; i < len[idx]; i++) {
      ret = (ret + dp[idx][i][2]) % mod;
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
