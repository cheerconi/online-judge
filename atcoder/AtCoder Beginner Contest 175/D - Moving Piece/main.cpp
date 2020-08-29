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
const int MAXN = 5000 + 10;
int p[MAXN], c[MAXN];
bool used[MAXN];
vector<LL> nums;
LL sum;

LL dfs(int i, LL k) {
  used[i] = true;
  nums.push_back(c[i]);
  sum += c[i];
  if (used[p[i]]) {
    LL n = nums.size();
    LL ret = LLONG_MIN;
    if (k >= n) ret = max(ret, k/n*sum);
    for (int len = 1; len < n; len++) {
      if (len > k) break;
      LL tmp = 0;
      for (int i = 0; i < len; i++) {
        tmp += nums[i];
      }
      for (int i = 0; i < n; i++) {
        tmp -= nums[i];
        tmp += nums[(i+len)%n];
        ret = max(ret, tmp);
        ret = max(ret, tmp + sum*((k-len)/n));
      }
    }
    return ret;
  }
  return dfs(p[i], k);
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  LL ret = LLONG_MIN;
  for (int i = 1; i <= n; i++) {
    if (used[i]) continue;
    nums.clear();
    sum = 0;
    ret = max(dfs(i, k), ret);
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
