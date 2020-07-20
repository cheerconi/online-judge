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
const int mod = 998244353;
const int MAXN = 3e5 + 10;
int nums[MAXN], sum[MAXN], ret[MAXN];

LL power(LL base, int p) {
  LL ret = 1;
  base = base % mod;
  while (p) {
    if (p&1) ret = ret * base % mod;
    base = base * base % mod;
    p >>= 1;
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
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  sort(nums, nums+n, greater<int>());
  sum[0] = nums[0];
  for (int i = 1; i < n; i++) {
    sum[i] = (sum[i-1] + nums[i]) % mod;
  }
  for (int i = 0; i < n; i++) {
    LL coeff = 1;
    for (int j = i+1; j < n; j += i+1) {
      LL tmp = (sum[min(j+i, n-1)] - sum[j-1] + mod) % mod * coeff % mod;
      ret[i] = (ret[i] + tmp) % mod;
      coeff++;
    }
  }
  LL inv = power(n, mod-2);
  for (int i = 0; i < n; i++) {
    cout << ret[i] * inv % mod;
    if (i+1 == n) cout << '\n';
    else cout << ' ';
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
