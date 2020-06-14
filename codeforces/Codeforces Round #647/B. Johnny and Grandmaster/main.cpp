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

LL power(LL base, int p) {
  LL ret = 1;
  while (p) {
    if (p&1) ret = ret * base % mod;
    if (ret > 1e7) return -1;
    p >>= 1;
    base = base * base;
    if (base > 1e7 && p != 0) return -1;
  }
  return ret;
}

LL power_mod(LL base, int p) {
  LL ret = 1;
  base = base % mod;
  while (p) {
    if (p&1) ret = ret * base % mod;
    p >>= 1;
    base = base * base % mod;
  }
  return ret;
}


int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while (t--) {
    LL n, p; cin >> n >> p;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }
    sort(nums.begin(), nums.end(), greater<int>());
    LL diff = 0;
    LL base = nums[0];
    int idx = n;
    for (int i = 0; i < n; i++) {
      if (diff != 0) {
        LL coeff = power(p, base - nums[i]);
        if (coeff == -1 || coeff * diff > 1e7) {
          idx = i;
          break;
        }
        diff = coeff * diff;
      }
      base = nums[i];
      diff = abs(diff - 1);
    }
    LL ret = power_mod(p, base) * diff % mod;
    for (int i = idx; i < n; i++) {
      ret = (ret - power_mod(p, nums[i]) + mod) % mod;
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
