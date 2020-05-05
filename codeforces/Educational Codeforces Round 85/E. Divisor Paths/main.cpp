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
const int MAXN = 1e5 + 10;
int cur[MAXN];
LL fact[MAXN], inv[MAXN];
vector<LL> nums;

LL power(LL base, LL p) {
  LL ret = 1;
  while (p) {
    if (p&1) ret = ret * base % mod;
    base = base * base % mod;
    p >>=1;
  }
  return ret;
}

LL solve(int tot) {
  LL ret = 1;
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < tot; i++) {
    if (cur[i] > 0) sum1 += cur[i];
    else sum2 -= cur[i];
    ret = ret * inv[abs(cur[i])] % mod;
  }
  ret = ret * fact[sum1] % mod * fact[sum2] % mod;
  return ret;
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  fact[0] = 1;
  for (int i = 1; i < 100000; i++) {
    fact[i] = fact[i-1] * i % mod;
  }
  inv[100000-1] = power(fact[100000-1], mod-2);
  for (int i = 100000-2; i >= 0; i--) {
    inv[i] = inv[i+1] * (i+1) % mod;
  }

  LL d, q, a, b; cin >> d >> q;
  for (LL i = 2; i*i <= d; i++) {
    if (d % i == 0) {
      nums.push_back(i);
      while (d % i == 0) {
        d /= i;
      }
    }
  }
  if (d != 1) nums.push_back(d);
  while (q--) {
    cin >> a >> b;
    if (a < b) swap(a, b);
    fill(cur, cur+nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
      if (a < nums[i]) break;
      while (a % nums[i] == 0) {
        cur[i]++;
        a /= nums[i];
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      if (b < nums[i]) break;
      while (b % nums[i] == 0) {
        cur[i]--;
        b /= nums[i];
      }
    }
    cout << solve(nums.size()) << '\n';



  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
