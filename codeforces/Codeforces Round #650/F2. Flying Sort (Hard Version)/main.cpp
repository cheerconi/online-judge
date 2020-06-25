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
int nums[MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while (t--) {
    map<int, int> table;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
      table[nums[i]]++;
    }
    table[-1] = 0;
    table[1e9+1] = 0;
    int ret = 0;
    map<int, int> count, dp[3], pre_count, suf_count;
    for (int i = 0; i < n; i++) {
      auto it = table.find(nums[i]);
      auto pre = it; pre--;
      auto suf = it; suf++;
      count[nums[i]]++;

      dp[0][nums[i]] = max(dp[0][nums[i]], count[pre->first]) + 1;
      ret = max(ret, dp[0][nums[i]]);
      ret = max(ret, dp[1][pre->first] + count[nums[i]] - suf_count[nums[i]]);

      if (count[nums[i]] == 1) {
        pre_count[pre->first] = count[pre->first];
      }
      if (count[nums[i]] == it->second) {
        suf_count[suf->first] = count[suf->first];
        dp[1][nums[i]] = max(dp[2][pre->first], pre_count[pre->first]) + it->second;
        if (count[suf->first] == 0) {
          dp[2][nums[i]] = dp[1][nums[i]];
        }
      }
    }
    cout << n - ret << '\n';


  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
