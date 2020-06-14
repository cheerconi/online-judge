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
const int MAXN = 4e5 + 10;
LL nums[MAXN], day[MAXN], sum[MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  LL n, x; cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> nums[i];
  }
  LL m = 2*n;
  for (int i = n+1; i <= m; i++) {
    nums[i] = nums[i-n];
  }
  for (int i = 1; i <= m; i++) {
    sum[i] = (1+nums[i]) * nums[i] / 2;
    sum[i] += sum[i-1];
    day[i] = nums[i] + day[i-1];
  }
  LL ret = 0;
  for (int i = 1, j = 1; i <= n; i++) {
    while (j <= m && day[j]-day[i-1] < x) j++;
    if (nums[i] >= x) {
      LL tmp = (nums[i] + nums[i]-x+1) * x / 2;
      ret = max(ret, tmp);
      continue;
    }
    LL tmp = sum[j-1] - sum[i-1];
    LL need = x - (day[j-1] - day[i-1]);
    assert(nums[j] >= need);
    tmp += (1 + need) * need / 2;
    LL gain = nums[j] - need;
    gain = min(nums[i]-1, gain);
    tmp -= (1+gain) * gain / 2;
    tmp += (need+1 + need+gain) * gain / 2;
    ret = max(tmp, ret);
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
