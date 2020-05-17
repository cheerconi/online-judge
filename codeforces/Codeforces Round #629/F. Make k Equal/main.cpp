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

LL solve(LL target, int k, LL sum1, LL sum2, int cnt1, int cnt2) {
  if (k <= 0) return 0;
  LL ret1 = (target - 1) * cnt1 - sum1;
  ret1 += min(k, cnt1);
  int k1 = k - min(k, cnt1);
  if (k1 > 0) {
    ret1 += sum2 - (target+1) * cnt2;
    ret1 += k1;
  }

  LL ret2 = sum2 - (target+1) * cnt2;
  ret2 += min(k, cnt2);
  int k2 = k - min(k, cnt2);
  if (k2 > 0) {
    ret2 += (target - 1) * cnt1 - sum1;
    ret2 += k2;
  }
  return min(ret1, ret2);

}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, k, val; cin >> n >> k;
  map<int, int> table;
  LL sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> val;
    table[val]++;
    sum += val;
  }
  int cur_cnt = 0;
  LL cur_sum = 0, ret = LLONG_MAX;
  for (const auto& item : table) {
    int tmp_cnt = item.second;
    LL tmp_sum = item.first * (LL)tmp_cnt;
    LL tmp = solve(item.first, k - tmp_cnt, cur_sum, sum - cur_sum - tmp_sum, cur_cnt, n - cur_cnt-tmp_cnt);
    ret = min(ret, tmp);
    cur_sum += tmp_sum;
    cur_cnt += tmp_cnt;
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
